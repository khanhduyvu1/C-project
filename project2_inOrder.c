/*
 * The program that determines if the input characters are in order
 */
#include <stdio.h>
#include <ctype.h>

int main() {
    char prevChar, currChar;
    int isValid = 1;
    printf("Enter input:");
    prevChar = getchar(); //Get the first character
    if (prevChar == '\n' || isalpha(prevChar) == 0) {   //Check if the input is empty or just a number (0 to 9) initially
        printf("invalid input\n");
        return 1;
    }
    while ((currChar = getchar()) != '\n') {
        if (!isalpha(prevChar) || !isalpha(currChar)) {
            printf("invalid input\n"); // if number in the input print invalid
            return 1;
        }
        if (tolower(prevChar) > tolower(currChar)) {
            isValid = 0; //not in order
            break;
        }
        prevChar = currChar;
    }
    if (isValid) {
        printf("in order\n");
    }
    else {
        printf("not in order\n");
    }
    return 0;
}