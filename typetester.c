#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<unistd.h>
#define reset "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
typedef struct
   {
         int entries[100];
         double time[100];
         double wpm1[100];
   }WPM;
struct NET_WPM
   {
         int errors[100];
         double net_wpm1[100];
   };
typedef struct 
   {
         WPM wpm;
         struct NET_WPM net_wpm;
         double accuracy[100];
   }CALCULATOR;
CALCULATOR calculation1;
typedef struct
{
    char sno[100][2];
    char name[100][33];
    char wpm[100][3];
    char accuracy[100][3];
    char speed[100][3];
}score;
score s;
FILE *fp;
double Gross_WPM,Net_WPM,Accuracy;
char names[33];
void Calculator(int entries,int errors,double time);
void insert(score s,int);
int main()
{
    int x=0,y=0,k=0,a=0,b=0,count=0;
    FILE *pfp;
    fp=fopen("D:\\Notepad++\\Typing_Test.txt","a+");
    if((fp)==NULL)
       {
        printf("This file can not be opened.");
        return 0;
       }
    printf("Shivnaran S(22PD32) and Sujan S(22PD35) heartly welcome you to a typing test\n");
    printf("Plese enter your name:");
    do
    {
     count=0;
     for(x=0;x<25;x++)
       {
         names[x]=getch();
         if(names[x]=='\r')
            {
                break;
            }
         if((((names[x])>=65 && names[x]<=90) || ((names[x])>=97 && names[x]<=122))|| (names[x]== '.') || (names[x]==' '))
            {
              putch(names[x]);
              count=count+1;
              continue;
            }
         else
            {
                printf("\nYour name should not contain special characters other than blank space and dot and alphabets\n");
                printf("Enter the character again:");
                --x;
            }
        }
       
    }while(count==0);
    names[x]='\0';
    printf("\nName:%s",names);
    printf("\nStart typing as soon as the text appears before you.\nUntil then please wait with patience.");
    printf("\nWhen the character typed by you is incorrect it will be shown in red else if it is correct it will be displayed in green.\nYou may correct your errors using backspace key only not forward and backward arrow key.");
    printf("\n\n");
    srand(time(0));
    b=(rand()%(5+1))+0;
    switch (b)
    {
        case 0: if((pfp=fopen("D:\\Notepad++\\Typing_Test0.txt","r"))==NULL)
                    {
                        printf("This file can not be opened.");
                        return 0;
                    }
                break;
        case 1: if((pfp=fopen("D:\\Notepad++\\Typing_Test1.txt","r"))==NULL)
                    {
                        printf("This file can not be opened.");
                        return 0;
                    }
                break;
        case 2: if((pfp=fopen("D:\\Notepad++\\Typing_Test2.txt","r"))==NULL)
                    {
                        printf("This file can not be opened.");
                        return 0;
                    }
                break;
        case 3: if((pfp=fopen("D:\\Notepad++\\Typing_Test3.txt","r"))==NULL)
                    {
                        printf("This file can not be opened.");
                        return 0;
                    }
                break;
        case 4: if((pfp=fopen("D:\\Notepad++\\Typing_Test4.txt","r"))==NULL)
                    {
                        printf("This file can not be opened.");
                        return 0;
                    }
                break;
        case 5: if((pfp=fopen("D:\\Notepad++\\Typing_Test5.txt","r"))==NULL)
                    {
                        printf("This file can not be opened.");
                        return 0;
                    }
                break;
        default:if((pfp=fopen("D:\\Notepad++\\Chemistry doubts.txt","r"))==NULL)
                    {
                        printf("This file can not be opened.");
                        return 0;
                    }
                break;
    }
    char p[10000],t[10000];
    time_t time;
    fscanf(pfp,"%[^EOF]",p);
    fseek(pfp,0,SEEK_END);
    y=ftell(pfp);
    //sleep(20);
    printf("%s",p);
    printf("\n");
    time=clock();
    for(x=0;x<y;x++)
       {
         t[x]=getch();
         if(t[x]=='\b')
            {
               putch(t[x]);
               putch(' '); 
               putch(t[x]);
               x=x-2;
            }
         else
            {  
               if(p[x]==t[x])
                  printf(GRN "%c" reset,t[x] );
               else 
                  printf(RED "%c" reset,t[x]);
            }
       }
    time=clock()-time;
    double time_taken=(double)((time)/(CLOCKS_PER_SEC))/60;
    for(x=0;x<y;x++)
       {
         if(t[x]!=p[x])
            k++;
       }
    Calculator(y,k,time_taken);
    fseek(fp,0,SEEK_SET);
    int i=0,j=0;
    for(i=0;i<100;i++)
       {
            if(getc(fp)==EOF)
               {
                    --i;
                    break;
               }
            else   
               { 
                    fseek(fp,129+j,SEEK_SET);
                    fscanf(fp,"%[^ ]",s.sno[i]);
                    fseek(fp,2,SEEK_CUR);
                    fscanf(fp,"%[^0123456789]25",s.name[i]);
                    fscanf(fp,"%[^ ]",s.wpm[i]);
                    fseek(fp,14,SEEK_CUR);
                    fscanf(fp,"%[^ ]",s.accuracy[i]);
                    fseek(fp,11,SEEK_CUR);
                    fscanf(fp,"%[^ ]",s.speed[i]);
               }
            j=j+75;
       }
    int op_num=1;
    printf("\nEnter the corresponding number for a function to perform that particular function.\n");
    printf("1.Insert\n2.Exit\n");
    scanf("%d",&op_num);
    while(1)
       {
        if((op_num!=1) && (op_num!=2))
           {
            printf("The option entered by you must be either 1 or 2.But it is not so.\nSo enter a correct option number again:");
            scanf("%d",&op_num);
           }
        else
            break;
       }
   switch(op_num)
          {
              case 1:   insert(s,i);
                        break;
              case 2:   break;
          }
    fclose(fp);
    fclose(pfp);
    return 0;
}
void Calculator(int entries,int errors,double time)
{
   int i=0,j=0,k=0;
   calculation1.wpm.entries[i]=entries;
   calculation1.net_wpm.errors[i]=errors;
   calculation1.wpm.time[i]=time;
   calculation1.wpm.wpm1[i]=entries/(5*time);
   Gross_WPM=calculation1.wpm.wpm1[i];
   calculation1.net_wpm.net_wpm1[i]=Gross_WPM-(errors)/time;
   Net_WPM=calculation1.net_wpm.net_wpm1[i];
   printf("\nYou have made %d errors",calculation1.net_wpm.errors[i]);
   printf("\nThe total number of characters entered by you is :%d",calculation1.wpm.entries[i]);
   printf("\nYou have taken %lf minutes to complete typing the text.",calculation1.wpm.time[i]);
   calculation1.accuracy[i]=(((Net_WPM*100)/Gross_WPM));
   Accuracy=calculation1.accuracy[i];
   printf("\nYour accuracy is:%.0lf%% and the number of words typed per minute is:%.0lf",Accuracy,Gross_WPM);
   printf("\nTHANK YOU.\nPlease give the laptop to the coders.");
}
void insert(score s,int i)
{
    char serial[2];
    (int) Gross_WPM;
    (int) Net_WPM;
    (int) Accuracy;
    int a,b,c;
    a=Gross_WPM;
    b=Accuracy;
    c=Gross_WPM*(Accuracy/100);
    sprintf(s.sno[i], "%d",i+1);
    sprintf(s.wpm[i], "%d",a);
    sprintf(s.accuracy[i], "%d",b);
    sprintf(s.speed[i], "%d",c);
    strcpy((s.name[i]),(names));
    fseek(fp,(75*3)+128,SEEK_SET);
    if(b<100 && b>=10)
       {
         fprintf(fp,"\n %2s  %-33s%2s              %-s            %2s ",s.sno[i],s.name[i],s.wpm[i],s.accuracy[i],s.speed[i]);
       }
    else if(b=100)
         fprintf(fp,"\n %2s  %-33s%2s              %3s           %2s    ",s.sno[i],s.name[i],s.wpm[i],s.accuracy[i],s.speed[i]);
    else
         fprintf(fp,"\n %2s  %-33s%2s              %-s             %2s ",s.sno[i],s.name[i],s.wpm[i],s.accuracy[i],s.speed[i]);
    
}