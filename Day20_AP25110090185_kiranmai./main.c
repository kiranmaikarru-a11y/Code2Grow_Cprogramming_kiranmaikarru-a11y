#include <stdio.h>
#define MAX 20
int productID[MAX];
int quantity[MAX];
int price[MAX];
int count = 0;
int rack[3][3];
void addProduct();
void searchProduct();
void updateQuantity();
void rackReport();
void calculateStockValues();
void displayAll();
int main() {
int choice;
for(int i=0;i<3;i++){
 for(int j=0;j<3;j++){
rack[i][j] = (i+1)*(j+2);
}
}
 while(1){
 printf("\n===== SMART WAREHOUSE MENU =====\n");
 printf("1. Add Product\n");
 printf("2. Search Product (By ID)\n");
 printf("3. Update Quantity\n");
 printf("4. Generate Rack Report (2D Array)\n");
 printf("5. Calculate Stock Values\n");
 printf("6. Display All Products\n");
printf("7. Exit\n");
printf("Enter choice: ");
scanf("%d",&choice);
switch(choice){
case 1: addProduct(); break;
case 2: searchProduct(); break;
case 3: updateQuantity(); break;
case 4: rackReport(); break;
case 5: calculateStockValues(); break;
case 6: displayAll(); break;
case 7: return 0;
default: printf("Invalid Choice!\n");
}}}
void addProduct(){
if(count >= MAX){
printf("Storage Full! Cannot add more.\n");
return;
}
 int id, q, p;
printf("Enter Product ID: ");
scanf("%d",&id);
for(int i=0;i<count;i++){
if(productID[i] == id){
printf("Duplicate ID! Product already exists.\n");
return;
}}  
printf("Enter Quantity: ");
scanf("%d",&q);
printf("Enter Price: ");
scanf("%d",&p);
if(q <= 0 || p <= 0){
printf("Quantity & Price must be positive.\n");
return;
}
 productID[count] = id;
 quantity[count] = q;
 price[count] = p;
 count++;
printf("Product Added Successfully!\n");
}
void searchProduct(){
 int id;
 printf("Enter Product ID to Search: ");
 scanf("%d",&id);
for(int i=0;i<count;i++){
if(productID[i] == id){
printf("Product Found!\n");
printf("ID: %d\n", productID[i]);
printf("Quantity: %d\n", quantity[i]);
printf("Price: %d\n", price[i]);
return;
}}
printf("Not Found.\n");
}
void updateQuantity(){
int id, change;
printf("Enter Product ID: ");
scanf("%d",&id);
for(int i=0;i<count;i++){
if(productID[i] == id){
printf("Enter Quantity Change (+ or -): ");
scanf("%d",&change);
if(quantity[i] + change < 0){
printf("Quantity cannot be negative!\n");
return;
}
 quantity[i] += change;
 printf("Quantity Updated! New Quantity = %d\n", quantity[i]);
 return;
 }}
printf("Product Not Found.\n");
}
void rackReport(){
int max = rack[0][0], min = rack[0][0];
int maxR=0,maxC=0,minR=0,minC=0;
int total = 0;
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
int val = rack[i][j];
total += val;
if(val > max){
max = val;
maxR = i; 
maxC = j;
}
if(val < min){
min = val;
minR = i; 
minC = j;
printf("\n--- Rack Analysis ---\n");
printf("Maximum Stock: %d at (%d, %d)\n", max, maxR, maxC);
printf("Minimum Stock: %d at (%d, %d)\n", min, minR, minC);
printf("Total Items Across Racks: %d\n", total)
 }
void calculateStockValues(){
if(count==0){
n;
}
int maxVal = -1, minVal = 999999;
int totalValue = 0;
int maxID, minID;
printf("\nID   Qty   Price   StockValue\n");
for(int i=0;i<count;i++){
int value = quantity[i] * price[i];
printf("%d%d%d%d\n", productID[i], quantity[i], price[i], value);
if(value > maxVal){
maxVal = value;
maxID = productID[i];
}
 if(value < minVal){
minVal = value;
minID = productID[i];
}
totalValue += value;
}
printf("\nHighest Stock Value Product ID: %d (Value=%d)\n", maxID, maxVal);
printf("Lowest Stock Value Product ID: %d (Value=%d)\n", minID, minVal);
printf("Total Warehouse Value: %d\n", totalValue);}
void displayAll(){
if(count == 0){
printf("No products to display.\n");
return;
}
printf("\nID   Quantity   Price   StockValue\n");
for(int i=0;i<count;i++){
int value = quantity[i] * price[i];
printf("%d%d%d%d\n",
 productID[i], quantity[i], price[i], value);
}
