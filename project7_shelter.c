/*
 * A program searches for animals in a data file (animals.txt) for adoption purposes
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Store animals information
struct Animal {
    char name[100];
    char species[100];
    char gender[100];
    int age;
    double weight;
};
int compareAnimals(const void *a, const void *b) {
    // Compare based on species first
    int speciesComparison = strcmp(((struct Animal *)a)->species, ((struct Animal *)b)->species);
    if (speciesComparison != 0) {
        return speciesComparison;
    }

    // If species is the same, compare based on age
    int ageComparison = ((struct Animal *)a)->age - ((struct Animal *)b)->age;
    return ageComparison;
}
int main() {
    FILE *inputFile = fopen("animals.txt", "r"); // open animals.txt file
    if (inputFile == NULL) {
        perror("Error opening animals.txt");
        return 1;
    }
    struct Animal animals[200];
    int numAnimals = 0;
    //read data in the input file
    while (fscanf(inputFile, "%s %s %s %d %lf", animals[numAnimals].name, animals[numAnimals].species, animals[numAnimals].gender, &animals[numAnimals].age, &animals[numAnimals].weight) == 5) {
        numAnimals++;
    }
    fclose(inputFile);
    qsort(animals, numAnimals, sizeof(struct Animal), compareAnimals);
    char searchSpecies[100];
    char searchGender[100];
    printf("Enter species: ");
    scanf("%s", searchSpecies);
    printf("Enter gender: ");
    scanf("%s", searchGender);
    printf("Output file name: results.txt");
    FILE *outputFile = fopen("results.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening");
        return 1;
    }
    // print output

    for (int i = 0; i < numAnimals; i++) {
        if (strcmp(animals[i].species, searchSpecies) == 0 && strcmp(animals[i].gender, searchGender) == 0) {
            fprintf(outputFile, "%s %d %.2lf\n", animals[i].name, animals[i].age, animals[i].weight);
        }
    }
    fclose(outputFile);
    return 0;
}

