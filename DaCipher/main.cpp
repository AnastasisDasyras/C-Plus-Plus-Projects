#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const int MODULO{ 26 };

using namespace std;

string ceasar(string plainText,int shift);
vector<int> str2lst(string text);
string lst2str(vector<int> lst);
string decrypt_ceaser(string cipher,int shift);

// Function Prototype - default values in arguments in the end! ex. int modInverse(int a, int m=10);
// Info: Pass a reference in a function with & ex. int modInverse(int &a);
// Info: Pass a reference in a function with & but read only(const) ex. int modInverse(const int &a);
// Info: A static variable keeps its values between function calls. Is like a global var with local visibility!

int main()
{
	string cipher {};
	string plainText {};
	int key {};

	cout << "Enter text for encryption: ";
	getline(cin,plainText);
	//All capital
	std::transform(plainText.begin(), plainText.end(),plainText.begin(), ::toupper);
	//delete spaces
    plainText.erase(remove(plainText.begin(), plainText.end(), ' '), plainText.end()); 
	cout << "Enter a key (0<integer<=25) for encrytpion:"<<endl;
	cin >> key;
	cout << "This is the text for encryption: " << plainText << endl;
	cipher = ceasar(plainText,key);
	cout <<"This is the encrypted text: "<< cipher << endl;
	plainText = decrypt_ceaser(cipher,key);
	cout << "This is the decryption of the cipherText: "<< plainText <<endl;
	
	cout << "problem: " << ((-12)%26+26)%26;
	
    return 0;
}

string ceasar(string plainText, int shift)
{

    vector<int> plainTextList{};
    plainTextList = str2lst(plainText);
	vector<int> cipherTextList {};
	for (auto x : plainTextList){
		x = (x + shift) % MODULO;
		cipherTextList.push_back(x);
	}
	
	string cipher = lst2str(cipherTextList);
	
	return cipher;
	
}

string decrypt_ceaser(string cipher,int shift){
	
	vector<int> cipherTextList {str2lst(cipher)};
	vector<int> plainTextList {};
	//mod (%) OPERATION IN C++ IS JUST THE REMINDER NOT THE MODULO IN A DACTYLUS
	for (auto c : cipherTextList){
		c = (((c-shift) % MODULO) + MODULO) % MODULO;
		plainTextList.push_back(c);
	}
	
	string plainText {lst2str(plainTextList)};
	
	return plainText;
	
}

vector<int> str2lst(string text)
{

    vector<int> plainTextList{};
    for(auto t : text) {
		plainTextList.push_back((int)t-65);
    }

	for (auto i : plainTextList)
		cout << i << " ";
    return plainTextList;
}

string lst2str(vector<int> lst)
{

    string str {};
    for(auto l : lst) {
		str += char(l+65);
    }

    return str;
}