#include <stdio.h>

int main() {
    int prices[5] = {50, 30, 80, 120, 60};
    char items[5][20] = {"Coffee", "Tea", "Sandwich", "Burger", "Pastry"};
    int totalSold[5] = {0};
    int totalRevenue = 0, totalItems = 0;
    int numCustomers;

    printf("=========== Café Order Management System ===========\n");

    printf("Enter total number of customers (max 10): ");
    scanf("%d", &numCustomers);

    for (int c = 0; c < numCustomers; c++) {
        char name[30];
        int numOrders, itemNo, qty, bill = 0;

        printf("\n--- Enter Customer Name: ");
        scanf("%s", name);

        printf("Enter number of items: ");
        scanf("%d", &numOrders);

        printf("Enter item number and quantity:\n");
        for (int k = 0; k < numOrders; k++) {
            scanf("%d %d", &itemNo, &qty);

            if (itemNo >= 1 && itemNo <= 5) {
                bill += prices[itemNo - 1] * qty;
                totalSold[itemNo - 1] += qty;
                totalItems += qty;
            } else {
                printf("Invalid item number! Try again.\n");
                k--; // retry input
            }
        }

        totalRevenue += bill;
        printf("Total Bill for Customer %d: %d\n", c + 1, bill);
    }

    // find most and least ordered items
    int most = 0, least = 0;
    for (int i = 1; i < 5; i++) {
        if (totalSold[i] > totalSold[most]) most = i;
        if (totalSold[i] < totalSold[least]) least = i;
    }

    printf("\n=========== Café Summary ===========\n");
    printf("Total Revenue: %d\n", totalRevenue);
    printf("Total Items Sold: %d\n", totalItems);
    printf("Most Ordered Item: %s\n", items[most]);
    printf("Least Ordered Item: %s\n", items[least]);
    printf("====================================\n");

    return 0;
}
