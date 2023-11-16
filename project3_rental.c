/*
 * The program calculates and prints the charges for a floor cleaning equipment rental,
 * allows users enter type of floor cleaning with time.
 * The formula is calculated the same as project 1, just replaced by using array
 */
#include <stdio.h>

int main() {
    //Stored the price into an array
    double rates[4][3] = {
            {7.0, 10.0, 40.0},
            {27.0, 39.0, 156.0},
            {61.0, 87.0, 348.0},
            {59.0, 84.0, 336.0}
    };
    int selection, days, hours;
    int price;
    printf("Please select from four equipment: 1, 2, 3, and 4\n");
    printf("Enter equipment selection: ");
    scanf("%d",&selection);
    if (selection > 4 || selection < 1) {
        printf("Invalid selection. Select from 1 to 4.\n");
    }
    else {
        printf("Enter days: ");
        scanf("%d", &days);
        printf("Enter hours: ");
        scanf("%d", &hours);
        if (hours < 0 || hours > 24) {
            printf("Invalid hours.\n");
            return 1;
        }
        else {
            if (hours <= 4) {
                if (days % 7 < 4) {
                    // calculated by weeks + days(less than 4) + 4-hours
                    price = ((days - days%7)/7) * rates[selection-1][2] + days%7 * rates[selection-1][1] + rates[selection-1][0];
                }
                else {
                    // calculated by (weeks + 1) and (4-hours) due to more than 5 days count as 1 week
                    price = ((days - days%7)/7 + 1) * rates[selection-1][2] + rates[selection-1][0];
                }
            }
            else {
                days += 1; // more than 4 hours count as 1 day
                if (days%7 < 4) {
                    // calculated by weeks + days(less than 4)
                    price = (days - days % 7) / 7 * rates[selection-1][2] + days % 7 * rates[selection-1][1];
                }
                else {
                    // calculated by (weeks + 1) due to more than 4 days
                    price = ((days - days % 7) / 7 + 1) * rates[selection-1][2];
                }
            }
            printf("Charge($): %d\n",price);
        }
    }

    return 0;
}
