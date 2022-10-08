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

struct{
   char name[50];
   char address[100];
   char account_type[100];
   char citizenship[100];
   int age;
   int account_number;
   int phone_number;
   float amt;
}add;

	void new_account(){
		FILE *ptr;
		ptr = fopen("record.txt","a+");

		printf("enter name: ");
		scanf("%s",add.name);
		printf("enter age: ");
		scanf("%d",&add.age);
		printf("enter address: ");
		scanf("%s",add.address);
		printf("enter citizenship: ");
		scanf("%s",add.citizenship);
		printf("enter account type: ");
		scanf("%s",add.account_type);
		printf("enter account number: ");
		scanf("%d",&add.account_number);
		printf("enter phone number: ");
		scanf("%d",&add.phone_number);
		printf("enter amt: ");
		scanf("%f",&add.amt);

		fprintf(ptr,"\nAccount details:%s %d %s %s %s %d %d %f",add.name,add.age,add.address,add.citizenship,add.account_type,add.account_number,add.phone_number,add.amt);
		fclose(ptr);
	}

	void close(void){
		system("clear");
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


int main(void) {

	menu();
//	int i;
//	struct Accounts no_1;
//	struct Accounts no_2;
//	struct Accounts no_3;
//
//	printf("enter name: ");
//	scanf("%[^\n]%*c",no_1.name);
//	printf("enter age: ");
//	scanf("%d",&no_1.age);
//
//	//strcpy(no_2.name,"Peter john");
//	//no_2.age = 40;
//
//
//	printf("Account 1 details:%s %d",no_1.name,no_1.age);

	return 0;
}
