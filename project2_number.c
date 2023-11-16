/*
 * The program determines if a number entered by the user is including digit 3 and divided by 3
 */
#include <stdio.h>

int digit3(int num) { // Check if the input has digit 3
    while (num > 0) {
        if (num % 10 == 3) {
            return 1; //has digit 3
        }
        num /= 10; //divide by 10 to look for digit 3
    }
    return 0; // no digit 3 in the input
}

int main() {
    int num;
    printf("Enter input: ");
    scanf("%d", &num);
    if (num % 3 == 0 && digit3(num)){ // check if the input has divided by 3 and including digit 3
        printf("yes");
    }
    else{
        printf("no");
    }
    return 0;
}