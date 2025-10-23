#include <stdio.h> 
int main()
{
    float basic_salary;
    float hra_percent, da_percent, tax_percent;
    float hra,da,tax,gross_salary;
    
        printf("Enter Basic Salary : ");
    scanf("%f",&basic_salary);
    printf("Enter HRA% : ");
    scanf("%f",&hra_percent);
    printf("Enter DA% : ");
    scanf("%f",&da_percent);
    printf("Enter TAX% : ");
    scanf("%f",&tax_percent);
    printf("\n");
    
      hra = basic_salary * (hra_percent / 100);
     da = basic_salary * (da_percent / 100);
     tax = basic_salary * (tax_percent / 100);
     gross_salary = basic_salary + hra + da - tax;
     
       printf("HRA : %f \n",hra);
    printf("DA : %f \n",da);
    printf("TAX : %f \n",tax);
    printf("GROSS SALARY : %f \n",gross_salary);
    
     int result=gross_salary>50000.00;
    printf("is monthly salary above 50000?%d \n",result);
    
      float monthly = gross_salary / 12;
    printf("MONTHLY SALARY : %f \n",monthly);
    
    return 0;
}

