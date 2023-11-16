/*
 * Khanh Vu
 * U56604117
 * The program that determines if the input characters are in order
 */
#include <stdio.h>
#include <ctype.h>

int inOrder(char *input) {
    if (!isalpha(*input)) {
        return -1; // Invalid input
    }
    char prev = *input;
    input++;
    while (*input) {
        if (!isalpha(*input)) {
            return -1; // Invalid input
        }
        if (*input < prev) {
            return 0; // Not in order
        }
        prev = *input;
        input++;
    }
    return 1; // In order
}
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("invalid input\n");
        return 1;
    }
    int result = inOrder(argv[1]);
    if (result == 1) {
        printf("in order\n");
    } else if (result == 0) {
        printf("not in order\n");
    } else {
        printf("invalid input\n");
    }
    return 0;
}
