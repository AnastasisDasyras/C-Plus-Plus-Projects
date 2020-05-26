#include <iostream>
#include <climits>

using namespace std;

int main() {

    cout << "Size of variable in general:\n\n";
    cout << "Size of char: " << sizeof(char) << " byte" << endl;
    cout << "Size of short: " << sizeof(short) << " bytes" << endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of long: " << sizeof(long) << " bytes" << endl;
    cout << "Size of long long: " << sizeof(long long) << " bytes" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of long double: " << sizeof(long double) << " bytes\n\n" << endl;
    
    cout << "Min/Max variables' values in my PC:\n\n";
    cout << "CHAR_MIN : " << CHAR_MIN << endl; 
    cout << "CHAR_MAX : " << CHAR_MAX << endl; 
    cout << "SHRT_MIN : " << SHRT_MIN << endl; 
    cout << "SHRT_MAX : " << SHRT_MAX << endl; 
    cout << "USHRT_MAX : " << USHRT_MAX << endl; 
    cout << "INT_MIN : " << INT_MIN << endl; 
    cout << "INT_MAX : " << INT_MAX << endl; 
    cout << "UINT_MAX : " << UINT_MAX << endl; 
    cout << "LONG_MIN : " << LONG_MIN << endl; 
    cout << "LONG_MAX : " << LONG_MAX << endl; 
    cout << "ULONG_MAX : " << ULONG_MAX << endl; 
    cout << "LLONG_MIN : " << LLONG_MIN << endl; 
    cout << "LLONG_MAX : " << LLONG_MAX << endl; 
    cout << "ULLONG_MAX : " << ULLONG_MAX << endl; 
    
    return 0;
}
