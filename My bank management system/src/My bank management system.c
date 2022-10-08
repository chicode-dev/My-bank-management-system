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
		printf("enter name: ");
		scanf("%[^\n]s",add.name);
		printf("enter age: ");
		scanf("%d",&add.age);
		printf("enter address: ");
		scanf("%[^\n]s",add.address);
		printf("enter citizenship: ");
		scanf("%[^\n]s",add.citizenship);
		printf("enter account type: ");
		scanf("%[^\n]s",add.account_type);
		printf("enter account number: ");
		scanf("%d",&add.account_number);
		printf("enter phone number: ");
		scanf("%d",&add.phone_number);
		printf("enter amt: ");
		scanf("%f",&add.amt);

		printf("\nAccount details:%s %d %s %s %s %d %d %f",add.name,add.age,add.address,add.citizenship,add.account_type,add.account_number,add.phone_number,add.amt);

	}

int main(void) {

	new_account();
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
