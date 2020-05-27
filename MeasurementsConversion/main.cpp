/*
 * Programme that converts us measurements into eu and uk standards
 */

#include <iostream>

using namespace std;

int main()
{
    const double feetToCm = 30.48;
    const int feetToInch = 12;
    const double galToLt = 3.78541178;
    const double lbToKg = 0.45359237;
    const int lbToOz = 16;
    const double mlToKm = 1.609344;
    const double mlToyd = 1.609344;

    int option {0};
    cout << "1. Convert Feets to Centimeters and Inches" << endl;
    cout << "2. Convert Fahrenheit to Celcius" << endl;
    cout << "3. Convert Miles to Kilometers and Yards" << endl;
    cout << "4. Convert Gallons to Liters" << endl;
    cout << "5. Convert Pounds(lb) to Kilos(kg) and Ounce (oz)" << endl;
    cout << "Please enter the number of your option: ";
    cin >> option;

    switch (option) {
    case 1: {
        cout << "Please enter how many feets: ";
        double feets {0};
        cin >> feets;
        cout << "It is equal to " << feets * feetToCm << " centimeters." << endl;
        //static_cast <double> convert the integer to double to get a double as a result
        //if one of two number is double then the result will be double, here is useless but just to remember it
        cout << "It is equal to " << static_cast<double>(feetToInch)*feets  << " inches." << endl;
        break;
    }
    case 2: {
        cout << "Please enter Fahrenheit value: ";
        double fahrenheit {0};
        cin >> fahrenheit;
        cout << "It is equal to " << (fahrenheit - 32) * 5 / 9  << " Celcius." << endl;
        break;
    }
    case 3: {
        cout << "Please enter how many Miles: ";
        double miles {0};
        cin >> miles;
        cout << "It is equal to " << miles * mlToKm << " kilometers." << endl;
        cout << "It is equal to " << miles * mlToyd << " yards." << endl;
        break;
    }
    case 4: {
        cout << "Please enter how many Gallons: ";
        double gallons {0};
        cin >> gallons;
        cout << "It is equal to " << gallons * galToLt << " liters." << endl;
        break;
    }
    case 5: {
        cout << "Please enter how many Pounds: ";
        double pounds {0};
        cin >> pounds;
        cout << "It is equal to " << pounds * lbToKg << " kilos." << endl;
        cout << "It is equal to " << pounds * static_cast<double>(lbToOz) << " oz." << endl;
        break;
    }
    }

    return 0;
}
