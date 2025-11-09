#include <stdio.h>
int main() {
    int totalcustomers;
    int currentcustomer = 1;
    char customername;
    int roomtype, numdays;
    char addbreakfast, addwifi, addgym;
     long basefarepaise, servicescostpaise, subtotalpaise, discountamountpaise, totalbeforegstpaise, finalbillpaise;
    long dailyratepaise = 0;
     long wifiratepaise = 1000; 
    long gymratepaise = 2000;  
    long breakfastratepaise = 3000; 
     long totalroomsbooked = 0;
   long totalrevenuepaise = 0;
     long highestbillpaise = 0;
     long lowestbillpaise = 0;
    int firstcustomer = 1; 
    int GSTRATE = 12;
    int DISCOUNTPERCENT = 10;
    long long DISCOUNTTHRESHOLDPAISE = 1000000; 
    printf("Smart Hotel Room Booking System\n");
    printf("Enter total number of customers: ");
    scanf("%d", &total_customers);
    while (currentcustomer <= totalcustomers) {
        printf("\n--- Customer %d ---\n", currentcustomer);
        printf("Enter name: ");
        scanf("%s", customername);
        do {
            printf("Enter room type (1-Deluxe, 2-Super Deluxe, 3-Suite): ");
            scanf("%d", &roomtype);
dailyratepaise = 0; 
            if (room_type == 1) {
                dailyratepaise = 250000;
            } else if (roomtype == 2) {
                dailyratepaise = 400000; 
            } else if (roomtype == 3) {
                dailyratepaise = 600000; 
            } else {
                printf("Invalid room type selected. Please choose 1, 2, or 3.\n");
            }
        } while (dailyratepaise == 0);
        printf("Enter number of days: ");
        scanf("%d", &numdays);
        printf("Add Breakfast (Y/N)?: ");
        scanf(" %c", &addbreakfast); 
        printf("Add Wi-Fi (Y/N)?: ");
        scanf(" %c", &addwifi);
        printf("Add Gym (Y/N)?: ");
        scanf(" %c", &addgym);
        basefarepaise = dailyratepaise * numdays;
        servicescostpaise
        if (addbreakfast == 'Y' || addbreakfast == 'y') {
            servicescostpaise += breakfastratepaise * numdays;
        }
        if (addwifi == 'Y' || addwifi == 'y') {
            servicescostpaise += wifiratepaise * numdays;
        }
        if (addgym == 'Y' || addgym == 'y') {
            servicescostpaise += gymratepaise * numdays;
        }subtotalpaise = basefarepaise + servicescostpaise;
        totalbeforegstpaise = subtotalpaise;
        discountamountpaise = 0;
        if (totalbeforegstpaise > DISCOUNTTHRESHOLDPAISE) {
            discountamountpaise = (totalbeforegstpaise * DISCOUNTPERCENT) / 100;
            totalbeforegstpaise -= discountamountpaise;
        }
        finalbillpaise = totalbefore_gst_paise + (totalbeforegstpaise * GSTRATE) / 100;
        printf("\n *Individual Bill for %s:*\n", customername);
        printf("Base Fare: %.2f\n", (float)basefarepaise / 100.0);
        printf("Additional Services: \u%.2f\n", (float)servicescostpaise / 100.0);
        printf("Subtotal: %.2f\n", (float)subtotalpaise / 100.0);
        if (discountamountpaise > 0) {
           printf("Discount (%d%%):%.2f\n", DISCOUNTPERCENT, (float)discountamountpaise / 100.0);
        }
        printf("GST (%d%%): %.2f\n", GSTRATE, (float)(finalbillpaise - totalbeforegstpaise) / 100.0);
        printf("#### *Total Bill:* %.2f\n", (float)finalbillpaise / 100.0);
        totalroomsbooked++;
        totalrevenuepaise += finalbillpaise;

        if (firstcustomer || finalbillpaise > highestbillpaise) {
            highestbillpaise = finalbillpaise;
        }
        if (firstcustomer || finalbillpaise < lowestbillpaise) {
            lowestbillpaise = finalbillpaise;
            firstcustomer = 0; 
        }
        currentcustomer++;
    }
    printf("\n\n--- Hotel Summary ---\n");
  printf("Total rooms booked: \n", totalroomsbooked);
    printf("Total Revenue: %.2f\n", (float)totalrevenuepaise / 100.0);
    printf("Highest Bill: %.2f\n", (float)highestbillpaise / 100.0);
    printf("Lowest Bill: %.2f\n", (float)lowestbillpaise / 100.0);

    return 0;
}
