#include <stdio.h>
int main() {
    int totalCustomers;
    float grandTotal = 0;
    printf("Enter total number of customers: ");
    scanf("%d", &totalCustomers);
    printf("\nWelcome to Smart Canteen Billing System \n");
    for (int c = 1; c <= totalCustomers; c++) {
        int numItems;
        float total = 0, discount = 0, finalBill = 0;
        printf("\nCustomer %d\n", c);
        printf("\nMenu Card:\n");
        printf("1. Sandwich  - ₹80\n");
        printf("2. Burger    - ₹120\n");
        printf("3. Pizza     - ₹150\n");
        printf("4. Coffee    - ₹60\n");
        printf("5. Juice     - ₹50\n");
        printf("\nEnter number of items: ");
        scanf("%d", &numItems);
        for (int i = 1; i <= numItems; i++) {
            int code, qty;
            float price = 0;
            printf("\nEnter item code: ");
            scanf("%d", &code);
            printf("Enter quantity: ");
            scanf("%d", &qty);
            switch (code) {
                case 1: price = 80; break;
                case 2: price = 120; break;
                case 3: price = 150; break;
                case 4: price = 60; break;
                case 5: price = 50; break;
                default:
                    printf("Invalid code! Skipping item.\n");
                    continue;
            }
            printf("Item cost: ₹%.2f\n", price * qty);
            total += price * qty;
        }
        printf("\nCustomer %d Total: ₹%.2f\n", c, total);
        if (total > 500) {
            discount = total * 0.10;
            printf("Discount Applied (10%%): ₹%.2f\n", discount);
        } else {
            printf("No discount applied.\n");
        }
        finalBill = total - discount;
        printf("Final Bill: ₹%.2f\n", finalBill);
      grandTotal += finalBill;
    }
    printf("\nCanteen Summary\n");
    printf("Total Customers Served: %d\n", totalCustomers);
    printf("Total Revenue: ₹%.2f\n", grandTotal);
    printf("\n");

    return 0;
}
