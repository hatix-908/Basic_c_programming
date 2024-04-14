#include<stdio.h>
#include<stdlib.h>
struct expenditure
{
    char name[20];
    float paid,balance;
};
struct expenditure disp(struct expenditure a[],int s,float t);
int main()
{
    int s;
    float total;
    char ch;
    printf("Enter the number of students :");
    scanf("%d",&s);
    printf("\nEnter the expenses per head :");
    scanf("%f",&total);
    printf("\n=================================\n"); 
    struct expenditure a[s];
    for (int i = 0; i < s; i++)
    {
        printf("Enter the name of the student :");
        scanf("%s",a[i].name);
        printf("\nEnter the amount paid :");
        scanf("%f",&a[i].paid);
        a[i].balance=total-a[i].paid;
        printf("\n-----------------------------\n");
    }
    printf("\n===================================\n");
    printf("Data recorded successfully!\n Do you wish to print the results ?\n enter Y to confirm or N to cancel :");
    scanf(" %c",&ch);
        switch (ch)
        {
        case 'y':
        case 'Y':disp(a,s,total);
            break;
            case 'n':
        case 'N':exit(0);
            break;
        
        default: printf("\n!!!invalid choice!!!");
            break;
        }
}
struct expenditure disp(struct expenditure a[],int s,float t)
{
    printf("\n=====================EXPENDITURE-RECORD========================\n");
      for (int i = 0; i < s; ++i) 
      {
        printf("candidate %d\n Name: %s\t| ",i+1,a[i].name);
        printf("Paid: %.2f\t|", a[i].paid);
        if(a[i].paid<=t)
        {
            printf("\tBalance: %.2f\n--------------------------------------------------\n",a[i].balance);
        }
        else
        {
            printf("\tBalance: ! OVERPAID by-> %.2f\n--------------------------------------------------\n",a[i].balance/-1.00);
        }
      }
}
