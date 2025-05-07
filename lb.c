

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
    fclose(fp);
}
void viewbook()
{
    system("cls");
    printf("available books are : \n");
    printf("%-10s %-30s %-20s %s\n","book id","book name","author","date");
    fp=fopen("booklist.txt","rb");
    while(fread(&b,sizeof(b),1,fp)==1)
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
    fprintf(fp,"%s%s%s\n",u.name,u.pass,u.role);
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
   fp = fopen("issue.txt", "ab");

    printf("Enter Student Name: ");
    fflush(stdin);
    gets(s.student_name);

    printf("Enter Student Class: ");
    fflush(stdin);
    gets(s.s_class);

    printf("Enter Student Roll: ");
    scanf("%d", &s.roll);

    printf("Book Issued Successfully\n\n");

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

}
void member_login()
{
    printf("system under development\n\n\n");
}
void view_issuebook()
{

    system("cls");
    printf("<== Book Issue List ==>\n\n");

    printf("%-10s %-30s %-20s %-10s %-30s %s\n\n", "S.id", "Name", "Class", "Roll", "Book Name", "Date");

    fp = fopen("issue.txt", "rb");
    while(fread(&s, sizeof(s), 1, fp) == 1){
        printf("%-10d %-30s %-20s %-10d %-30s %s\n", s.id, s.student_name, s.s_class, s.roll, s.bookname, s.date);
    }

    fclose(fp);
}

void del(){
    int id, f=0;
    system("cls");
    printf("Enter Book id to remove: ");
    scanf("%d", &id);

    FILE *ft;

    fp = fopen("booklist.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while(fread(&b, sizeof(b), 1, fp) == 1){
        if(id == b.id){
            f=1;
        }else{
            fwrite(&b, sizeof(b), 1, ft);
        }
    }

    if(f==1){
        printf("\n\nDeleted Successfully.");
    }else{
        printf("\n\nRecord Not Found !");
    }

    fclose(fp);
    fclose(ft);

    remove("booklist.txt");
    rename("temp.txt", "booklist.txt");

}
void searchbook() {
    int choice, id, found = 0;
    char name[100];
    system("cls");
    printf("Search Book By:\n");
    printf("1. Book ID\n");
    printf("2. Book Name\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    fp = fopen("booklist.txt", "rb");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    if (choice == 1) {
        printf("Enter Book ID to search: ");
        scanf("%d", &id);
        while (fread(&b, sizeof(b), 1, fp) == 1) {
            if (b.id == id) {
                printf("Book Found:\nID: %d\nName: %s\nAuthor: %s\nDate: %s\n", b.id, b.book_name, b.author_name, b.date);
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        printf("Enter Book Name to search: ");
        fflush(stdin);
        gets(name);
        while (fread(&b, sizeof(b), 1, fp) == 1) {
            if (strcmp(b.book_name, name) == 0) {
                printf("Book Found:\nID: %d\nName: %s\nAuthor: %s\nDate: %s\n", b.id, b.book_name, b.author_name, b.date);
                found = 1;
                break;
            }
        }
    } else {
        printf("Invalid choice.\n");
    }

    if (!found) {
        printf("Book not found.\n");
    }

    fclose(fp);
}
void returnbook() {
   printf("system under development\n\n\n");
}

void payfine()
{
    printf("system ujnder development\n\n\n");
}

int main()
{
    int choice,num;
    int issue;
    int man;
    printf("      LIBRARY MANAGEMENT SYSTEM    \n");
    while(1){
    printf("\n\n Modules of my  projects \n");
         printf("---------------------------------\n");
         printf("1.Member management\n ");
         printf("  a)member registration\n");
         printf("  b)member login\n");
         printf("2. Add book\n ");
         printf("3. View book\n");
         printf("4. Issue book Management\n ");
         printf("  a) Issue book\n");
         printf("   b)view issue book\n");
         printf("5.Search Book\n");
         printf("6.Delete book\n");
        printf("7.Pay Fine\n");
        printf("8. Return book \n");
        printf("9.Book Cataloging\n");
        printf("0. Exit\n");


    printf("Enter your choice\n");
    scanf("%d",&choice);
     switch(choice)
     { case 1:
         printf("you choose member management\n");
         printf("enter 1 for registration and 2 for login\n");
         scanf("%d",&man);
         switch(man)
         {
             case 1: printf("you choose member registration\n\n");
             member_reg();
             break;
             case 2: printf("you choose member login\n\n");
             member_login();
             break;
         }

     case 0:
        printf("you choose exit from the system");
        break;
     case 2:
         printf("you choose add book \n");
         addbook();
         break;
     case 3:
        printf("you choose view book \n");
        viewbook();
        break;
     case 4:
        printf("you choose issue book management : \n");
        printf(" enter 1 to issue book and 2 to view issue book : \n");
        scanf("%d",&issue);
        switch(issue)
        {
            case 1: printf("you choose issue book \n\n");
            issuebook();
            break;
            case 2: printf("you choose view issue book\n\n");
            view_issuebook();
            break;
        }
        break;
        case 5: printf("you choose search book\n");
        searchbook();
        break;
        case 6: printf("you choose delete book\n");
        del();
        break;
        case 7: printf("you choose pay fine\n\n\n");
        payfine();
        break;
        case 8: printf("you choose return book\n");
    returnbook();
    break;

     }
    }


    return 0;
}
