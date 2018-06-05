/*
WORK IT OUT::
1. on entering string ticket id in search block infinite loop for no match results.
*/
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <time.h>

int authorise(int);
int n;

struct ticket
{
 int id;
 char name[50];
 char dest[10];     //destination.
 int age;
 };

//authorised login
 int authorise(int a)
 {
  char uid[20];
  int pass;
 
  while(1)
  {
  printf("\nEnter the given user id");
  scanf("%s",uid);
  printf("\n Enter the captcha code shown on the screen");
  scanf("%d",&pass);
 
  //checking....
  
  if((strcmp(uid,"train@sp")==0)&&(pass==a))
   {
    printf("\nWELCOME USER");
    return 0;
   }
   else
    {
     printf("\n!!!! uid or password is incorrect\a");
     
     }

  }
}


int main()
{	
int i;
 char home[10];
 int choice,search,captcha;
 srand(time(NULL));
 captcha=rand()%3276;  

 printf("captcha code=%d\n",captcha);   //printing auto gen pass

 authorise(captcha);

 printf("\n|||||||||||||||||||||||||\n| WELCOME ABOARD        |\n|||||||||||||||||||||||||\n");
 printf("\nPlease enter the number of passengers");
 scanf("%d",&n);

 printf("enter the details:\nfollowing is a destination guide:\nDESTINATION CODES=\n1.Chandigarh=CHD\n2.Mumbai=MBI\n3.Delhi=DEL\n4.Agra=AGR\n5.Varanasi=VRN");
 
struct ticket ticket[n];

//taking  entries

for(i=0;i<n;i++)
{
ticket[i].id=rand();
  printf("\nEnter the name and age of the passenger %d\n",i+1);
  scanf("%s%d",ticket[i].name,&ticket[i].age);
 }
 
 //enter and CROSSCHECKING destination
 for(i=0;i<n;i++)
 {
   while(1)
   {  
      printf("enter the destination of %dth passenger",i+1);
      scanf("%s",ticket[i].dest);
      
      //needs improvisation(don't panic it runs fine.)
      if(strcmp(ticket[i].dest,"CHD")==0||strcmp(ticket[i].dest,"DEL")==0||strcmp(ticket[i].dest,"AGR")==0||strcmp(ticket[i].dest,"MBI")==0||strcmp(ticket[i].dest,"VRN")==0)
      {  
        printf("\nthank you!!!your entry has been recorded.\n");
        break;
      }
     else 
        printf("\n\a!!ERROR!!please enter a valid destination code\n");
   }
  
  } 
 
 // printing individual ticket IDs

 for(i=0;i<n;i++)
 {
  printf("\nPlease note down your ticket IDs for further enquiry:\npassenger name=%s\tticket ID=%d",ticket[i].name,ticket[i].id);
 }
 while(1)
{
  printf("\nTHANK YOU\n for enquiry press 1 else to exit press 2.\n");
  scanf("%d",&choice);
  
  //searching ticket
  
  if(choice==1)
   {
       
         printf("\nPlease enter the ticket id alloted to the passenger");
         scanf("%d",&search);
         
         for(i=0;i<n;i++)
         {
           if(search==ticket[i].id)
           {
             printf("\nMATCH FOUND\nid-%d\nname-%s\ndestination-%s\nage-%d",ticket[i].id,ticket[i].name,ticket[i].dest,ticket[i].age);
             break;
           }
         }
        if(i==n)
          printf("\n\a!!!NO MATCH FOUND\n Please enter a valid id");
       
   }
   
 
   else if(choice==2)  exit(0);
 }
}
