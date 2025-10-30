#include <stdio.h>

int main() {
    float dataused, totalbill, basecost = 0, extrarate = 0.0, extradatacost = 0.0, dailylimit = 0, limit = 0, discount = 0.0;
    int student, corporate;
    char planname[20];

    printf("Enter total data used (in GB): ");
    scanf("%f", &dataused);

    printf("Student status (1 for yes / 0 for no): ");
    scanf("%d", &student);

    printf("Corporate status (1 for yes / 0 for no): ");
    scanf("%d", &corporate);

    if (dataused > 100) {
        printf("Excessive usage - plan not allowed\n");
        return 0;
    }

    if (dataused < 30) {
        basecost = 299;
        dailylimit = 1;
        extrarate = 50;
        sprintf(planname, "Silver");
    }
    else if (dataused <= 60) {
        basecost = 499;
        dailylimit = 2;
        extrarate = 40;
        sprintf(planname, "Gold");
    }
    else {
        basecost = 799;
        dailylimit = 3;
        extrarate = 30;
        sprintf(planname, "Platinum");
    }

    limit = dailylimit * 30;

    if (dataused > limit)
        extradatacost = (dataused - limit) * extrarate;
    else
        extradatacost = 0.0;

    totalbill = basecost + extradatacost;

    if (student == 1 && corporate == 1) {
        discount = 0.15;
    }
    else if (student == 1) {
        discount = 0.15;
    }
    else if (corporate == 1) {
        discount = 0.10;
    }
    else {
        discount = 0.0;
    }

    totalbill = totalbill - (totalbill * discount);

    printf("\n----- BILL DETAILS -----\n");
    printf("Selected Plan: %s\n", planname);
    printf("Base Cost: Rs %.2f\n", basecost);
    printf("Extra Data Used: %.2f GB\n", (dataused > limit) ? (dataused - limit) : 0.0);
    printf("Extra Data Charge: Rs %.2f\n", extradatacost);
    printf("Discount Applied: %.0f%%\n", discount * 100);
    printf("Total Bill Amount: Rs %.2f\n", totalbill);

    return 0;
}

