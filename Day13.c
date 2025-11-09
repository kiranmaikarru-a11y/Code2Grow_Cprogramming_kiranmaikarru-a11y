#include <stdio.h>
#include <string.h>

#define BASE_FARE_PER_KM 10.0
#define MINIMUM_FARE 20.0
#define CHILD_DISCOUNT 0.50
#define SENIOR_DISCOUNT 0.30
#define PEAK_HOUR_SURCHARGE 0.20

int main() {
    int total_passengers = 0;
    float total_revenue = 0.0;
    float highest_fare = 0.0;
    float lowest_fare = -1.0;
    int num_passengers;

    printf("Enter total number of passengers: ");
    scanf("%d", &num_passengers);

    for (int i = 0; i < num_passengers; i++) {
        char name[50];
        int age, distance, time;
        float fare, final_fare;

        printf("\n--- Passenger %d ---\n", i + 1);
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter age: ");
        scanf("%d", &age);
        printf("Enter distance (in km): ");
        scanf("%d", &distance);
        printf("Enter time of travel (24-hour format): ");
        scanf("%d", &time);

        fare = distance * BASE_FARE_PER_KM;

        // Apply peak hour surcharge
        if ((time >= 8 && time <= 10) || (time >= 17 && time <= 20)) {
            fare += fare * PEAK_HOUR_SURCHARGE;
        }

        // Apply age-based discounts
        if (age < 12) {
            fare -= fare * CHILD_DISCOUNT;
        } else if (age >= 60) {
            fare -= fare * SENIOR_DISCOUNT;
        }

        // Apply minimum fare
        if (fare < MINIMUM_FARE) {
            final_fare = MINIMUM_FARE;
        } else {
            final_fare = fare;
        }

        printf("Fare: $%.2f\n", final_fare);
        
        total_passengers++;
        total_revenue += final_fare;

        if (lowest_fare == -1.0 || final_fare < lowest_fare) {
            lowest_fare = final_fare;
        }
        if (final_fare > highest_fare) {
            highest_fare = final_fare;
        }
    }

    printf("\n--- Daily Summary ---\n");
    printf("Total passengers: %d\n", total_passengers);
    printf("Total revenue collected: $%.2f\n", total_revenue);
    printf("Highest fare of the day: $%.2f\n", highest_fare);
    printf("Lowest fare of the day: $%.2f\n", lowest_fare);

    return 0;
}
