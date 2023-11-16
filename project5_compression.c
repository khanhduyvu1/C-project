/*
 * Khanh Vu
 * U56604117
 * The program encode is as follows: 'consecutive character count' followed by the 'character'
 */
#include <stdio.h>

void compress(char *input, char *output) {
    char current_char = *input;
    int count = 1;

    while (*input) {
        input++;
        if (*input == current_char) {
            count++;
        } else {
            if (count > 2) {
                *output = count + '0'; // Convert count to character
                output++;
            }
            else if (count == 2) { // Make sure the characters don't encode unless they lead to compression
                *output = current_char;
                output++;
            }
            *output = current_char;
            output++;

            current_char = *input;
            count = 1;
        }
    }

    if (count > 1) {
        *output = count + '0'; // Convert count to character
        output++;
    }
    *output = '\0';
}

int main() {
    char input[1001]; // no more than 1000 characters
    char compressed[1001];

    printf("Enter message: ");
    scanf("%s", input);

    compress(input, compressed);

    printf("Output: %s\n", compressed);

    return 0;
}