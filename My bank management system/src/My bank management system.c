/*
 ============================================================================
 Name        : My.c
 Author      : Chimdi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
int i;
int enter;
void menu();
void close();

struct date{
	int day,month,year;
};

struct{
   char name[50];
   char address[100];
   char account_type[100];
   char citizenship[100];
   int age;
   int account_number;
   int phone_number;
   float amt;
   struct date Date_of_birth;
   struct date Deposit;
   struct date Withdraw;
}add,check,update,delete;

	void new_account(){
		FILE *ptr;
		ptr = fopen("record.txt","a+");

		account_no:
		printf("Enters today date:");
		scanf("%d/%d/%d",&add.Deposit.day,&add.Deposit.month,&add.Deposit.year);
		printf("\nenter new account number: ");
		scanf("%d",&check.account_number);
		while(fscanf(ptr,"%d %s %d %d/%d/%d %s %s %d %s %f",&add.account_number,add.name,&add.age,&add.Date_of_birth.day,&add.Date_of_birth.month,
				&add.Date_of_birth.year,add.citizenship,add.address,&add.phone_number,add.account_type,&add.amt)!=EOF){
			if(check.account_number == add.account_number){
				printf("This account already exists\n");
				goto account_no;
			}
		}
		add.account_number = check.account_number;
		printf("\nenter name: ");
		scanf("%s",add.name);
		printf("\nenter age: ");
		scanf("%d",&add.age);
		printf("\nenter date of birth: ");
		scanf("%d/%d/%d",&add.Date_of_birth.day,&add.Date_of_birth.month,&add.Date_of_birth.year);
		printf("\nenter citizenship: ");
		scanf("%s",add.citizenship);
		printf("\nenter address: ");
		scanf("%s",add.address);
		printf("\nenter phone number: ");
		scanf("%d",&add.phone_number);
		printf("\nenter account type: ");
		scanf("%s",add.account_type);
		printf("\nenter amount to deposit: ");
		scanf("%f",&add.amt);

		fprintf(ptr,"%d %s %d %d/%d/%d %s %s %d %s %f",add.account_number,add.name,add.age,add.Date_of_birth.day,add.Date_of_birth.month,add.Date_of_birth.year,
				add.citizenship,add.address,add.phone_number,add.account_type,add.amt);
		fclose(ptr);

		printf("ACCOUNT SUCCESFULLY CREATED");
		add_invalid:
		printf("PICK ACTION\n1.Go to main menu\n2.Close program\n");
		int pick;
		scanf("%d",&pick);
		if(pick == 1){
			menu();
		}else if(pick == 2){
			close();
		}else{
			printf("incorrect input please enter correct options:\n");
			goto add_invalid;

		}
	}

	void view_records(){
		FILE *view;
		view=fopen("record.txt","r");
		int rec=0;

		printf("View all records\nAccount number, name, address, phone number\n");
		while(fscanf(view,"%d %s %d %d/%d/%d %s %s %d %s %f",&add.account_number,add.name,&add.age,&add.Date_of_birth.day,&add.Date_of_birth.month,
						&add.Date_of_birth.year,add.citizenship,add.address,&add.phone_number,add.account_type,&add.amt)!=EOF)
		{
				printf("%d\t%s\t%s\t%d\n",add.account_number,add.name,add.address,add.phone_number);
				rec++;
		}
		fclose(view);
		if(rec==0){
			printf("No records available\n");
			menu();
		}
		viewrec:
		printf("Choose next action:\n1.back to main menu\n2.close program\n");
		scanf("%d",&enter);
		if(enter==1){
			system("clear");
			menu();
		}else if(enter == 2){
			system("clear");
			close();
		}else{
			printf("incorrect input");
			goto viewrec;
		}
		}

	void delete_account(){

		int num2=0;
		FILE *oldfile,*newfile;
		oldfile=fopen("record.txt","r");
		newfile=fopen("new.txt","w");

		printf("Enter the account no. of the customer you want to delete:");
		scanf("%d",&delete.account_number);
		    while (fscanf(oldfile,"%d %s %d %d/%d/%d %s %s %d %s %f",&add.account_number,add.name,&add.age,&add.Date_of_birth.day,&add.Date_of_birth.month,
					&add.Date_of_birth.year,add.citizenship,add.address,&add.phone_number,add.account_type,&add.amt)!=EOF)
		   {
		        if(add.account_number != delete.account_number){
		        	fprintf(newfile,"%d %s %d %d/%d/%d %s %s %d %s %f",add.account_number,add.name,add.age,add.Date_of_birth.day,
		        	add.Date_of_birth.month,add.Date_of_birth.year,add.citizenship,add.address,add.phone_number,add.account_type,add.amt);}
		        else
		            {num2++;
		            printf("\nAccount deleted successfully\n");
		            }
		   }
		   fclose(oldfile);
		   fclose(newfile);
		   remove("record.txt");
		   rename("new.txt","record.txt");
		   if(num2==0)
		   		        {   system("clear");
		   		            printf("\nRecord not found.");
		   		            tryagain2:
		   		            printf("\nEnter option\n0.try again\n1.main menu\n2close program\n");
		   		            scanf("%d",&enter);
		   		            system("clear");
		   		                 if (enter==1){
		   		                    menu();}
		   		                else if (enter==2){
		   		                    close();}
		   		                else if(enter==0){
		   		                    delete_account();}
		   		                else
		   		                    {printf("Wrong input try again\n");
		   		                    goto tryagain2;
		   		                    }
		   		        }
		   		    else
		   		        {printf("Enter option\n1.main menu\n0.close program\n");
		        scanf("%d",&enter);
		        system("clear");
		        if (enter==1){
		            menu();}
		        else{
		            close();}
		   		        }

		}

	void edit_account(){
		 int num1,num2=0;
		 FILE *oldfile,*newfile;
		 oldfile=fopen("record.txt","r");
		 newfile=fopen("new.txt","w");

		 printf("\nEnter the account no. of the customer whose info you want to edit:");
		 scanf("%d",&update.account_number);
		 while(fscanf(oldfile,"%d %s %d %d/%d/%d %s %s %d %s %f",&add.account_number,add.name,&add.age,&add.Date_of_birth.day,&add.Date_of_birth.month,
					&add.Date_of_birth.year,add.citizenship,add.address,&add.phone_number,add.account_type,&add.amt)!=EOF)
		    {
		        if(add.account_number == update.account_number)
		        {   num2=1;
		            printf("\nWhich information do you want to change?\n1.Address\n2.Phone number\n\nEnter your choice:");
		            scanf("%d",&num1);
		            system("clear");
		            if(num1==1)
		                {printf("Enter the new address:");
		                scanf("%s",update.address);
		                fprintf(newfile,"%d %s %d %d/%d/%d %s %s %d %s %f",add.account_number,add.name,add.age,add.Date_of_birth.day,
		                		add.Date_of_birth.month,add.Date_of_birth.year,
		        				add.citizenship,update.address,add.phone_number,add.account_type,add.amt);
		                system("clear");
		                printf("address updated");
		                }
		            else if(num1==2)
		                {
		                printf("Enter the new phone number:");
		                scanf("%d",&update.phone_number);
		                fprintf(newfile,"%d %s %d %d/%d/%d %s %s %d %s %f",add.account_number,add.name,add.age,add.Date_of_birth.day,
		                		add.Date_of_birth.month,add.Date_of_birth.year,add.citizenship,add.address,update.phone_number,
								add.account_type,add.amt);
		                system("clear");
		                printf("phone number updated.");
		                }

		        }
		        else{
		            fprintf(newfile,"%d %s %d %d/%d/%d %s %s %d %s %f",add.account_number,add.name,add.age,add.Date_of_birth.day,
	                		add.Date_of_birth.month,add.Date_of_birth.year,add.citizenship,add.address,add.phone_number,
							add.account_type,add.amt);}
		    }
		    fclose(oldfile);
		    fclose(newfile);
		    remove("record.txt");
		    rename("new.txt","record.txt");

		if(num2!=1)
		        {   system("clear");
		            printf("\nRecord not found.");
		            tryagain:
		            printf("\nEnter option\n0.try again\n1.main menu\n2close program\n");
		            scanf("%d",&enter);
		            system("clear");
		                 if (enter==1){
		                    menu();}
		                else if (enter==2){
		                    close();}
		                else if(enter==0){
		                    edit_account();}
		                else
		                    {printf("Wrong input try again\n");
		                    goto tryagain;
		                    }
		        }
		    else
		        {printf("Enter option\n1.main menu\n0.close program\n");
		        scanf("%d",&enter);
		        system("clear");
		        if (enter==1){
		            menu();}
		        else{
		            close();}
		        }
		}


	void close(){
		system("clear");
		printf("bank management system has ended");
	}

	void menu(void){
		int choose;
		system("clear");
		printf("WELCOME TO THE BANK MANAGEMENT SYSTEM\nPLEASE CHOOSE WHAT YOU WOULD LIKE TO DO:\n");
		printf("press 1 to add new account\n");
		printf("press 2 to view records\n");
		printf("press 3 to edit an account\n");
		printf("press 4 to delete an account\n");
		printf("press 5 to close program\n");
		printf("enter value: ");
		scanf("%d",&choose);
		system("clear");

		switch(choose){
		case 1:new_account();
		break;
		case 2:view_records();
		break;
		case 3:edit_account();
		break;
		case 4:delete_account();
		break;
		case 5:close();
		break;
		}
	}

int main(void) {

	printf("Welcome to the bank management system\n");
			password_start:
			printf("please enter the correct password: \n");
			int arr[] = {1,2,3,4,5};
			int arr2[5];

			for(i=0;i<5;i++){
			scanf("%d",&arr2[i]);
			}
			for(i=0;i<5;i++){
			 if(arr[i] == arr2[i]){
				 printf("Password successful\n");
				 menu();
			 }
			 else{
				 printf("Password incorrect please try again\n");
				 goto password_start;
			 }
			}

	return 0;
}
