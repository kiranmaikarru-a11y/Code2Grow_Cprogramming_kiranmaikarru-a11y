#include <stdio.h>
int main() {
    char name[50], regNo[20], section[10];
    float salary[10];
    int n, i, j, choice;
    float total, avg, highest, lowest, temp;
    int above, below;
    printf("Enter Student Name: ");
    scanf(name, sizeof(name), stdin);
    printf("Enter Register Number: ");
    scanf(regNo, sizeof(regNo), stdin);
    printf("Enter Section: ");
    scanf(section, sizeof(section), stdin);
    printf("\nEnter number of employees (max 10): ");
    scanf("%d", &n);
    printf("Enter salaries:\n");
    for (i = 0; i < n; i++) {
        printf("Salary %d: ", i + 1);
        scanf("%f", &salary[i]);
    }
    do {
        printf("\n===== MENU =====\n");
        printf("1. Show All Salaries\n");
        printf("2. Show Total and Average Salary\n");
        printf("3. Show Highest and Lowest Salary\n");
        printf("4. Count Above and Below Average\n");
        printf("5. Sort Salaries (Ascending)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
 printf("\nAll Salaries:\n");
            for (i = 0; i < n; i++) {
                printf("%.2f\n", salary[i]);
            }
        }

        else if (choice == 2) {
            total = 0;
            for (i = 0; i < n; i++) {
                total += salary[i];
            }
            avg = total / n;
            printf("Total Salary = %.2f\n", total);
            printf("Average Salary = %.2f\n", avg);
        }
        else if (choice == 3) {
            highest = salary[0];
            lowest = salary[0];
            for (i = 1; i < n; i++) {
                if (salary[i] > highest)
                    highest = salary[i];
                if (salary[i] < lowest)
                    lowest = salary[i];
            }
            printf("Highest Salary = %.2f\n", highest);
            printf("Lowest Salary = %.2f\n", lowest);
        }
        else if (choice == 4) {
            total = 0;
            for (i = 0; i < n; i++) { total += salary[i];
            }
            avg = total / n;
            above = 0;
            below = 0;
            for (i = 0; i < n; i++) {
                if (salary[i] > avg)
                    above++;
                else if (salary[i] < avg)
                    below++;
            }
            printf("Average = %.2f\n", avg);
            printf("Above Average = %d\n", above);
            printf("Below Average = %d\n", below);
        }
        else if (choice == 5) {
            for (i = 0; i < n - 1; i++) {
                for (j = 0; j < n - i - 1; j++) {
                    if (salary[j] > salary[j + 1]) {
                        temp = salary[j];
                        salary[j] = salary[j + 1];
                        salary[j + 1] = temp;
            }}}
            printf("\nSalaries in Ascending Order:\n");
            for (i = 0; i < n; i++) {
                printf("%.2f\n", salary[i]);
            }}
        else if (choice == 6) {
            printf("Exiting the program...\n");
        }else {
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    printf("\nSubmitted by: %sReg No: %sSection: %s", name, regNo, section);
    printf("Challenge Day 17 - Code2Grow Program\n");
    return 0;
}
