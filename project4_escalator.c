/*
 * The program calculates the number of active seconds that an escalator was active.
 */
#include<stdio.h>

int active_seconds(int arrival[], int n) {
    int active = 0;
    int *ptr = arrival;
    for (int i = 1; i<n; i++) {
        int interval = *(ptr + i) - *(ptr + i - 1); //calculate the interval between each person from the 1st
        if (interval >= 10) {
            active += 10; // if the interval larger than 10 secs, counts as 10 secs
        }
        else {
            active += interval;
        }
    }
    active += 10;// extra 10 secs since the last person
    return active;
}
int main() {
    int n;
    printf("Enter number of people: ");
    scanf("%d",&n);
    int arrival[n];
    printf("Enter arrival times: ");
    for (int i = 0; i<n; i++) {
        scanf("%d",&arrival[i]);
    }
    int time = active_seconds(arrival, n);
    printf("Active seconds: %d\n", time);
    return 0;
}
