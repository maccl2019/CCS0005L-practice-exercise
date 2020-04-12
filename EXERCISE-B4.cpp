/**
 * B. One Dimensional Array - Array of Characters
 * Problem 4. Create a program that will check if
 * a given word is a palindrome or not.
 * 
 * Created 2020-04-11 08:46:28
 */

#include<iostream>
#include<cstring>
using namespace std;

int main() {
    
    /* Variable initialization */
    char input[255] = "";
    bool isPalindrome = true;

    /* Input handling */
    cout << "Enter a word: ";
    cin.getline(input, 255);
    
    int len = strlen(input) - 1;

    /* Palindrome checker */
    for(int i = len; i >= 0; i--) {
        if(input[i] != input[len - i]) isPalindrome = false;
    }

    /* Output handling */

    cout << input << (isPalindrome ? " is " : " is not ") << "a palindrome";

    return 0;
}