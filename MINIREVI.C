#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
void add(void);
void list(void);
void personal(void);
void deletea(void);
int dis(void);
int prompt(void);
void modify(void);
int clientfun(void);
typedef struct client
 {
    int sno;
    char nomineename[20];
    char fundscheme [20];
    char foliono[12];
    char dateofinv[10];
    char amount[10];
    char netasset[10];
    char currentnav[10];
    struct client *next;
    int count;
    } Client;

Client *head,*tail,*newc;

    char name[20];
    char phone[15];
    char email[20];
    char dob[20];
int main  ()
{
int a;
 clrscr();
	printf("\n------------------------------------------------------------------------------\n");
	printf("\t\t\t\tWelcome !!!\n");
	printf("--------------------------------------------------------------------------------\n");

printf("\nEnter your password if your a  Distributor  and if you are a client please click any number to continue\n\n") ;
scanf("%d",&a);
if(a==1234)
{
printf("\nHey Distributor\n");
dis();
exit(0);
}
else
{
printf("\nHey client\n ") ;
clientfun();


}
getch();
return 0;
  }
int dis(void)
{
    FILE *datafile;
    char filename[10];
    char ch;
    head = NULL;
     printf("\nEnter the clients name with extension.txt to open the clients file\n \n");
    scanf("%s",filename);
    datafile = fopen(filename,"r");

    if(datafile)
    {
	    head = (struct client *)malloc(sizeof(struct client));
       tail = head;
	    while(1)
		{
		    newc = (struct client *)malloc(sizeof(struct client));
		    fread(tail,sizeof(struct client),1,datafile);
		    if(tail->next == NULL)
		       break;
		    tail->next =newc;
		    tail->count=0;
		    tail =newc;
	    }
	    fclose(datafile);


    }

    do
    {
	fflush(stdin);
	printf("\n--------------------------------------------------------------------------\n");
	printf("\t\tWelcome To The Mutual Fund distributor record\n");
	printf("--------------------------------------------------------------------------\n");

	printf("\t\t\t\t 1 -Personal details \n");
	printf("\t\t\t\t 2 - Add details \n");
	printf("\t\t\t\t 3 -List details \n");
	printf("\t\t\t\t 4 -Delete details \n");
	printf("\t\t\t\t 5 -Modify details \n");
	printf("\t\t\t\t 6- Save and Quit\n");
	printf("\tYour choice:");
	ch = getchar();
      switch(ch)     /*stores in ch variable.*/
	{
	     case '1':

		       fflush(stdin);
			personal();
		      break;
	     case '2':
	       fflush(stdin);
		add();
		break;

	    case '3':

		      list();
		      break;
	    case '4':

		      deletea();
		      break;
	    case '5':

		    modify();
		      break;
	    case '6':
	    default:
		break;
	}
    }
    while(ch != '6');

    tail = head;

    if(tail == NULL)
	    return(0);

    datafile = fopen(filename,"w");

    if(datafile == NULL)
    {
	    printf("Error writing to %s\n",filename);
	    return(1);
    }

    while(tail != NULL)
    {
	    fwrite(tail,sizeof(struct client),1,datafile);
	    tail = tail->next;
 }
    fclose(datafile);
    getch();
    return(0);
}
void personal(void)
{
    printf("\n Enter Your Name  ");
    scanf("%s",&name);
    printf("\nEnter Your Phone Number");
    scanf("%s",&phone);
    printf("\nEnter Your  Email Address");
     scanf("%s",&email);
    printf("\nEnter Your Date Of Birth");
    scanf("%s",&dob);
}
void add(void)
{
    newc = (struct client *)malloc(sizeof(struct client));

    if(head==NULL)
	head = tail = newc;

    else
    {
	tail = head;

	while(tail->next != NULL)tail = tail->next;
	tail->next = newc;
	tail = newc;
    }
   printf("\nEnter Sno.");
   scanf("%d",&tail->sno) ;
    printf(" \nEnter  Nominee Name: ");
    scanf("%s",tail->nomineename);
    printf("\nEnter Fund Scheme  ");
   scanf("%s",tail->fundscheme);
     printf("\nEnter Folio No  ");
    scanf("%s", tail->foliono);
     printf("\nEnter Date of Investment  ");
    scanf("%s",tail->dateofinv);
	  printf("\nEnter  Amount   ");
   scanf("%s",tail->amount);
     printf("\nEnter  Net Asset Value (NAV)  ");
    scanf("%s",tail->netasset);
    printf("\nEnter Current NAV  ");
    scanf("%s",tail->currentnav);
    printf("\ninvestment added!");
    tail->count=0;
    tail->next = NULL;
}
 void list(void)
{
    if(head==NULL)
	puts("There are no records to display!");

    else
    {        printf("NAME %s \n PHONE %s \n EMAIL %s \n DATE OF BIRTH %s \n",name,phone,email,dob);
	      printf("\n\n SNO.  FOLIO NO.   NOMINEE NAME   FUND SCHEME  DOI  NAV   CNAV   AMOUNT ");
	      printf("\n-------------------------------------------------------------------------------\n");

	tail=head;

	do
	{

		printf("%d\t %s\t %s\t %s\t %s\t %s\t  %s\t %s\t \n",tail->sno,
		tail->foliono,  \
		tail->nomineename,\
		tail->fundscheme,  \
		tail->dateofinv,    \
		tail->netasset,     \
		tail->currentnav,    \
		tail->amount);

	}

	while((tail=tail->next) != NULL);
    }
}
void deletea(void)
{
    int record;
    struct client *previous;
    if(head==NULL)
    {
	printf("There are no contacts to delete!");
	return;
    }
      printf("Enter investment number to delete: ");
    scanf("%d",&record);
    tail = head;

    while(tail != NULL)
    {
	if(tail->sno == record)
	{
	    if(tail == head)
		head=tail->next;
	    else
		previous->next = tail->next;

	free(tail);
	    printf("Investment%d deleted!\n",record);
	    return;
	}

	else
	{
	previous = tail;
	    tail = tail->next;
	}
    }
    printf("investment %d not found!\n",record);
 }
 void modify(void)
{
    int record;
    if(head==NULL)
    {
	printf("There are no investemnts to modify!");
	return;
    }


    printf("Enter investment number to modify or change: ");
    scanf("%d",&record);

   tail = head;

    while(tail != NULL)
    {
    if( tail->sno==record  )
    {
	    printf("Sno. %d:\n",tail->sno);
	    printf("Folio no: %s\n", tail->foliono);
	     if(prompt())
		    gets(tail->foliono);
	    printf("Nominee Name: %s\n",tail->nomineename);
	    if(prompt())
		    gets(tail->nomineename);
	    printf("Fund scheme: %s\n",tail->fundscheme);
	    if(prompt())
		    gets(tail->fundscheme);

		       printf("Date Of Investment: %s\n",tail->dateofinv);
	    if(prompt())
		    gets(tail->dateofinv);
		      printf("Net asset Value: %s\n",tail->netasset);
	    if(prompt())
		    gets(tail->netasset);
		      printf("Current nav: %s\n",tail->currentnav);
	    if(prompt())
		    gets(tail->currentnav);
		      printf("Amount: %s\n",tail->amount);
	    if(prompt())
		    gets(tail->amount);
	 return;
		}
			else
	{
	    tail = tail->next;
	}
    }

    printf("investment %d was not found!\n",record);
}
int prompt(void)
{
	char ch;
    fflush(stdin);
	printf("Update? (Y to update any other key to not)");
	ch = getchar();
	ch = toupper(ch);
	fflush(stdin);
	if(ch == 'Y')
	{
		printf("Enter new value: ");
		return(1);
	}
	else
		return(0);
}

 int clientfun(void)
 {

 FILE *datafile;
    char filename[10];
    char ch;
    head = NULL;
      printf("\n--------------------------------------------------------------------------\n");
	printf("\t\t\t\tWelcome client  !!!\n");
	printf("--------------------------------------------------------------------------\n");

     printf("Enter you name with the extention txt to open the  file \n");
    scanf("%s",filename);
    datafile = fopen(filename,"r");

    if(datafile)
    {
	    head = (struct client *)malloc(sizeof(struct client));
	    tail = head;
	    while(1)
		    {
		    newc = (struct client *)malloc(sizeof(struct client));
		    fread(tail,sizeof(struct client),1,datafile);
		    if(tail->next == NULL)
			    break;
		    tail->next = newc;
	    tail->count=0;
		    tail = newc;
	    }
	    fclose(datafile);


    }

     printf("\n--------------------------------------------------------------------------\n");
	printf("\t\t\tYour Investment's Are:   !!!\n");
	printf("--------------------------------------------------------------------------\n");

 if(head==NULL)
	puts("There are no records to display!");

    else
    {
	      printf("\n\n SNO.  FOLIO NO .   NOMINEE NAME   FUND SCHEME  DOI  NAV    CNAV   AMOUNT ");
	      printf("\n-------------------------------------------------------------------------------\n");

	tail=head;

	do
	{
	printf("%d\t %s\t %s\t %s\t %s\t %s\t   %s\t  %s\t  \n",tail->sno,
		tail->foliono,  \
		tail->nomineename,\
		tail->fundscheme,  \
		tail->dateofinv,    \
		tail->netasset,     \
		tail->currentnav,    \
		tail->amount);

	}

	while((tail=tail->next) != NULL);
    }

   getch();
   return 0;

    }














