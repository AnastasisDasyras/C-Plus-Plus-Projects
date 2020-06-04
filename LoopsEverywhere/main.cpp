#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char print_menu(const vector <char> &options);
void print_list(const vector<int> &vecOfNums);
void add_number(const int &num, vector<int> &vecOfNums);
void print_mean_list(const vector<int> &vecOfNums);
void print_smallest_num(const vector<int> &vecOfNums);
void print_largest_num(const vector<int> &vecOfNums);
void empty_list(vector<int> &vecOfNums);

int main()
{

    vector <char> options {'P','A','M','S','L','D','Q'};
    char option;
    vector <int> vecOfNums {};
    bool stop = false;

    while(!stop) {

        //print menu
        option = print_menu(options);

        switch (option) {
        case 'P': {
            print_list(vecOfNums);
            break;
        }
        case 'A': {
            int num;
            do {
                cout << "Give an integer number to add: ";
                cin >> num;
            } while(isdigit(num));
            add_number(num, vecOfNums);
            break;
        }
        case 'M': {
            print_mean_list(vecOfNums);
            break;
        }
        case 'S': {
            print_smallest_num(vecOfNums);
            break;
        }
        case 'L': {
            print_largest_num(vecOfNums);
            break;
        }
        case 'D': {
            empty_list(vecOfNums);
            break;
        }
        case 'Q': {
            cout << "Thank you, Goodbye!" << endl;
            stop = true;
            break;
        }

        }
    }

    return 0;
}


char print_menu (const vector <char> &options)
{
    char option;
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

    //Check user's input - convert Upercase before check
    option = toupper(option);
    bool found {false};
    while(!found) {
        found = (std::find(options.begin(), options.end(), option) != options.end());
        if (found) {
            break;
        } else {
            //wrong input
            cout << "Sorry wrong option please try again: ";
            cin >> option;
            option = isupper(option);

        }
    }
    
    return option;

}

void print_list(const vector<int> &vecOfNums)
{

    if(vecOfNums.size() == 0) {
        cout << "The list is empty - []" << endl;
    } else {
        cout << "[";
        for(unsigned i {0}; i<vecOfNums.size(); ++i) {
            if(i!=vecOfNums.size()-1)
                cout << vecOfNums.at(i) << ", ";
            else
                cout << vecOfNums.at(i) << "]" << endl;
        }

    }

}

void add_number(const int &num, vector<int> &vecOfNums)
{

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

}

void print_mean_list(const vector<int> &vecOfNums)
{

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

}

void print_smallest_num(const vector<int> &vecOfNums)
{

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

}

void print_largest_num(const vector<int> &vecOfNums)
{
    
    if (vecOfNums.size() > 0)
    {
        int max {vecOfNums.at(0)};
        for(unsigned i {1}; i<vecOfNums.size(); ++i) {
            if(max < vecOfNums.at(i)) {
                max = vecOfNums.at(i);
            }
        }
        cout << "The largest number is: " << max << endl;
    } else
    {
        cout << "Unable to determine the largest number - list is empty." <<  endl;
    }
    
}

void empty_list(vector<int> &vecOfNums)
{
    cout << "List is empty now." << endl;
    vecOfNums.clear();
}




