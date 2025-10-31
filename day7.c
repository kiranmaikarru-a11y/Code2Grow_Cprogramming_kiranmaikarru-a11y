#include<stdio.h>
int main(){
    int ch;
    float bal=10000,amt,bns;
    do{
        printf("\n1.Deposit\n2.Withdraw\n3.Check Balance\n4.Exit\nEnter choice: ");
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter amt to deposit: ");
            scanf("%f",&amt);
            if(amt>25000){
                bns=amt*0.01;
                amt+=bns;
                printf("Bonus of ₹%.0f added!\n",bns);
            }
            bal+=amt;
            bal-=5;
            printf("Service charge ₹5 applied.\nUpdated Balance: ₹%.0f\n",bal);
        }
        else if(ch==2){
            printf("Enter amt to withdraw: ");
            scanf("%f",&amt);
            if(amt>bal){
                printf("Insufficient balance!\n");
            }
            else{
                bal-=amt;
                bal-=5;
                printf("Service charge ₹5 applied.\nUpdated Balance: ₹%.0f\n",bal);
            }
        }
        else if(ch==3){
            printf("Current Balance: ₹%.0f\n",bal);
        }
        else if(ch==4){
            printf("Thank you for banking with us!\n");
        }
        else{
            printf("Invalid choice!\n");
        }
    }while(ch!=4);
    return 0;
}
