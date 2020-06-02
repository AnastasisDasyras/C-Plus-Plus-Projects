#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>


const int MODULO
{
    26
};

int modInverse(int a, int m);

using namespace std;

int main()
{

    int key_a {7};
    int key_b {2};
    string cipherString;
    string plainString;
    string plainText;
    
    cout << "Enter plain text for encryption:" << endl;
    getline(cin,plainText);
    //Break string into chars 
    char charArray[plainText.length() + 1];
    strcpy(charArray, plainText.c_str());
    
    
    
    //Encryption
    for (auto let : plainText) {
        char cipher = (key_a*(let-'a')+key_b) % MODULO;
        cipherString += (cipher+'a');
    }
    cout <<"Cipher: " << cipherString <<endl;
    //Decryption
    int modInv = modInverse(key_a,MODULO);
    cout << "ModInv: " << modInv << endl;
    for (auto let : cipherString) {
        char plainChar = (((let)-key_b)*modInv +1) % MODULO;
        plainString += (plainChar+'a');
    }
    cout << "Plain: " << plainString <<endl;


    return 0;
}

int modInverse(int a, int m)
{
    a = a%m;
    for (int x=1; x<m; x++)
        if ((a*x) % m == 1) {
            return x;
        }
    return 0;
}