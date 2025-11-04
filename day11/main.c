#include <stdio.h>

int main() {
    int choice;
    float balance = 10000.0;
    float amount;
    int transaction_count = 0;

    printf("========== Mini ATM Simulator ==========\n");
    printf("Initial Balance: %.2f\n", balance);

    do {
        printf("\n1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Your Current Balance: %.2f\n", balance);
                break;
            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("Amount Deposited Successfully!\n");
                } else {
                    printf("Invalid amount.\n");
                }
                break;
            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (amount > 0 && balance - amount >= 500) {
                    balance -= amount;
                    printf("Withdrawal Successful! Remaining Balance: %.2f\n", balance);
                } else if (balance - amount < 500) {
                    printf("Insufficient balance. Minimum balance of 500 must be maintained.\n");
                } else {
                    printf("Invalid amount.\n");
                }
                break;
            case 4:
                printf("Thank you for banking with us!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        if (choice >= 1 && choice <= 3) {
            transaction_count++;
        }

        if (transaction_count >= 5) {
            printf("\nMaximum 5 transactions reached. Session ended.\n");
            choice = 4; // Force exit
        }
    } while (choice != 4);

    printf("\n========== Transaction Summary ==========\n");
    printf("Total Transactions: %d\n", transaction_count);
    printf("Final Balance: %.2f\n", balance);
    printf("Session Ended.\n");

    return 0;
}
