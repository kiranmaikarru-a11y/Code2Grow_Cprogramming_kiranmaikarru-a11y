#include<stdio.h>
int main()
{
int unit;
printf("units consumed:");
scanf("%d",&unit);
printf("Electricity Bill Summary: \n");
printf("Total Units Consumed: %d \n",unit);
if((unit>0) && (unit<=100))
{
float total_bill1=(unit*3.00)+50.0;
printf("Total Bill (including meter charge): %f \n",total_bill1);
}
else if((unit>100) && (unit<=200))
{
float total_bill2=(unit*4.50)+50.0;
printf("total bill(including meter charge): %f \n",total_bill2);
}
else if((unit>201) && (unit<=300))
{
float total_bill3=(unit*6.00)+50.0;
printf("total bill(including meter charge):%f \n",total_bill3);
}
else
{
float total_bill4=(unit*8.00)+50.0;
printf("total bill(including meter charge):%f \n",total_bill4);
}
return 0;}
