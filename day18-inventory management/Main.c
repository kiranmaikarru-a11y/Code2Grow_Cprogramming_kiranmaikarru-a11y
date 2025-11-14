#include <stdio.h>
int main() {
    int productID[10],quantity[10][30],n=0,choice,i;
    char productName[10][30];
    float price[10],value[10];
    while  {
        printf("\n==== INVENTORY MENU ====\n");
        printf("1. Input product details\n");
        printf("2. Display all products\n");
        printf("3. Show inventory value / highest / lowest\n");
        printf("4. Search product by ID\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nEnter number of products (max 10): ");
            scanf("%d", &n);
            if (n > 10) n = 10;
            for (i = 0; i < n; i++) {
                printf("\nProduct %d\n", i + 1);
                printf("Enter Product ID: ");
                scanf("%d", &productID[i]);
                printf("Enter Product Name: ");
                scanf("%s", productName[i]);
                printf("Enter Quantity: ");
                scanf("%d", &quantity[i]);
                printf("Enter Price: ");
                scanf("%f", &price[i]);
                value[i] = quantity[i] * price[i];  
            }}
        else if (choice == 2) {
printf("\n--- PRODUCT LIST ---\n");
            for (i = 0; i < n; i++) {
                printf("\nID: %d", productID[i]);
                printf("\nName: %s", productName[i]);
                printf("\nQuantity: %d", quantity[i]);
                printf("\nPrice: %.2f", price[i]);
                printf("\nValue: %.2f\n", value[i]);
            }
        }
        else if (choice == 3) {
            float total = 0;
            float highest = value[0], lowest = value[0];
            int highIndex = 0, lowIndex = 0;
            for (i = 0; i < n; i++) {
                total += value[i];
                if (value[i] > highest) {
                    highest = value[i];
                    highIndex = i;
                }
                if (value[i] < lowest) {
                    lowest = value[i];
                    lowIndex = i;
                }
            }

            printf("\nTotal Inventory Value = %.2f\n", total);

            printf("\nHighest Value Product:\n");
            printf("ID: %d, Name: %s, Value: %.2f\n",
                   productID[highIndex], productName[highIndex], highest);
printf("\nLowest Value Product:\n");
            printf("ID: %d, Name: %s, Value: %.2f\n",
                   productID[lowIndex], productName[lowIndex], lowest);
        }

        else if (choice == 4) {
            int searchID, found = 0;
            printf("\nEnter Product ID to search: ");
            scanf("%d", &searchID);
            for (i = 0; i < n; i++) {
                if (productID[i] == searchID) {
                    found = 1;
                    printf("\nProduct Found:\n");
                    printf("ID: %d\n", productID[i]);
                    printf(
                      "Name: %s\n", productName[i]);
                    printf("Quantity: %d\n", quantity[i]);
                    printf("Price: %.2f\n", price[i]);
                    printf("Value: %.2f\n", value[i]);
                }
            }
            if (!found)
                printf("Product not found!\n");
        }
        else if (choice == 5) {
            break;   // exit the loop
        }
        else {
printf("Invalid choice!\n");
        }
    }
    return 0;
}
