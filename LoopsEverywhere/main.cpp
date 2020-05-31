#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{

    vector <char> options {'P','p','A','a','M','m','S','s','L','l','D','d','Q','q'};
    char option;
    vector <int> vecOfNums {};
    bool stop = false;

    while(!stop) {
        cout << endl;
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display Mean of the numbers" << endl;
        cout << "S - Display the Smallest number" << endl;
        cout << "L - Display the Largest number" << endl;
        cout << "D - Delete numbers from list" << endl;
        cout << "Q - Quit" << endl;
        cout << "Select one of the above: ";
        cin >> option;

        //Check user's input
        bool found {false};
        while(!found) {
            found = (std::find(options.begin(), options.end(), option) != options.end());
            if (found) {
                break;
            } else {
                //wrong input
                cout << "Sorry wrong option please try again: ";
                cin >> option;
            }
        }

        //right input
        switch (option) {
        case 'P':
        case 'p': {
            if(vecOfNums.size() == 0) {
                cout << "The list is empty - []" << endl;
            } else {
                for(unsigned i {0}; i<vecOfNums.size(); ++i) {
                    cout << vecOfNums.at(i) << " ";
                }
                cout << endl;
            }
            break;
        }
        case 'A':
        case 'a': {
            int num;
            cout << "Give the number you want to add: ";
            cin >> num;
            //Check dublicates
            bool exist {false};
            exist = (std::find(vecOfNums.begin(), vecOfNums.end(), num) != vecOfNums.end());
            if(exist) {
                cout << "Is not allowed to have dublicates in the list." << endl;
            } else {
                vecOfNums.push_back(num);
                cout << num << " added." << endl;
                exist = false;
            }

            break;
        }
        case 'M':
        case 'm': {
            if (vecOfNums.size() > 0) {
                double total {0};
                for(unsigned i {0}; i < vecOfNums.size(); ++i) {
                    total += vecOfNums.at(i);
                }
                double mean = total / vecOfNums.size();
                cout << "Mean: " << mean << endl;
            } else {
                cout << "Unable to calculate the mean - no data." << endl;
            }
            break;
        }
        case 'S':
        case 's': {
            if (vecOfNums.size() > 0) {
                int min {vecOfNums.at(0)};
                for(unsigned i {1}; i<vecOfNums.size(); ++i) {
                    if(min > vecOfNums.at(i)) {
                        min = vecOfNums.at(i);
                    }
                }
                cout << "The smallest number is: " << min << endl;
            } else {
                cout << "Unable to determine the smallest number - list is empty." <<  endl;
            }
            break;
        }
        case 'L':
        case 'l': {
            if (vecOfNums.size() > 0) {
                int max {vecOfNums.at(0)};
                for(unsigned i {1}; i<vecOfNums.size(); ++i) {
                    if(max < vecOfNums.at(i)) {
                        max = vecOfNums.at(i);
                    }
                }
                cout << "The largest number is: " << max << endl;
            } else {
                cout << "Unable to determine the largest number - list is empty." <<  endl;
            }
            break;
        }
        case 'D':
        case 'd': {
            cout << "List is empty now." << endl;
            vecOfNums.clear();
            break;
        }
        case 'Q':
        case 'q': {
            cout << "Thank you, Goodbye!" << endl;
            stop = true;
            break;
        }

        }
    }

    return 0;
}
