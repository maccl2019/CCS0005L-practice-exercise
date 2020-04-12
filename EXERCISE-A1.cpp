/**
 * A. One Dimensional Array - Number Array
 * Problem 1. Create a program that will ask
 * the user to enter 10 numbers and display
 * it in ascending order.
 * 
 * Created 2020-04-10 09:45:14
 */ 

#include<iostream>
using namespace std;

int main() {

    /* Variable initialization */

    // Integer array to sort from
    int array[10];

    /* Input handling */
    cout << "Enter 10 numbers: " << endl;

    for(int i = 0; i < 10; i++) {
        cin >> array[i];
    }

    /* Sorting algorithm
       PS. this is not an efficient algorithm
       but it will do the job nicely. */
    for(int i = 0; i < 10; i++) {
        int cache = array[i];
        for(int j = 0; j < 10; j++) {
            if(array[i] < array[j]) {
                array[i] = array[j];
                array[j] = cache;
                cache = array[i];
            }
        }
    }

    /* Output handling */
    cout << "Element value of array in ascending order" << endl;
    
    for(int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }

    return 0;
}