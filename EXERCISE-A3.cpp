/**
 * A. One Dimensional Array - Number Array
 * Problem 3. Create a program that will ask
 * the user to enter 10 numbers and display:
 * - First highest number
 * - Second highest number
 * - Second lowest number
 * - Lowest number
 * 
 * Additional notes:
 * Don't use array sorting
 * 
 * Created 2020-04-10 10:44:34 
 */

#include<iostream>
using namespace std;

int main() {
    
    /* Variable initialization */

    int highest = 0;
    int secondHighest = 0;
    int secondLowest = 0;
    int lowest = 0;

    // Integer array to sort
    int array[10];

    /* Input handling */
    cout << "Enter ten numbers: " << endl;

    for(int i = 0; i < 10; i++) {
        cin >> array[i];
    }

    /* Determination algorithm */

    // Highest number
    for(int i = 0; i < 10; i++) {
        if(highest < array[i]) highest = array[i];
    }

    // Use the highest number as the base of the lowest (and second lowest) number
    secondLowest = lowest = highest;

    // Second highest, lowest, and second lowest number
    for(int i = 0; i < 10; i++) {
        if(secondHighest < array[i] && array[i] != highest) secondHighest = array[i];
        if(lowest > array[i]) lowest = array[i];
        if(secondLowest > array[i] && array[i] != lowest) secondLowest = array[i];
    }

    if(highest == secondLowest) {
        // Special case: if there is no unique numbers in the array
        lowest = secondHighest = highest;
    }

    /* Output handling */
    cout << "highest: " << highest << endl;
    cout << "second highest: " << secondHighest << endl;
    cout << "lowest: " << lowest << endl;
    cout << "second lowest: " << secondLowest << endl;

    return 0;
}
