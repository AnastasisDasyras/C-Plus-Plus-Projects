/*
 * Arrays & Vectors
 * Arrays are static structures, they was used a lot in the past
 * Vectors are dynamic structures, they are used more today
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    //array of 10 integers is initialized with zeros
    int array_of_int[10] {0};
    //It is not necessary to set who many items if you initialize the array.
    char array_of_vowels[] {'a','e','i','o','u'};
    //set values only in the three first items
    double array_of_prices [10] {20.3,44.5,29.34};

    cout << "First item of int array: " << array_of_int[0] << endl;
    cout << "Second item of char array: " << array_of_vowels[1] << endl;
    cout << "Third item of prices arrays: " << array_of_prices[2] << endl;

    //Multidimensional Array
    const int movies {
        5
    };
    const int reviewers {
        5
    };
    //Initialize with zeros
    double movie_rates[movies][reviewers] {0};
    cout << movie_rates[1][2] << endl;
    //Initialize with specific values
    double movie_rates_with_values[movies][reviewers] {
        {1.23,4.3,3.33,5,2.7},
        {2.23,3.5,4.63,4.55,1.72},
        {1.83,2.34,3.63,5,4.32},
        {3.53,4,2.85,4,4.1},
        {3.78,2.22,3,5,3.2}
    };
    cout << movie_rates_with_values[1][2] << endl;

    //Vectors

    //Empty vector
    vector <double> vec_temperatures;
    //Initialize 10 items to zero
    vector <double> vec_temperatures1 (10);
    //You can specify an index in vector with .at(index)
    cout << "First temperature: " << vec_temperatures1.at(0) << endl;
    //Initialize char items in vector
    vector <char> vec_vowels {'a','e','i','o','u'};
    cout << "First Vowel: " << vec_vowels.at(0) << endl;
    //Initialize 100 items with value 20
    vector <int> vec_ages (100,20);
    cout << "Last Age: " << vec_ages.at(99) << endl;

    //2D vector
    vector <vector <int>> vec_movies {
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,4}
    };

    cout << "First row first col: " << vec_movies.at(0).at(0) << endl;
    
    //Add item in the end of the vector
    cout << "Size of array ages: " << vec_ages.size() << endl;
    vec_ages.push_back(23);
    cout << "Size of array ages after pushing back: " << vec_ages.size() << endl;
    cout << "Last Age: " << vec_ages.at(vec_ages.size()-1) << endl;
    
    

    return 0;
}
