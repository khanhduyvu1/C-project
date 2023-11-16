/*
 * The program calculates and prints the charges for a floor cleaning equipment rental,
 * allows users enter type of floor cleaning with time.
 */
#include <stdio.h>
void carpet_blower();
void carpet_cleaner();
void carpet_extractor_with_heater();
void hard_flooring_cleaner();

int selection = 0;
int hours = 0;
int days = 0;
int costs = 0;
int main() {
    printf("Please select from four equipment: 1, 2, 3, and 4\n");
    printf("Enter equipment selection: ");
    scanf("%d", &selection);
    if (selection > 4 || selection < 1) {
        printf("Invalid selection. Select from 1 to 4.\n");
    }
    else {
        printf("Enter days: ");
        scanf("%d",&days);
        printf("Enter hours: ");
        scanf("%d", &hours);
        if (hours < 0 || hours > 24) {
            printf("Invalid hours.\n");
            return 1;
        }
        else {
            switch(selection) {
                case 1:
                    carpet_blower();
                    break;
                case 2:
                    carpet_cleaner();
                    break;
                case 3:
                    carpet_extractor_with_heater();
                    break;
                case 4:
                    hard_flooring_cleaner();
                    break;
                default:
                    printf("Invalid selection. Select from 1 to 4.\n");
                    break;
            }
        }
    }
    return 0;
}
// 4 selections have the same structure, just replaced by the price.
void carpet_blower() {
    if (hours <= 4) {
        if (days%7 < 4) {
            // calculated by weeks + days(less than 4) + 4-hours
            costs = (days - days % 7) / 7 * 40 + days % 7 * 10 + 7;
        }
        else {
            // calculated by (weeks + 1) and (4-hours) due to more than 5 days count as 1 week
            costs = (days - days % 7) / 7 * 40 + 40 + 7;
        }
    }
    else {
        days += 1; // more than 4 hours count as 1 day
        if (days%7 < 4) {
            // calculated by weeks + days(less than 4)
            costs = (days - days % 7) / 7 * 40 + days % 7 * 10;
        }
        else {
            // calculated by (weeks + 1) due to more than 4 days
            costs = (days - days % 7) / 7 * 40 + 40;
        }
    }
    printf("Charge($): %d\n",costs);
}
void carpet_cleaner() {
    if (hours <= 4) {
        if (days%7 < 4) {
            costs = (days - days % 7) / 7 * 156 + days % 7 * 39 + 27;
        }
        else {
            costs = (days - days % 7) / 7 * 156 + 156 + 27;
        }
    }
    else {
        days += 1;
        if (days%7 < 4) {
            costs = (days - days % 7) / 7 * 156 + days % 7 * 39;
        }
        else {
            costs = (days - days % 7) / 7 * 156 + 156;
        }
    }
    printf("Charge($): %d\n",costs);
}
void carpet_extractor_with_heater() {
    if (hours <= 4) {
        if (days%7 < 4) {
            costs = (days - days % 7) / 7 * 348 + days % 7 * 87 + 61;
        }
        else {
            costs = (days - days % 7) / 7 * 348 + 348 + 61;
        }
    }
    else {
        days += 1;
        if (days%7 < 4) {
            costs = (days - days % 7) / 7 * 348 + days % 7 * 87;
        }
        else {
            costs = (days - days % 7) / 7 * 348 + 348;
        }
    }
    printf("Charge($): %d\n",costs);
}
void hard_flooring_cleaner() {
    if (hours <= 4) {
        if (days%7 < 4) {
            costs = (days - days % 7) / 7 * 336 + days % 7 * 84 + 59;
        }
        else {
            costs = (days - days % 7) / 7 * 336 + 336 + 59;
        }
    }
    else {
        days += 1;
        if (days%7 < 4) {
            costs = (days - days % 7) / 7 * 336 + days % 7 * 84;
        }
        else {
            costs = (days - days % 7) / 7 * 336 + 336;
        }
    }
    printf("Charge($): %d\n",costs);
}