 #include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

char unique[11]; 
                                                                                                            
struct customer
{
	char ph[11];
	char na[20];
	char ge[7];
	char st[10];
	char ci[10];
	char pl[2];
	char passW[20];
	char cp[2];
	int d;
	int y;
	int m;
	int hr;
	int min;
	int sec;
}s;


struct date
{
	int years;
	int months;
	int days;
};



struct employee
{
char phonenumber[11];
char name[20];
char ge[7];
char id[7];
char pword[20];
}u;


void signup();
void login();
void dashboard();
void profile();
void randomPasswordGeneration();
int faq();
void change_plan();
void change_password();
int diff();
void plan_expire();
void forgot_pass();

void employee_login();

int main()
{
	char choice;
	system("cls");

	printf("\n\n\n\n\n\n\n\n\n**************************************************************");
	printf("\n\t\t------WELCOME TO THE TELECOM BILLING MANAGEMENT SYSTEM----");
	printf("\n\t\t****************************************************************");
	Sleep(2000);
	getch();
        system("cls");
	while (1)
	{
		system("cls");
		printf("\n\n\n\n\n\n\t\t\t\t\t\t************************* CHOOSE *************************");
		printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tA :USER  SIGNUP");
		printf("\n\t\t\t\t\t\t\t\tB :USER LOGIN");
		printf("\n\t\t\t\t\t\t\t\tC :EMPLOYEE LOGIN");

		printf("\n\t\t\t\t\t\t\t\tE: EXIT\n");
		
		choice=getche();
		choice=toupper(choice);
		switch(choice)
		{
			case 'A':
				signup();
				break;
			case 'B':
				login();
				break;
			case 'C':
				employee_login();
				break;

			case 'E':
				system("cls");

				printf("\t\t\t\tTHANK YOU FOR USING OUR SERVICE");
				Sleep(2000);
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\nAny key to continue");
				getch();
		}
	}
}


//########################################################################################################################################################


void signup()
{
	FILE *f;
	char ph[11];
	char test,pag ,o[10];
	f=fopen("cusrecord","ab+");
	if(f==0)
	{   f=fopen("c:/file.ojs","wb+");
		system("cls");
		
		printf("please wait while we configure your computer");
		printf("/npress any key to continue");
		getch();
	}
        while(1)
	{
		char  *n;
		char a;	
		int flag=1;	

		system("cls");
		printf("\n Enter phone number:");
		scanf("%s",&o);
		fflush(stdin);
    
		while(fread(&s,sizeof(s),1,f)!=0)
		{
		if(strcmp(s.ph,o)==0)
	   	{	
			system("cls");
			printf("\n\n\n\n\n\n\t\t\t\t\t\t\tENTERED PHONE NUMBER ALREADY EXIST ");
			flag=0;
			Sleep(3000);
			main();
			
	   	}    
	}	
	    if(flag==1)
	    {	
	
		strcpy(s.ph,o);
		
		printf("\n Enter name:");
		fflush(stdin);
		scanf("%[^\n]s",&s.na);
		
		printf("\n Enter your  gender:");
		fflush(stdin);
		scanf("%s",&s.ge);

		
		printf("\n Enter your state:");
		scanf("%s",&s.st);
		
		printf("\n Enter your city:");
		scanf("%s",&s.ci);
		fflush(stdin);
		
		int i=0;
		while(i==0)
		{
			printf("1: 599 PLAN \n 2: 799 PLAN  \n 3:999 PLAN \n 4: 1299 PLAN \n ");		
			printf("ENTER YOUR PLAN NUMBER  :\n");
		
			fflush(stdin);
			a=getche();
		
		
			switch(a)
			{	
				case '1':
					n="1";
					printf("\n YOU HAVE CHOOSEN PLAN 1 , Rs 599 /mo ");
					Sleep(3000);
					i=8;
					break;
				
				
				case '2':
					n="2";
					printf("\n YOU HAVE CHOOSEN PLAN 2 , Rs 799 /mo");
					Sleep(3000);
					i=8;
					break;
			
				case '3':
					n="3";
					printf("\n YOU HAVE CHOOSEN PLAN 3 , Rs 999 /mo");
					Sleep(3000);
					i=8;
					break;
			
				case '4':
					n="4";
					printf("\n YOU HAVE CHOOSEN PLAN 4 , Rs 1299 /mo");	
					Sleep(3000);
					i=8;
					break;
			
				default:
					printf("\n Incorrect Input \n");
					printf("\n ENTER Any key to continue  \n");
					getch();	
			}
		
			strcpy(s.pl,n);
		                                                                                                                                               

		}
		randomPasswordGeneration();
		printf("\n\n\nCONGRATULATIONS **** %s **** YOUR ACCOUNT IS SUCCESSFULLY CREATED ",s.na);
		printf("\n\n\nYOUR ACCOUNT **** USER ID **** is : %s",s.ph);
		printf("\n\n\nYOUR PASSWORD IS : %s",s.passW);
		
		// #################################################
		time_t t;
		t=time(NULL); 
		struct tm tm=*localtime(&t);
		int d,m,y,min,sec,hr;			

		s.d=tm.tm_mday;
		s.m=tm.tm_mon+1;
		s.y=tm.tm_year+1900;
		s.hr=tm.tm_hour;
		s.min=tm.tm_min;
		s.sec=tm.tm_sec;
		
		fwrite(&s,sizeof(s),1,f);
		fclose(f);
		
		printf("\n\n Press any key to exit");
		test=getche();
		if(test!=27){
			break;  }
	}	
   }
}


//########################################################################################################################################################

void login()
{
	FILE *f;
	char phonenumber[20];
	char paswor[8];
	int flag=1;
	f=fopen("cusrecord","rb+");
	if(f==0)
	{
		system("cls");
		printf("\n\n\n NO USER FOUND \n\nPLEASE SIGNUP TO CONTINUE");
		Sleep(3000);
		signup();
        }
	
	fflush(stdin);
	system("cls");
	printf("\n\n\n\n\t\t\t\tEnter Phone Number / USER ID :\n");
	scanf("%s", phonenumber);
	strcpy(unique,phonenumber);
	fflush(stdin);
	printf("\n\n\n\n\t\t\t\tEnter your PASSWORD :\n");
	scanf("%s", paswor);
	fflush(stdin);
	         
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.ph,phonenumber)==0)
		{	
			if(strcmp(s.passW,paswor)==0)
			{	
				system("cls");
				dashboard();
				flag=0;
				break;  
			}
			else
			{   
				system("cls");
				printf("\n\n\n\n************* YOUR PASSWORD IS INCORRECT *************");
				printf("\nAny key to continue");				
			}   
		}
		else if(flag==1)
		{	system("cls");
			printf("\n\n\n\nRequested Phone Number Not found in our database");
			
		}
	}
	getch();
	fclose(f);
}

//########################################################################################################################################################

void dashboard()
{
    system("cls");
    char choice;
    system("cls");
    printf("\n\t\t\t\t\tDASHBOARD\n");
    printf("\n TO ACCESS THE OPTIONS MENTIONED BELOW, PRESS THE NUMBER SPECIFIED BESIDE IT\n");
    printf("\nA: Profile\n");
    printf("\nB: Change Password\n");
    printf("\nC: Change Plan\n");
    printf("\nD: FAQ\n");
    printf("\nE: Exit\n");



    FILE *f;
    f=fopen("cusrecord","ab+");
	
	//####################################
		
	time_t t;
	t=time(NULL); 
	struct tm tm=*localtime(&t);
	
	int min2=tm.tm_min;
	int hr2=tm.tm_hour;
	int sec2=tm.tm_sec;
	
	int seconds1 =(s.hr*60*60)+(s.min*60)+s.sec;
	int seconds2 = hr2*60*60 + min2*60 + sec2;

	int totalSeconds = seconds2-seconds1;

	//extract time in Hours, Minutes and Seconds
	int min3 = totalSeconds/60;
	int hr3 = min3/60;
	min3 = min3%60;
	int sec3 = totalSeconds%60;
	
	int d2,m2,y2;
	d2=tm.tm_mday;
	m2=tm.tm_mon+1;
	y2=tm.tm_year+1900;
	

	//DATE-------------------------------------------------------
	struct date s1, s2;
	int days_on_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	s1.years=y2;
	s1.months=m2;
	s1.days=d2;

	s2.years=s.y;
	s2.months=s.m;
	s2.days=s.d;
	
	int dif=diff(s1,s2);
	int ar1[10]={1,3,5,7,8,10,12};
	int ar2[10]={4,6,9,11};
	int ar3[10]={2};
	int diffDays;
    for(int i=1;i<=12;i++)
     {
	if(s.m==ar1[i])
	{
		diffDays = (s.y*365)+(s.m*31)+s.d;
	}
	else if(s.m==ar2[i])
	{
		diffDays = (s.y*365)+(s.m*30)+s.d;
	}	
	else if(s.m==ar3[i])
	{
		diffDays = (s.y*365)+(s.m*28)+s.d;
	}
    }
	
	diffDays=diffDays+28;
	int year,month,day;

		year=diffDays/365;
		month=(diffDays%365)/31;
		day=diffDays - year*365 - month*31;
		
	if(diff(s1,s2)<=28)
	{
		printf("\n\n\nYOU HAVE %d DAYS REMAINING",28-diff( s1,  s2));
	}
	
/*     
      if(diff(s1,s2)>=0)
	continue;
      else
	{
	if(abs(min3)>=2)
		printf("\n\n\t\tYour plan has Expired !! \n \t\t\tPlease recharge for activation !");
	else
		printf("\n\n\t\t Your Plan has not expired !!");
	}

	
      if(diff(s1,s2)<=28)
	{
	 if(abs(min3)>=2){
		printf("\n\n\t\tYour plan has Expired !! \n \t\t\tPlease recharge for activation !");
	}
      else{
		printf("\n\n\t\tYour plan has Expired !! \n \t\t\tPlease recharge for activation !");
	}
		
*/	
	// time version ----------------------------------------for presenting....
		
	if(abs(min3)>=2){
		//printf("\n\n\t\tYour plan has Expired !! \n \t\t\tPlease recharge for activation !");
		plan_expire();  }
	else
		printf("\n\n\n\n\n\n\n\n Your plan expires on : %d/%d/%d",day,month,year);
	// end-------------------------------------------------------------------------

	printf("---------------------------------------------------------------------------------------------------------------");
	printf("ENTER :");
	choice=getche();
	printf("\n----------------------------------------------------------------------------------------------------------------");

    choice=toupper(choice);
    switch(choice)
    {
        case 'A':
            	 profile();
            	 break;
        case 'B':
            	 change_password();
            	 break;
        case 'C':            	 
		change_plan();
		break;
	
        case 'D':
            	 faq();
                 break;
        case 'E':
            	 system("cls");
	         printf("\n\n\t\tTHANK YOU\n");
	         printf("\t\t\tFOR USING OUR SERVICE\n\n");
	         break;
        default: 		 
                 break;
    }	
}


//########################################################################################################################################################


int days_date(struct date s)     					//Based on 0000-00-00, calculate how many days have passed
{
	int days_on_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int sum=0;                      				//Statistics days
	for (int i = 1; i < s.years; i++)      				//years
	{
		if (s.years % 4 == 0 && s.years % 100 != 0 || s.years % 400 == 0)   //Determine if it is a leap year
			sum += 366;
		else sum += 365;
	}

	for (int k = 1; k < s.months; k++)    				//month
		sum += days_on_month[k];

	return sum+s.days;      					//Add the number of days
}

//########################################################################################################################################################


int diff(struct date s1, struct date s2)
{
	return days_date(s1)-days_date(s2);
}

//########################################################################################################################################################

int faq()
{
    int choice;
    char c;
    system("cls");
    printf("\n\t\t\t\tFREQUENTLY ASKED QUESTIONS(FAQ)\n");
    printf("\n TO KNOW THE ANSWER FOR THE QUESTIONS MENTIONED BELOW ENTER THE NUMBER GIVEN BESIDE TO IT\n");
    printf("\n1: Why is the network so bad from last few days?\n");
    printf("\n2: When do you set up a tower in our area?\n");
    //can add still more q&a
    choice=getche();
    switch(choice)
    {
        case '1': printf("\nWe are sorry for your inconvinience, we will try to correct it as soon as possible\n");
                break;
        case '2': printf("\nWe will setup it within few days\n");
                break;
        default: printf("\nInvalid number\n");
    }
    printf("\n\t\t PRESS esc KEY TO EXIT OR  ANY OTHER KEY FOR DASHBOARD \n");
	
	c=getche();
	if(c==27)
        {
		main();
        }
	else
	{   
		system("cls");
		dashboard();
	}	
    
}

//########################################################################################################################################################

void profile()
{
	system("cls");
	char en;
	printf("********************************************************************************************************************");
	printf("\n********************************************************************************************************************");
	
	printf("\n\n\t\t\t\tNAME             :%s",s.na);
	printf("\n\n\n\t\t\t\tNUMBER           :%s",s.ph);
	printf("\n\n\n\t\t\t\tGENDER           :%s",s.ge);
	printf("\n\n\n\t\t\t\tSTATE            :%s",s.st);
	printf("\n\n\n\t\t\t\tCITY             :%s",s.ci);
	printf("\n\n\n\t\t\t\tPLAN             :%s",s.pl);
	printf("\n\n\n\t\t\t\tDATE            :%d/%d/%d",s.d,s.m,s.y);
	printf("\n********************************************************************************************************************");
	printf("\n********************************************************************************************************************");
	printf("\n\n\n\n\n\n ENTER esc KEY TO EXIT ");
	en=getche();
	if(en==27){ system("cls");
		dashboard();
	}
}

//########################################################################################################################################################

void randomPasswordGeneration()
{
    int  N=6;
    int i = 0;
  
    int randomizer = 0;

    srand((unsigned int)(time(NULL)));

    char numbers[] = "0123456789";

    char letter[] = "abcdefghijklmnoqprstuvwyzx";

    char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";

    char symbols[] = "!@#$^&*?";

    char password[N];
 
    randomizer = rand() % 4;

    char store[N];
    for(int j=0;j<N;j++){
        store[j] = 0;
    }
    int p = 0;
 
    for (i = 0; i < N; i++) {
                                             
        if (randomizer == 1) {
            password[i] = numbers[rand() % 10];
            randomizer = rand() % 4;
            store[p] = password[i];
            store[p+1] = '\0';
            p++;
        }
        else if (randomizer == 2) {
            password[i] = symbols[rand() % 8];
            randomizer = rand() % 4;
            store[p] = password[i];
            store[p+1] = '\0';
            p++;
        }
        else if (randomizer == 3) {
            password[i] = LETTER[rand() % 26];
            randomizer = rand() % 4;
            store[p] = password[i];
            store[p+1] = '\0';
            p++;
        }
        else {
            password[i] = letter[rand() % 26];
            randomizer = rand() % 4;
            store[p] = password[i];
            store[p+1] = '\0';
            p++; 
        }
        
    }
    strcpy(s.passW,store);
}
 
//########################################################################################################################################################

void change_plan()
{
			system("cls");
			
			char  a;
                	char *n;
			int i=0;
			char p[12];
			//printf("\nEnter :");
			//scanf("%s",p);
			//printf("\n%s\n",p);
			FILE *f;
			f=fopen("cusrecord","rb+");
			while(fread(&s,sizeof(s),1,f)==1)
			{ //printf("\n%s\n",p);
			     if(strcmp(s.ph,unique)==0)
			     {
				printf("\n\n\n\n\n1: 599 PLAN \n 2: 799 PLAN  \n 3:999 PLAN \n 4: 1299 PLAN \n ");		
				printf("\n\nENTER YOUR PLAN NUMBER  :\n");
		
				fflush(stdin);
				a=getche();
		
		                long int size=sizeof(s);
				switch(a)
				{	
					case '1':
						n="1";
						printf("\n YOU HAVE CHOOSEN PLAN 1 , Rs 599 /mo ");
						Sleep(3000);
						i=8;
						break;
				
				
					case '2':
						n="2";
						printf("\n YOU HAVE CHOOSEN PLAN 2 , Rs 799 /mo");
						Sleep(3000);
						i=8;
						break;
			
					case '3':
						n="3";
						printf("\n YOU HAVE CHOOSEN PLAN 3 , Rs 999 /mo");
						Sleep(3000);
						i=8;
						break;
			
					case '4':
						n="4";
						printf("\n YOU HAVE CHOOSEN PLAN 4 , Rs 1299 /mo");	
						Sleep(3000);
						i=8;
						break;
			
					default:
						printf("\n Incorrect Input \n");
						printf("\n ENTER Any key to continue  \n");
						getch();	
				}
			
			
			strcpy(s.pl,n);
			fseek(f,-size,SEEK_CUR);
		       fwrite(&s,sizeof(s),1,f);
		       fclose(f);
			break;
		    } 
		 }
			 printf("\n\n ENTER ESC KEY TO GOTO DASHBOARD ");
			char g;
			g=getche();
			if(g==27){
				dashboard();  
		}

}

//########################################################################################################################################################

void change_password()
{
	system("cls");
	FILE *f;
			f=fopen("cusrecord","rb+");
			long int size=sizeof(s);
			while(fread(&s,sizeof(s),1,f)==1)
			{ 
			     if(strcmp(s.ph,unique)==0)
			     {
				printf("Enter your new password : ");
				scanf("%s",s.passW);
				break;
			     }
			}
			fseek(f,-size,SEEK_CUR);
		       fwrite(&s,sizeof(s),1,f);
		       fclose(f);
			printf("\n\nYour password is successfully changed !!\n\n");
		  
			
			printf("\n\n ENTER ESC KEY TO GOTO DASHBOARD ");
			char g;
			g=getche();
			if(g==27){
				dashboard();  }
					
}

//########################################################################################################################################################

void plan_expire()
{
			system("cls");
	
			char  a;
                	char *n;
			int i=0;
			char p[12];
			
			FILE *f;
			f=fopen("cusrecord","rb+");
			
			printf("\n\n\n\n\n\nYOUR PLAN HAS EXPIRED !!! PLEASE CHOOSE YOUR PLAN TO CONTINUE");	

			while(fread(&s,sizeof(s),1,f)==1)
			{  
			   if(strcmp(s.ph,unique)==0)
			     {
				printf("\n\n\n\n\n1: 599 PLAN \n 2: 799 PLAN  \n 3:999 PLAN \n 4: 1299 PLAN \n ");		
				printf("\n\nENTER YOUR PLAN NUMBER  :\n");
		
				fflush(stdin);
				a=getche();
		
		                long int size=sizeof(s);
				switch(a)
				{	
					case '1':
						n="1";
						printf("\n YOU HAVE CHOOSEN PLAN 1 , Rs 599 /mo ");
						Sleep(3000);
						i=8;
						break;
				
				
					case '2':
						n="2";
						printf("\n YOU HAVE CHOOSEN PLAN 2 , Rs 799 /mo");
						Sleep(3000);
						i=8;
						break;
			
					case '3':
						n="3";
						printf("\n YOU HAVE CHOOSEN PLAN 3 , Rs 999 /mo");
						Sleep(3000);
						i=8;
						break;
			
					case '4':
						n="4";
						printf("\n YOU HAVE CHOOSEN PLAN 4 , Rs 1299 /mo");	
						Sleep(3000);
						i=8;
						break;
			
					default:
						printf("\n Incorrect Input \n");
						printf("\n ENTER Any key to continue  \n");
						getch();	
				}
			strcpy(s.pl,n);
		
		time_t t;
		t=time(NULL); 
		struct tm tm=*localtime(&t);
		int d,m,y,min,sec,hr;			

		s.d=tm.tm_mday;
		s.m=tm.tm_mon+1;
		s.y=tm.tm_year+1900;
		s.hr=tm.tm_hour;
		s.min=tm.tm_min;
		s.sec=tm.tm_sec;
			
		fseek(f,-size,SEEK_CUR);
	        fwrite(&s,sizeof(s),1,f);
	        fclose(f);
		break;
	    } 
	 }
		 printf("\n\n ENTER ESC KEY TO GOTO DASHBOARD ");
	       	 char g;
		 g=getche();
		 if(g==27){
				dashboard();  
	}			
}


//##################################################----EMPLOYEEEEEEEEEEEEEEE---#####################################################


void employee_login()
{

	char id[10], passwor[10];
	system("cls");
	printf("\n\n\n\n\t\t\t\tENTER USER ID :\n");
	scanf("%s",id);

	fflush(stdin);
	printf("\n\n\n\n\t\t\t\tEnter your PASSWORD :\n");
	scanf("%s",passwor);
	fflush(stdin);
	         
	if(strcmp("DARSHAN",id)==0)
	{
	    if(strcmp("DARSH",passwor)==0)
		{
			printf("YOU ENTERED");
		}
	    else{
		printf("PASSWORD INCORRECT");
		}
	}
	else{
		printf("USER ID IS INCORRECT");
		}
	getch();
}