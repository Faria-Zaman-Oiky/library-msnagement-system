#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void opennwacc()
{
    printf("\n\n Input details of customer\n");

}
struct User{
    char name[20];
    char pass[10];
    char role[10];

};
void member_reg()
{
   struct User u;
    FILE *fp=fopen("users.txt","a");
    printf("enter name : \n");
    scanf("%s",u.name);
    printf("enter password : \n");
    scanf("%s",u.pass);
    printf("enter role: \n");
    scanf("%s",u.role);
    fprintf(fp,"%s%s%s\n",u.name,u.pass,u.role);;
    fclose(fp);
    printf("user registered successfully\n");
}
int main()
{
    int choice,num;
    while(1){
    printf("\n\n Modules of your projects \n");
         printf("---------------------------------\n");
         printf("1.Member Registration\n ");
         printf("2. Admin management\n ");
         printf("3. User Management\n");
         printf("4. Book Cataloging\n ");
         printf("5.Add books\n");
         printf("6.View Books\n");
        printf("7.Issue book\n");
        printf("8. Return Book \n");
        printf("9.Pay fine\n");
        printf("10.View  Issued book\n");
        printf("0. Exit\n");


    printf("Enter your choice\n");
    scanf("%d",&choice);
     switch(choice)
     {
     case 1:
        printf("\n\n You choose - Member registration\n\n");
        member_reg();
        break;
     case 0:
        printf("you choose exit from the system");
        break;
    return 0;
     }
    }

}
