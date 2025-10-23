
#include <stdio.h>
int main() {
    float meal_cost, tax, tip, total_bill;
    float person1, person2,person3;
    printf("Enter meal cost: ");
    scanf("%f", &meal_cost);
 
    tax =( 5 * meal_cost)/100 ;
    tip = (10* meal_cost)/100;
    total_bill = meal_cost + tax + tip;
    person1 = (total_bill / 3) + ((total_bill / 3) / 2);
    person2 = person1;
    person3 = 0;
    printf("Total bill: %f\n", total_bill);
    printf("Each person should pay accordingly:\n");
    printf("You: %f\n", person1);
    printf("Friend 2: %f\n", person2);
    printf("Friend 3: %f\n", person3);
    return 0;
}
