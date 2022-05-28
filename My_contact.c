#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void add_contact();
void search_contact();
void delete_contact();
void view_contact();

int main()
{
    printf("\t_____PHONE BOOK_____\n");
    printf("\t1.Add contact.\n");
    printf("\t2.Search contact.\n");
    printf("\t3.Delete contact.\n");
    printf("\t4.View all contact.\n");
    printf("\t5.Exit.\n");
    printf("Choose the option :- ");
    int choose;
    scanf("%d",&choose);
    switch(choose)
    {
        case 1:
            add_contact();
            break;
        case 2:
            search_contact();
            break;
        case 3:
            delete_contact();
            break;
        case 4:
            view_contact();
            break;
        case 5:
            exit(1);
        default:
            main();
    }
}

void add_contact()
{
    FILE *fp;
    fp=fopen("contact.txt","a+");
    printf("\t______ADD CONTACT______");
    printf("\n\tName :-" );
    char name[20];
    scanf("%s",name);
    printf("\n\tMobile number :- ");
    char mob[20];
    scanf("%s",mob);
    fprintf(fp,"%s  %s\n",name,mob);
    fclose(fp);
    printf("\n_______________________________\n");
    main();
}
void search_contact()
{
    FILE *fp;
    fp=fopen("contact.txt","r");
    printf("\t______SEARCH CONTACT______\n");
    printf("\n\tEnter name :- ");
    char name[20];
    char Name[20],mob[20];
    scanf("%s",Name);
    while(fscanf(fp,"%s%s",name,mob)!=EOF)
    {
        if(strcmp(name,Name)==0)
        {
            printf("\n\tName :- %s\n",Name);
            printf("\tMOB No :- %s\n",mob);
        }
    }
    fclose(fp);
    printf("\n____________________________\n");
    main();
}
void delete_contact()
{
    FILE *fp,*_fp_;
    int flag=0;
    fp=fopen("contact.txt","r+");
    long pos = ftell(fp);
    printf("%ld",pos);
    if(fp != NULL){
        fseek(fp, 0, SEEK_SET);
    }
    ftell(fp);
    printf("%ld",pos);
    _fp_=fopen("temp.txt","w");
    printf("\t_____DELETE CONTACT_____");
    printf("\n\tEnter name :- ");
    char name[20];
    char Name[20],mob[20];
    scanf("%s",Name);
    while(fscanf(fp,"%s%s",name,mob)!=EOF)
    {
        printf("Name:%s\n",name);
        printf("Mob:%s\n",mob);
        if(strcmp(Name,name)!=0)
        {
            fprintf(_fp_,"%s    %s\n",name,mob);
        }
        else
        {
            flag=1;
        }
        //fprintf(_fp_,"%s    %s",name,mob);
    }
    if(flag==0)
    {
        printf("%s Not found in the list...\nplease try with valid name.\n\n",Name);
    }
    else
    {
        printf("\n%s delete successfully from the list.\n\n",Name);
    }
    fclose(fp);
    fclose(_fp_);
    fp=fopen("contact.txt","w");
    _fp_=fopen("temp.txt","r");
    while(fscanf(_fp_,"%s%s",name,mob)!=EOF)
    {
        fprintf(fp,"%s  %s\n",name,mob);
    }
    fclose(fp);
    fclose(_fp_);
    remove("temp.txt");
    main();
}

void edit_contact()
{
    FILE *fp;
    fp=fopen("contact.txt","r");
    printf("\t______SEARCH CONTACT______\n");
    printf("\n\tEnter name :- ");
    char name[20];
    char Name[20],mob[20];
    scanf("%s",Name);
    while(fscanf(fp,"%s%s",name,mob)!=EOF)
    {
        if(strcmp(name,Name)==0)
        {
            printf("\n\tName :- %s\n",Name);
            printf("\tMOB No :- %s\n",mob);
        }
    }
    fclose(fp);
    printf("\n____________________________\n");
}
void view_contact()
{
    FILE *fp;
    fp=fopen("contact.txt","r");
    printf("\t_____ALL CONTACT_____");
    char Name[20],mob[20];
    while(fscanf(fp,"%s%s",Name,mob)!=EOF)
    {
        printf("\n\tName :- %s",Name);
        printf("\n\tMOB No. :- %s",mob);
        printf("\n\t________________\n\n");
    }
    fclose(fp);
    printf("\n_____________________________\n");
    main();
}