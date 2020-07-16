/*
 * A simple programme for practising pointers
 */

#include <iostream>

using namespace std;

void print_array(const int *const array, size_t size);
int *multiply_all(const int *const ar1, const int *const ar2, size_t s1, size_t s2);

int main()
{

    int array1[5] = { 1, 2, 3, 4, 5 };
    int array2[3] = { 10, 20, 30 }; 

    print_array(array1, 5);
	print_array(array2, 3);
	int *newArrPtr = multiply_all(array1,array2,5,3);
	print_array(newArrPtr,15);

	delete [] newArrPtr;

    return 0;
}

void print_array(const int *const array, size_t size)
{
	
    cout << "[";
    for(size_t i {0}; i < size; i++) {
		if(i!=size-1){
			cout << array[i] << ", ";
		}
		else{
			cout << array[i] << "]" << endl;;
		}
		
    }

}


int *multiply_all(const int *const ar1, const int *const ar2, size_t s1, size_t s2){
	
	int *newArray {nullptr};
	newArray = new int[s1*s2];
	
	int position {0};
	for(size_t i{0};i<s2;i++){
		for(size_t j{0};j<s1;j++){
			newArray[position] = ar1[j] * ar2[i];
			position++;
		}
	}
	
	return newArray;
}