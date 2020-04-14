/**
 * A. One Dimensional Array - Number Array
 * Problem 2. Create a program that will convert
 * a decimal number (positive value) to its 
 * equivalent binary number.
 * 
 * Additional notes:
 * Use array for binary values.
 * 
 * Created 2020-04-10 10:01:14
 */

#include<iostream>
using namespace std;

int main() {
    /* Variable initialization */

    // Integer to convert to
    short decimalToConvert;
    char representation[16] = "\0";

    /* Input handling */
    cout << "Enter a decimal number: ";

    cin >> decimalToConvert;

    /* Conversion algorithm */
    int rPos = 0;
    while(decimalToConvert != 0 && rPos >= 0) {
        representation[rPos] = (decimalToConvert % 2 ? '1' : '0');
        decimalToConvert /= 2;
        rPos++;
    }

    /* Output handling */
    cout << "Binary equivalent: ";

    for(int i = 16; i >= 0; i--) {
        if(isdigit(representation[i])) cout << representation[i];
    }

    return 0;
}