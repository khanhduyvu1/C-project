/* Khanh Vu
 * U56604117
 * The program will first ask the user to enter the file name,
 * open and read the file, decode the message, then write the
 * resulting message to a file with the same name but an added prefix of decoded_
 */
#include <stdio.h>
#include <string.h>
void decode(char words[][101], int num_words, char *result);

int main() {
    char file_name[101];
    char output_file_name[111] = "decoded_";
    char words[1000][101];
    char result[1001];
    printf("Enter the file name: ");
    scanf("%s", file_name);
    FILE *pfile = fopen(file_name, "r"); // open file
    if (pfile == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    int word_count = 0;

    while (fscanf(pfile, "%s", words[word_count++]) == 1); // read words until the end

    fclose(pfile);

    decode(words, word_count, result); // call function

    strcat(output_file_name, file_name);

    FILE *output_file = fopen(output_file_name, "w");
    fprintf(output_file, "%s", result);
    fclose(output_file);

    printf("Output file name: %s", output_file_name);

    return 0;
}

void decode(char words[][101], int num_words, char *result){
    // get the first letter of each word
    for (int i = 0; i < num_words; i++) {
        result[i] = words[i][0];
    }
    result[num_words] = '\0';
}