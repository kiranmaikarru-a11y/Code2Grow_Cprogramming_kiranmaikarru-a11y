#include<stdio.h>
int main()
{
       int age,health;
       char gender;
       float premium;
       printf("enter age :");
       scanf("%d",&age);
       printf("enter gender (m/f) :"); 
       scanf(" %c",&gender);
       printf("health condition(1-healthy/0-unheathy): ");
       scanf("%d",&health);
       printf("\ncustomer details:\n");
       printf("age: %d\n",age);
       printf("gender:%c\n",gender);
       printf("healthy:%s\n",(health==1)? "healthy" : "unhealthy");
  if( health == 0 && age > 60){
       printf("status: not eligible for insurance\n");
  } 
        else {
           if(age<25) {
             if(health == 1)
                  premium=5000;
}
         else if(age >=25 && age <= 40) 
{
       if(health == 1)
       premium = 7000;
     else 
         premium = 9500;
}
      else if(age >=41 && age<=60)
{
    if (health == 1)
       premium=10000;
    else
     premium = 13000;
   }
     else if(age > 60)
{
      if(health == 1)
        premium = 15000;
}
     if(gender=='F'||gender=='f')
{
      premium=premium-(premium*0.10);
}
     if(premium > 0)
     printf("final preminum:rs%.2f\n",premium);
     else
    printf("status: not eligible for insurance\n");
}
    return 0;
}
 
