#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

const int MODULO{ 26 };

using namespace std;

string ceasar(string plainText, int shift);
vector<int> str2lst(string text);
string lst2str(vector<int> lst);
string decrypt_ceaser(string cipher, int shift);
void brute_force_ceaser(string cipher);
string subtitution_cipher(string plainText);
string decrypt_sub_cipher(string cipher);
string affine_encryption(string message,int key1,int key2);
tuple<int, int, int> extended_gcd(int a, int b);
void inverse_mod(int a, int b, int *inv);
string decrypt_affine(string cipher, int key1, int key2);
void display_menu();
string get_input(int *key);
string get_input();

// Function Prototype - default values in arguments in the end! ex. int modInverse(int a, int m=10);
// Info: Pass a reference in a function with & ex. int modInverse(int &a);
// Info: Pass a reference in a function with & but read only(const) ex. int modInverse(const int &a);
// Info: A static variable keeps its values between function calls. Is like a global var with local visibility!

int main()
{
    string ceaserCipher{};
	string cipherSub {};
	string AffineCipher {};
    string plainText{};
    int key{};
	//for affine encryption key1 & key2
	int key1 {11};
	int key2 {4};
	
	int option {0};
	display_menu();
	
	while(true){
		cout << "Please enter the number of your option: ";
		cin >> option;
		switch (option) {
		case 1: {
			plainText = get_input(&key);
			ceaserCipher = ceasar(plainText, key);
			cout << "This is the encrypted text: " << ceaserCipher << endl;
			break;
		}
		case 2: {
			plainText = decrypt_ceaser(ceaserCipher, key);
			cout << "This is the decryption of the cipherText: " << plainText << endl;
			break;
		}
		case 3: {
			cout <<"Brute force cipher text: " << endl;
			brute_force_ceaser(ceaserCipher);
			break;
		}
		case 4: {
			plainText = get_input(&key);
			cipherSub = subtitution_cipher(plainText);
			cout << "subtition cipher: " << cipherSub << endl;
			break;
		}
		case 5: {
			string decrypt_sub = decrypt_sub_cipher(cipherSub);
			cout << "subtition decryption: "  << decrypt_sub << endl;
			break;
		}
		case 6: {
			plainText = get_input();
			AffineCipher = affine_encryption(plainText,key1,key2);
			cout << "Affine cipher: " << AffineCipher <<endl;
			break;
		}
		case 7: {
			plainText = decrypt_affine(AffineCipher,key1,key2);
			cout << "plain: " << plainText <<endl;
			break;
		}
		case 8: {
			cout << "Thank you bye!" << endl;
			break;
		}
		}
		if(option==8)
			break;
	}
		

    return 0;
}

string ceasar(string plainText, int shift)
{

    vector<int> plainTextList{};
    plainTextList = str2lst(plainText);
    vector<int> cipherTextList{};
    for(auto x : plainTextList) {
		x = (x + shift) % MODULO;
		cipherTextList.push_back(x);
    }

    string cipher = lst2str(cipherTextList);

    return cipher;
}

string decrypt_ceaser(string cipher, int shift)
{

    vector<int> cipherTextList{ str2lst(cipher) };
    vector<int> plainTextList{};
    // mod (%) OPERATION IN C++ IS JUST THE REMINDER NOT THE MODULO IN A DACTYLUS
    for(auto c : cipherTextList) {
		c = (((c - shift) % MODULO) + MODULO) % MODULO;
		plainTextList.push_back(c);
    }

    string plainText{ lst2str(plainTextList) };

    return plainText;
}

vector<int> str2lst(string text)
{

    vector<int> plainTextList{};
    for(auto t : text) {
		plainTextList.push_back((int)t - 65);
    }

    /*for (auto i : plainTextList)
            cout << i << " ";
     */
    return plainTextList;
}

string lst2str(vector<int> lst)
{

    string str{};
    for(auto l : lst) {
		str += char(l + 65);
    }

    return str;
}

void brute_force_ceaser(string cipher)
{
    for(int i{ 0 }; i < MODULO; i++) {
		cout << i << ". " << decrypt_ceaser(cipher, i) << endl;
    }
}

string subtitution_cipher(string plainText)
{

    string permutation{ "ZAYBXCWDVEUFTGSHRIQJPKOLNM" };
    vector<int> plainTextList = str2lst(plainText);
    vector<int> cipherTextList{};
    for(size_t i{ 0 }; i < plainTextList.size(); i++) {
		cipherTextList.push_back(permutation.at(plainTextList.at(i)) - 65);
    }

    return lst2str(cipherTextList);
}

// It is more difficult to decrypt substitution cipher if you do not know the permutation
// then you work with letter frequencies. But here we suppose that we know it.
string decrypt_sub_cipher(string cipher)
{

    // we know it
	string permutation{ "ZAYBXCWDVEUFTGSHRIQJPKOLNM" };
	string plainText;
    vector<int> inversePermutation(permutation.size(), 0);
    for(size_t i{ 0 }; i < permutation.size(); i++) {
		//cout << permutation.at(i) - 65 << ", " << i << endl;
		// create invertion of permutation by pointing the potision of each character in order (ex. at index=0,value=1, because A is on the position 1 at permutation)
		inversePermutation.at(permutation.at(i) - 65) = i;
    }

    for(auto i : cipher)
		plainText += (char)(inversePermutation.at(i-65) + 65);

    return plainText;
}

string affine_encryption(string message,int key1,int key2)
{
	
	vector<int> plainTextList {};
	plainTextList = str2lst(message);
	vector<int> cipherTextList {};
	for(auto p : plainTextList)
		cipherTextList.push_back((key1*p+key2) % MODULO);		
	
	string cipherText = lst2str(cipherTextList);
	
	return cipherText;
	
	
}

string decrypt_affine(string cipher, int key1, int key2)
{
	
	//a very large number
	int inverseKey1 {999999999};
	string plainText {};
	inverse_mod(key1,MODULO,&inverseKey1);
	//cout << "inv: " << inverseKey1 << endl;
	if(inverseKey1!=999999999){		
		vector<int> cipherTextList {};
		vector<int> plainTextList {};
		cipherTextList = str2lst(cipher);
		for(auto c : cipherTextList){
			plainTextList.push_back((((inverseKey1*(c-key2))%MODULO) + MODULO)%MODULO);
		}
		plainText = lst2str(plainTextList);
	}
	
	return plainText;

}

// Function for Extended Euclidean algorithm
// It returns multiple values using tuple in C++
tuple<int, int, int> extended_gcd(int a, int b)
{
	if (a == 0)
		return make_tuple(b, 0, 1);

	int gcd, x, y;

	// unpack tuple  returned by function into variables
	tie(gcd, x, y) = extended_gcd(b % a, a);

	return make_tuple(gcd, (y - (b/a) * x), x);
}

void inverse_mod(int a, int b, int *inv)
{
	
	tuple<int, int, int> t = extended_gcd(a, b);
	int gcd = get<0>(t);
	int x = get<1>(t);
	
	if(gcd==1){
		//DACTYLUS MODULE
		*inv =  (((x%MODULO)+MODULO)%MODULO);
	}
	else
		cout << "Error, no inverse in modulo" << MODULO <<endl;
}

void display_menu(){
	
	cout << "Encryption project. Here you can encrypt plaintext in different ways and decrypt them. Only alhpabetic characters are accepted, because we work on MODULO 26" << endl;
    cout << "1. Encrypt with ceaser encryption." << endl;
    cout << "2. Decrypt ceaser encryption." << endl;
    cout << "3. Brute force attack on ceaser encryption." << endl;
    cout << "4. Encrypt with subtitution encryption." << endl;
    cout << "5. Encrypt subtitution knowing the permutation, no brute force or letter frequency analyzer." << endl;
    cout << "6. Encrypt with affine encryption." << endl;
    cout << "7. Decrypt affine encryption." << endl;
    cout << "8. Quit." << endl;
}

string get_input(int *key){
	string plainText {};
	cout << "Enter your text: " << endl;
	cin.ignore();
	getline(cin, plainText);
	// All capital
	transform(plainText.begin(), plainText.end(), plainText.begin(), ::toupper);
	// delete spaces
	plainText.erase(remove(plainText.begin(), plainText.end(), ' '), plainText.end());
	if(*key != -1){
		cout << "Enter a key (0<integer<=25) for encrytpion:" << endl;
		cin >> *key;
	}
	
	return plainText;
}

string get_input(){
	string plainText {};
	cout << "Enter your text: " << endl;
	cin.ignore();
	getline(cin, plainText);
	// All capital
	transform(plainText.begin(), plainText.end(), plainText.begin(), ::toupper);
	// delete spaces
	plainText.erase(remove(plainText.begin(), plainText.end(), ' '), plainText.end());
	
	return plainText;
}

