/*
 * Bob has a cleaning service
 * He charges 50$ per room
 * The tax is 3.5%
 * Calculate the estimated cost per customer
 */
#include <iostream>

using namespace std;

const float taxRate
{
    0.40
};
const double pricePerSmallRoom
{
    27
};
const double pricePerLargeRoom
{
    48
};

int main()
{

    int numOfSmallRooms {0};
    int numOfLargeRooms {0};
    cout << "Welcome to Bob's cleaning service. We clean every room!" <<
             "Small rooms are at most 30 square meters." << endl;

    cout << "Enter the number of small rooms you want to clean: ";
    cin >> numOfSmallRooms;
    cout << "Enter the number of large rooms you want to clean: ";
    cin >> numOfLargeRooms;
    cout << "Number of small rooms: " << numOfSmallRooms << endl;
    cout << "Number of large rooms: " << numOfLargeRooms << endl;
    cout << "Price per small room: " << pricePerSmallRoom << endl;
    cout << "Price per large room: " << pricePerLargeRoom << endl;
    double estimatedPriceTaxFree {(numOfSmallRooms * pricePerSmallRoom) + (numOfLargeRooms * pricePerLargeRoom)};
    cout << "Cost: " << estimatedPriceTaxFree << " dollars" << endl;
    double tax = estimatedPriceTaxFree * taxRate;
    cout << "Tax: " << tax << " dollars" << endl;
    cout << "================================" <<endl;
    cout << "The estimated total cost after taxes is: " << estimatedPriceTaxFree + tax << " dollars"<< endl;

    return 0;
}
