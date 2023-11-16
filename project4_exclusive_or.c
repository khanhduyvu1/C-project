/*
 * Khanh Vu
 * U56604117
 * The exclusive or of two arrays a and b of
 * integers are the elements that are either in a or in b, but not in both a and b
 */
#include <stdio.h>

void exclusive_or(int *a, int n1, int *b, int n2, int *c, int *size) {
    *size = 0;
    int *pa, *pb, *pc;
    // check if element in array1 is not in array 2
    for (pa = a; pa < a + n1; pa++) {
        int found = 0;
        for (pb = b; pb < b + n2; pb++) {
            if (*pa == *pb) {
                found = 1;
                break;
            }
        }
        if (!found) {
            pc = c + (*size);
            *pc = *pa;
            (*size)++;
        }
    }
    // check if element in array 2 is not in array 1
    for (pb = b; pb < b + n2; pb++) {
        int found = 0;
        for (pa = a; pa < a + n1; pa++) {
            if (*pb == *pa) {
                found = 1;
                break;
            }
        }
        if (!found) {
            pc = c + (*size);
            *pc = *pb;
            (*size)++;
        }
    }
}

int main() {
    int n1, n2;
    // input array 1
    printf("Enter length of array #1: ");
    scanf("%d", &n1);
    int array1[n1];
    printf("Enter array elements: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &array1[i]);
    }
    // input array 2
    printf("Enter length of array #2: ");
    scanf("%d", &n2);
    int array2[n2];
    printf("Enter array elements: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &array2[i]);
    }
    int result[99];
    int size;
    exclusive_or(array1, n1, array2, n2, result, &size);
    // print output
    printf("Output: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}