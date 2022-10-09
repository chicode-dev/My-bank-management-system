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
void menu ();
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
}add,check;

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

	void remove_account(void){

	}

	void view_records(){
		FILE *view;



	}

	void close(){
		//system("clear");
		printf("bank management system has ended");
	}

	void menu(void){
		int choose;
		system("clear");
		printf("WELCOME TO THE BANK MANAGEMENT SYSTEM\nPLEASE CHOOSE WHAT YOU WOULD LIKE TO DO:\n");
		printf("press 1 to add new account\n");
		printf("press 2 to close program\n");
		printf("enter value");
		scanf("%d",&choose);
		system("clear");

		switch(choose){
		case 1:new_account();
		break;
		case 2:close();
		break;
		}
	}


	void password(void){

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
