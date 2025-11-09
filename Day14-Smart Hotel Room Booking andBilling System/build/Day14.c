#include <stdio.h>

int main() {
    int total_customers;
    int current_customer = 1;
    char customer_name[50];
    int room_type, num_days;
    char add_breakfast, add_wifi, add_gym;
    // Use long long for monetary values to prevent overflow with large inputs
    // and store values in smallest unit (paise/cents) to avoid floating point issues.
    long long base_fare_paise, services_cost_paise, subtotal_paise, discount_amount_paise, total_before_gst_paise, final_bill_paise;
    long long daily_rate_paise = 0;
    long long wifi_rate_paise = 1000; // ₹100
    long long gym_rate_paise = 2000;  // ₹200
    long long breakfast_rate_paise = 3000; // ₹300

    // Variables for Hotel Summary (global scope simulation for the main function block)
    long lon…
#include <stdio.h>

int main() {
    int total_customers;
    int current_customer = 1;
    char customer_name;
    int room_type, num_days;
    char add_breakfast, add_wifi, add_gym;
    // Use long long for monetary values to prevent overflow with large inputs
    // and store values in smallest unit (paise/cents) to avoid floating point issues.
    long long base_fare_paise, services_cost_paise, subtotal_paise, discount_amount_paise, total_before_gst_paise, final_bill_paise;
    long long daily_rate_paise = 0;
    long long wifi_rate_paise = 1000; // ₹100
    long long gym_rate_paise = 2000;  // ₹200
    long long breakfast_rate_paise = 3000; // ₹300

    // Variables for Hotel Summary (global scope simulation for the main function block)
    long long total_rooms_booked = 0;
    long long total_revenue_paise = 0;
    long long highest_bill_paise = 0;
    long long lowest_bill_paise = 0;
    int first_customer = 1; // Flag to set initial lowest bill

    // Constants
    int GST_RATE = 12;
    int DISCOUNT_PERCENT = 10;
    long long DISCOUNT_THRESHOLD_PAISE = 1000000; // ₹10,000

    printf("Smart Hotel Room Booking System\n");
    printf("Enter total number of customers: ");
    scanf("%d", &total_customers);

    // Main loop to process each customer
    while (current_customer <= total_customers) {
        printf("\n--- Customer %d ---\n", current_customer);
        printf("Enter name: ");
        scanf("%s", customer_name); // Reads name without spaces

        // Room Type Selection Loop (Input Validation)
        do {
            printf("Enter room type (1-Deluxe, 2-Super Deluxe, 3-Suite): ");
            scanf("%d", &room_type);
            daily_rate_paise = 0; // Reset rate
            if (room_type == 1) {
                daily_rate_paise = 250000; // ₹2500
            } else if (room_type == 2) {
                daily_rate_paise = 400000; // ₹4000
            } else if (room_type == 3) {
                daily_rate_paise = 600000; // ₹6000
            } else {
                printf("Invalid room type selected. Please choose 1, 2, or 3.\n");
            }
        } while (daily_rate_paise == 0);

        printf("Enter number of days: ");
        scanf("%d", &num_days);

        // Services Input
        printf("Add Breakfast (Y/N)?: ");
        scanf(" %c", &add_breakfast); // Note the space before %c to consume newline
        printf("Add Wi-Fi (Y/N)?: ");
        scanf(" %c", &add_wifi);
        printf("Add Gym (Y/N)?: ");
        scanf(" %c", &add_gym);

        // Calculate Base Fare and Services Cost
        base_fare_paise = daily_rate_paise * num_days;
        services_cost_paise = 0;

        // The following IF blocks calculate the cost of services based on user input (Y/N)
        if (add_breakfast == 'Y' || add_breakfast == 'y') {
            services_cost_paise += breakfast_rate_paise * num_days;
        }
        if (add_wifi == 'Y' || add_wifi == 'y') {
            services_cost_paise += wifi_rate_paise * num_days;
        }
        if (add_gym == 'Y' || add_gym == 'y') {
            services_cost_paise += gym_rate_paise * num_days;
        }
        // End of services calculation

        subtotal_paise = base_fare_paise + services_cost_paise;
        total_before_gst_paise = subtotal_paise;
        discount_amount_paise = 0;

        // Apply 10% discount if total (before GST) exceeds ₹10,000
        if (total_before_gst_paise > DISCOUNT_THRESHOLD_PAISE) {
            discount_amount_paise = (total_before_gst_paise * DISCOUNT_PERCENT) / 100;
            total_before_gst_paise -= discount_amount_paise;
        }

        // Apply GST (12% on the final total after discount)
        final_bill_paise = total_before_gst_paise + (total_before_gst_paise * GST_RATE) / 100;

        // Display individual bill immediately
        printf("\n#### *Individual Bill for %s:*\n", customer_name);
        printf("Base Fare: \u20B9%.2f\n", (float)base_fare_paise / 100.0);
        printf("Additional Services: \u20B9%.2f\n", (float)services_cost_paise / 100.0);
        printf("Subtotal: \u20B9%.2f\n", (float)subtotal_paise / 100.0);
        if (discount_amount_paise > 0) {
           printf("Discount (%d%%): -\u20B9%.2f\n", DISCOUNT_PERCENT, (float)discount_amount_paise / 100.0);
        }
        printf("GST (%d%%): \u20B9%.2f\n", GST_RATE, (float)(final_bill_paise - total_before_gst_paise) / 100.0);
        printf("#### *Total Bill:* \u20B9%.2f\n", (float)final_bill_paise / 100.0);

        // Update Hotel Summary statistics
        total_rooms_booked++;
        total_revenue_paise += final_bill_paise;

        if (first_customer || final_bill_paise > highest_bill_paise) {
            highest_bill_paise = final_bill_paise;
        }
        if (first_customer || final_bill_paise < lowest_bill_paise) {
            lowest_bill_paise = final_bill_paise;
            first_customer = 0; // First customer processed
        }

        current_customer++;
    }

    // Display Hotel Summary after all customers are processed
    printf("\n\n--- Hotel Summary ---\n");
    printf("Total rooms booked: %lld\n", total_rooms_booked);
    printf("Total Revenue: \u20B9%.2f\n", (float)total_revenue_paise / 100.0);
    printf("Highest Bill: \u20B9%.2f\n", (float)highest_bill_paise / 100.0);
    printf("Lowest Bill: \u20B9%.2f\n", (float)lowest_bill_paise / 100.0);

    return 0;
}
