#include <stdio.h>
int main() {
    int productID[10], quantity[10],count =0,choice,i;
    float price[10];
    char name[10][50];
   { while  
        printf("\n===== MENU =====\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Inventory Value + Highest + Lowest\n");
        printf("4. Search by ID\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            if (count == 10) {
                printf("Cannot add more products.\n");
            } else {
                printf("Enter Product ID: ");
                scanf("%d", &productID[count]);

                printf("Enter Product Name: ");
                scanf("%s", name[count]);

                printf("Enter Quantity: ");
                scanf("%d", &quantity[count]);

                printf("Enter Price: ");
                scanf("%f", &price[count]);

                count++;
                printf("Product Added!\n");
            }
        }

        else if (choice == 2) {
            if (count == 0) {
                printf("No products added.\n");
            } else {
                printf("\n--- Product List ---\n");
                for (i = 0; i < count; i++) {
                    printf("%d  %s  %d  %.2f\n",
                           productID[i], name[i], quantity[i], price[i]);
                }
            }
        }

        else if (choice == 3) {
            if (count == 0) {
                printf("No data to calculate.\n");
            } else {
                float total = 0;
                float highest = -1, lowest = 999999;
                int highIndex = 0, lowIndex = 0;
                float value;
                for (i = 0; i < count; i++) {
                    value = quantity[i] * price[i];
            total += value;
            if (value > highest) {
            highest = value;
            highIndex = i;
            }
            if (value < lowest) {
            lowest = value;
            lowIndex = i;
            }}        
            printf("Total Inventory Value = %.2f\n", total);
            printf("Highest Value Product = %s (%.2f)\n", name[highIndex], highest);
            printf("Lowest Value Product  = %s (%.2f)\n", name[lowIndex], lowest);
           } }
          else if (choice == 4) {
          if (count == 0) {
          printf("No products added.\n");
          } else {
          int id, found = 0;
          printf("Enter Product ID to search: ");
          scanf("%d", &id);
         for (i = 0; i < count; i++) {
         if (productID[i] == id) {
        printf("Found: %d %s %d %.2f\n",
        productID[i], name[i], quantity[i], price[i]);
        found = 1;
        break;
        }}
        if (found == 0) {
        printf("Product not found.\n");
        } } }
        else if (choice == 5) {
        break;
        }
        else {
        printf("Invalid choice.\n");
    } }
    return 0;
}
