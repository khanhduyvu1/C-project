#include <stdio.h>
#include <string.h>

void decode(char words[][101], int num_words, char *result) {
    for (int i = 0; i < num_words; i++) {
        result[i] = words[i][0];
    }
    result[num_words] = '\0';
}

int main() {
    char file_name[101];
    char output_file_name[111] = "decoded_";
    char words[1000][101];
    char result[1001];

    printf("Enter the file name: ");
    scanf("%100s", file_name);

    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    int word_count = 0;
    while (fscanf(file, "%100s", words[word_count++]) == 1);

    fclose(file);

    decode(words, word_count, result);

    strcat(output_file_name, file_name);

    FILE *output_file = fopen(output_file_name, "w");


    fprintf(output_file, "%s", result);
    fclose(output_file);

    printf("Decoded message has been written to file: %s\n", output_file_name);

    return 0;
}
