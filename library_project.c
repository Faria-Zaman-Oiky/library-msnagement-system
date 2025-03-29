
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
void opennwacc()
{
    printf("\n\n Input details of customer\n");

}
struct User{
    char name[20];
    char pass[10];
    char role[10];


};
struct student{
    int id;
    char student_name[100];
    char s_class[50];
    int roll;
    char bookname[100];
    char date[12];
}s;

struct books
{
    int id;
    char book_name[100];
    char author_name[100];
    char date[12];

}b;
FILE *fp;
void addbook()
{
    char mydate[12];
    time_t t=time(NULL);
    struct tm tm=*localtime(&t);
    sprintf(mydate,"%02d/%02d/%d",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
    strcpy(b.date,mydate);
    fp=fopen("booklist.txt","a");
    printf("enter book id: \n");
    scanf("%d",&b.id);
    printf("Enter BOOK NAME : \n");
    fflush(stdin);
    gets(b.book_name);
    printf("Enter author name: \n");
    fflush(stdin);
    gets(b.author_name);
    fwrite(&b,sizeof(b),1,fp);
    //fprintf(fp,"%d %s %s %s", b.id, b.book_name, b.author_name, b.date);
    //fprintf(fp,"\n");


    fclose(fp);
}
void viewbook()
{
    system("cls");
    printf("available books are : \n");
    printf("%-10s %-30s %-20s %s\n","book id","book name","author","date");
    fp=fopen("booklist.txt","rb");
    while(fread(&b,sizeof(b),1,fp)==1)
    //while ( fscanf(fp,"%d %[^\n] %[^\n] %[^\n]",&b.id,b.book_name,b.author_name,b.date)==4)
   {
              printf("%-10d %-30s %-20s %s ",b.id,b.book_name,b.author_name,b.date);
              printf("\n");
          }
          fclose(fp);
}


void member_reg()
{
   struct User u;
    FILE *fp=fopen("users.txt","ab");
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
void issuebook()
{
    char mydate[12];
    time_t t=time(NULL);
    struct tm tm=*localtime(&t);
    sprintf(mydate,"%2d/%2d/%d",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
    strcpy(s.date,mydate);
    int f=0;
    system("cls");
   printf("enter book id you want to issue : ");
   scanf("%d",&s.id);
   fp=fopen("booklist.txt","rb");
   while(fread(&b,sizeof(b),1,fp)==1)
   //while ( fscanf(fp,"%d %[^\n] %[^\n] %[^\n]",&b.id,b.book_name,b.author_name,b.date)==4)
{
       if(b.id==s.id)
       {
           strcpy(s.bookname,b.book_name);
           f=1;
           printf("%s book issued successfully ",s.bookname);
       }
   }
   if(f==0)
   {
       printf("book is not found");
   }
}
int main()
{
    int choice,num;
    while(1){
    printf("\n\n Modules of my  projects \n");
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
     { case 1:
         member_reg();
        break;
     case 0:
        printf("you choose exit from the system");
        break;
     case 5:
         printf("you choose add book \n");
         addbook();
         break;
     case 6:
        printf("you choose view book \n");
        viewbook();
        break;
     case 7:
        printf("you choose issue book : \n");
        issuebook();
        break;
     }
    }
    return 0;
}
