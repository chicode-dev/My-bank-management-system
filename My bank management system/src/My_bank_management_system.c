/*
 ============================================================================
 Name        : Bank management system
 Author      : Chimdindu Chukwuka
 Description : C project that uses structs to store and manipulate data
 ============================================================================
 */

#include <bits/types/FILE.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i;
int enter;
void menu();
void close();

float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}

struct date {
int day, month, year;
};

struct {
char name[50];
char surname[50];
char address[50];
char account_type[10];
char citizenship[50];
int age;
int account_number;
int phone_number;
float amt;
struct date Date_of_birth;
struct date deposit;
struct date Withdraw;
} add, check, update, delete, transact, deposit, balance;

void new_account() {
	FILE *ptr;
	ptr = fopen("record.txt", "a+");

	printf("Enter today's date(DD/MM/YYYY):");
	scanf("%d/%d/%d",&add.deposit.day,&add.deposit.month,&add.deposit.year);

	account_no:
	printf("Enter new account number (4 digits): ");
	scanf("%d", &check.account_number);
	while (fscanf(ptr, "%d\t\t%s\t\t%s\t\t%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%d\t\t%s\t\t%f\n", &add.account_number,
			add.name, add.surname, &add.age, &add.Date_of_birth.day,&add.Date_of_birth.month,
			&add.Date_of_birth.year, add.citizenship,add.address, &add.phone_number,
			add.account_type, &add.amt) != EOF) {
		if (check.account_number == add.account_number) {
			printf("This account already exists\n");
			goto account_no;
		}//having an endless loop problem fix it!!!!!!!!!!!

	}
	add.account_number = check.account_number;
	printf("Enter first name: ");
	scanf("%s", add.name);
	printf("Enter surname: ");
	scanf("%s", add.surname);

	agetry:
	printf("Enter age (18 - 100): ");
	scanf("%d", &add.age);
	if(add.age > 100 || add.age < 18){
		printf("invalid age\n");
		goto agetry;
	}

	printf("Enter date of birth (DD/MM/YYYY): ");
	scanf("%d/%d/%d", &add.Date_of_birth.day, &add.Date_of_birth.month,&add.Date_of_birth.year);

	printf("Enter citizenship: ");
	scanf("%s", add.citizenship);

	printf("Enter city: ");
	scanf("%s", add.address);

	printf("Enter phone number (5 digits): ");
	scanf("%d", &add.phone_number);

	int type;
	account_type_try_again:
	printf("Pick account type\n1.Savings\n2.Current\n3.Fixed - 1 year\n4.Fixed - 2 years\n5.Fixed - 3 years\nInput choice: ");
	scanf("%d",&type);
	if(type == 1){
		strcpy(add.account_type ,"Savings");
	}else if(type == 2){
		strcpy(add.account_type ,"Current");
	}else if(type == 3){
		strcpy(add.account_type ,"fixed1");
	}else if(type == 4){
		strcpy(add.account_type , "fixed2");
	}else if(type == 5){
		strcpy(add.account_type , "fixed3");
	}else{
		printf("Incorrect input\n");
		goto account_type_try_again;
	}

	printf("Enter amount to deposit: $");
	scanf("%f", &add.amt);

	fprintf(ptr, "%d\t\t%s\t\t%s\t\t%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%d\t\t%s\t\t%f\n",
			add.account_number,add.name, add.surname, add.age, add.Date_of_birth.day,
			add.Date_of_birth.month,add.Date_of_birth.year, add.citizenship,add.address,
			add.phone_number,add.account_type, add.amt);
	fclose(ptr);
	printf("ACCOUNT SUCCESFULLY CREATED\n");

	add_invalid:
	printf("PICK ACTION\n1.Go to main menu\n2.Close program\n");
	int pick;
	scanf("%d", &pick);
	if (pick == 1) {
		menu();
	} else if (pick == 2) {
		close();
	} else {
		printf("incorrect input please enter correct options:\n");
		goto add_invalid;
	}
}

void view_records() {
	FILE *view;
	view = fopen("record.txt", "r");
	int rec = 0;

	printf("View all records\nAccount number\t\tFirst name\t\tSurname\t\tCity\t\tPhone number\n");
	while (fscanf(view, "%d\t\t%s\t\t%s\t\t%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%d\t\t%s\t\t%f\n", &add.account_number,
			add.name, add.surname, &add.age, &add.Date_of_birth.day,&add.Date_of_birth.month,
			&add.Date_of_birth.year, add.citizenship,add.address, &add.phone_number,
			add.account_type, &add.amt) != EOF) {
		printf("%d\t%s\t%s\t%s\t%d\n", add.account_number, add.name,add.surname, add.address,
				add.phone_number);
		rec++;
	}
	fclose(view);
	if (rec == 0) {
		printf("No records available\n");
		menu();
	}
	viewrec:
	printf("Choose next action:\n1.back to main menu\n2.close program\n");
	scanf("%d", &enter);
	if (enter == 1) {
		system("clear");
		menu();
	} else if (enter == 2) {
		system("clear");
		close();
	} else {
		printf("incorrect input");
		goto viewrec;
	}
}

void delete_account() {

	int num2 = 0;
	FILE *oldfile, *newfile;
	oldfile = fopen("record.txt", "r");
	newfile = fopen("new.txt", "w");

	printf("Enter the account no. of the customer you want to delete:");
	scanf("%d", &delete.account_number);
	while (fscanf(oldfile, "%d\t\t%s\t\t%s\t\t%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%d\t\t%s\t\t%f\n", &add.account_number,
			add.name, add.surname, &add.age, &add.Date_of_birth.day,&add.Date_of_birth.month,
			&add.Date_of_birth.year, add.citizenship,add.address, &add.phone_number,
			add.account_type, &add.amt) != EOF) {
		if (add.account_number != delete.account_number) {
			fprintf(newfile, "%d\t\t%s\t\t%s\t\t%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%d\t\t%s\t\t%f\n", add.account_number,
					add.name, add.surname, add.age, add.Date_of_birth.day,add.Date_of_birth.month,
					add.Date_of_birth.year, add.citizenship,add.address, add.phone_number,
					add.account_type, add.amt);
		} else {
			num2++;
			printf("\nAccount deleted successfully\n");
		}
	}
	fclose(oldfile);
	fclose(newfile);
	remove("record.txt");
	rename("new.txt", "record.txt");
	if (num2 == 0) {
		system("clear");
		printf("\nRecord not found.");
		tryagain2: printf(
				"\nEnter option\n0.try again\n1.main menu\n2.close program\n");
		scanf("%d", &enter);
		system("clear");
		if (enter == 1) {
			menu();
		} else if (enter == 2) {
			close();
		} else if (enter == 0) {
			delete_account();
		} else {
			printf("Wrong input try again\n");
			goto tryagain2;
		}
	} else {
		printf("Enter option\n1.main menu\n0.close program\n");
		scanf("%d", &enter);
		system("clear");
		if (enter == 1) {
			menu();
		} else {
			close();
		}
	}

}

void edit_account() {
	int num1, num2 = 0;
	FILE *oldfile, *newfile;
	oldfile = fopen("record.txt", "r");
	newfile = fopen("new.txt", "w");

	printf("\nEnter the account no. of the customer whose info you want to edit:");
	scanf("%d", &update.account_number);
	while (fscanf(oldfile, "%d\t\t%s\t\t%s\t\t%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%d\t\t%s\t\t%f\n", &add.account_number,
			add.name, add.surname, &add.age, &add.Date_of_birth.day,&add.Date_of_birth.month,
			&add.Date_of_birth.year, add.citizenship,add.address, &add.phone_number,
			add.account_type, &add.amt) != EOF) {
		if (add.account_number == update.account_number) {
			num2 = 1;
			printf("\nWhich information do you want to change?\n1.City\n2.Phone number\n3.First name\n4.Surname\nEnter your choice:");
			scanf("%d", &num1);
			system("clear");
			if (num1 == 1) {
				printf("Enter the new City: ");
				scanf("%s", update.address);
				fprintf(newfile, "%d\t\t%s\t\t%s\t\t%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%d\t\t%s\t\t%f\n", add.account_number,
						add.name, add.surname, add.age, add.Date_of_birth.day,add.Date_of_birth.month,
						add.Date_of_birth.year, add.citizenship,update.address, add.phone_number,
						add.account_type, add.amt);
				system("clear");
				printf("City updated\n");
			} else if (num1 == 2) {
				printf("Enter the new phone number:");
				scanf("%d", &update.phone_number);
				fprintf(newfile, "%d\t\t%s\t\t%s\t\t%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%d\t\t%s\t\t%f\n", add.account_number,
						add.name, add.surname, add.age, add.Date_of_birth.day,add.Date_of_birth.month,
						add.Date_of_birth.year, add.citizenship,add.address, update.phone_number,
						add.account_type, add.amt);
				system("clear");
				printf("phone number updated.");
			}else if(num1 == 3){
				printf("Enter new first name: ");
				scanf("%s", update.name);
				fprintf(newfile, "%d\t\t%s\t\t%s\t\t%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%d\t\t%s\t\t%f\n", add.account_number,
						update.name, add.surname, add.age, add.Date_of_birth.day,add.Date_of_birth.month,
						add.Date_of_birth.year, add.citizenship,add.address, add.phone_number,
						add.account_type, add.amt);
				system("clear");
				printf("first name updated.");
			}else if(num1 == 4){
				printf("Enter new surname: ");
				scanf("%s", update.surname);
				fprintf(newfile, "%d\t\t%s\t\t%s\t\t%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%d\t\t%s\t\t%f\n", add.account_number,
						add.name, update.surname, add.age, add.Date_of_birth.day,add.Date_of_birth.month,
						add.Date_of_birth.year, add.citizenship,add.address, add.phone_number,
						add.account_type, add.amt);
				system("clear");
				printf("surname updated.");
		} else {
			fprintf(newfile, "%d\t\t%s\t\t%s\t\t%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%d\t\t%s\t\t%f\n", add.account_number,
					add.name, add.surname, add.age, add.Date_of_birth.day,add.Date_of_birth.month,
					add.Date_of_birth.year, add.citizenship,add.address, add.phone_number,
					add.account_type, add.amt);
		}
	}
	}
	fclose(oldfile);
	fclose(newfile);
	remove("record.txt");
	rename("new.txt", "record.txt");

	if (num2 != 1) {
		system("clear");
		printf("\nRecord not found.");
		tryagain: printf("\nEnter option\n0.try again\n1.main menu\n2.close program\n");
		scanf("%d", &enter);
		system("clear");
		if (enter == 1) {
			menu();
		} else if (enter == 2) {
			close();
		} else if (enter == 0) {
			edit_account();
		} else {
			printf("Wrong input try again\n");
			goto tryagain;
		}
	} else {
		printf("Enter option\n1.main menu\n0.close program\n");
		scanf("%d", &enter);
		system("clear");
		if (enter == 1) {
			menu();
		} else {
			close();
		}
	}
}

void Balance(){
	int bal = 0;
	FILE *ptr;
	ptr = fopen("record.txt", "r");

	printf("\nEnter the account no.:");
	scanf("%d", &balance.account_number);
	while (fscanf(ptr,"%d\t\t%s\t\t%s\t\t%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%d\t\t%s\t\t%f\n", &add.account_number,
			add.name, add.surname, &add.age, &add.Date_of_birth.day,&add.Date_of_birth.month,
			&add.Date_of_birth.year, add.citizenship,add.address, &add.phone_number,
			add.account_type, &add.amt) != EOF) {
		if (add.account_number == balance.account_number) {
			bal = 1;
			printf("Your balance is %f",add.amt);
		}
	}

	if (bal != 1) {
			system("clear");
			printf("\nRecord not found.");
			tryagainbal:
			printf("\nEnter option\n0.try again\n1.main menu\n2.close program\n");
			scanf("%d", &enter);
			system("clear");
			if (enter == 1) {
				menu();
			} else if (enter == 2) {
				close();
			} else if (enter == 0) {
				Balance();
			} else {
				printf("Wrong input try again\n");
				goto tryagainbal;
			}
		} else {
			printf("Enter option\n1.main menu\n0.close program\n");
			scanf("%d", &enter);
			system("clear");
			if (enter == 1) {
				menu();
			} else {
				close();
			}
		}


}

void transaction() {
	int num2 = 0;
	FILE *oldfile, *newfile;
	oldfile = fopen("record.txt", "r");
	newfile = fopen("new.txt", "w");

	printf("\nEnter the account no.:");
	scanf("%d", &transact.account_number);
	while (fscanf(oldfile, "%d\t\t%s\t\t%s\t\t%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%d\t\t%s\t\t%f\n", &add.account_number,
			add.name, add.surname, &add.age, &add.Date_of_birth.day,&add.Date_of_birth.month,
			&add.Date_of_birth.year, add.citizenship,add.address, &add.phone_number,
			add.account_type, &add.amt) != EOF) {
		if (add.account_number == transact.account_number) {
			num2 = 1;
			if (strcmp(add.account_type, "fixed1") == 0
					|| strcmp(add.account_type, "fixed2") == 0
					|| strcmp(add.account_type, "fixed3") == 0) {
				printf("YOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS");
				system("clear");
				menu();

			}
			printf("Do you want to\n1.Deposit\n2.Withdraw?\n");
			scanf("%d", &enter);
			if (enter == 1) {
				printf("Enter the amount you want to deposit:$ ");
				scanf("%f", &transact.amt);
				add.amt += transact.amt;
				fprintf(newfile, "%d\t\t%s\t\t%s\t\t%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%d\t\t%s\t\t%f\n", add.account_number,
						add.name, add.surname, add.age, add.Date_of_birth.day,add.Date_of_birth.month,
						add.Date_of_birth.year, add.citizenship,add.address, add.phone_number,
						add.account_type, add.amt);
				printf("\nDeposited successfully");
			} else {
				printf("Enter the amount you want to withdraw: ");
				scanf("%f", &transact.amt);
				add.amt -= transact.amt;
				fprintf(newfile, "%d\t\t%s\t\t%s\t\t%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%d\t\t%s\t\t%f\n", add.account_number,
						add.name, add.surname, add.age, add.Date_of_birth.day,add.Date_of_birth.month,
						add.Date_of_birth.year, add.citizenship,add.address, add.phone_number,
						add.account_type, add.amt);
				printf("\nWithdrawn successfully!");
			}

		} else {
			fprintf(newfile, "%d\t\t%s\t\t%s\t\t%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%d\t\t%s\t\t%f\n", add.account_number,
					add.name, add.surname, add.age, add.Date_of_birth.day,add.Date_of_birth.month,
					add.Date_of_birth.year, add.citizenship,add.address, add.phone_number,
					add.account_type, add.amt);
		}
	}
	fclose(oldfile);
	fclose(newfile);
	remove("record.txt");
	rename("new.txt", "record.txt");

	if (num2 != 1) {
		system("clear");
		printf("\nRecord not found.");
		tryagain3:
		printf("\nEnter option\n0.try again\n1.main menu\n2.close program\n");
		scanf("%d", &enter);
		system("clear");
		if (enter == 1) {
			menu();
		} else if (enter == 2) {
			close();
		} else if (enter == 0) {
			transaction();
		} else {
			printf("Wrong input try again\n");
			goto tryagain3;
		}
	} else {
		printf("Enter option\n1.main menu\n0.close program\n");
		scanf("%d", &enter);
		system("clear");
		if (enter == 1) {
			menu();
		} else {
			close();
		}
	}

}

void see(void)
{
FILE *ptr;
int test=0,rate;
float time;
float intrst;
ptr=fopen("record.txt","r");
printf("Enter the account number:");
scanf("%d",&check.account_number);

while (fscanf(ptr, "%d\t\t%s\t\t%s\t\t%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%d\t\t%s\t\t%f\n", &add.account_number,
		add.name, add.surname, &add.age, &add.Date_of_birth.day,&add.Date_of_birth.month,
		&add.Date_of_birth.year, add.citizenship,add.address, &add.phone_number,
		add.account_type, &add.amt) != EOF)
{
if(add.account_number==check.account_number)
{
system("clear");
test=1;
if(strcmp(add.account_type,"fixed1")==0)
{
	time=1.0;
	rate=9;
	intrst=interest(time,add.amt,rate);
	printf("\nYou will get $%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+1);
}
else if(strcmp(add.account_type,"fixed2")==0)
{
	time=2.0;
	rate=11;
	intrst=interest(time,add.amt,rate);
	printf("\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+2);

}
else if(strcmp(add.account_type,"fixed3")==0)
{
	time=3.0;
	rate=13;
	intrst=interest(time,add.amt,rate);
	printf("\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+3);

}
else if(strcmp(add.account_type,"saving")==0)
{
	time=(1.0/12.0);
	rate=8;
	intrst=interest(time,add.amt,rate);
	printf("\nYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);

 }
else if(strcmp(add.account_type,"current")==0)
{

	printf("\nYou will get no interest");

 }}}


fclose(ptr);
if(test!=1)
{
system("clear");
printf("\nRecord not found!!\a\a\a");
tryagaind: printf("\nEnter option\n0.try again\n1.main menu\n2.close program\n");
	scanf("%d", &enter);
	system("clear");
	if (enter == 1) {
		menu();
	} else if (enter == 2) {
		close();
	} else if (enter == 0) {
		see();
	} else {
		printf("Wrong input try again\n");
		goto tryagaind;
	}
}
else
{
add_invalid:
printf("PICK ACTION\n1.Go to main menu\n2.Close program\n");
int pick;
scanf("%d", &pick);
if (pick == 1){
menu();
} else if (pick == 2) {
close();
} else {
printf("incorrect input please enter correct options:\n");
goto add_invalid;
}
}
}

void close() {
system("clear");
printf("bank management system has ended");
}

void menu(void) {
int choose;
system("clear");
printf("WELCOME TO THE BANK MANAGEMENT SYSTEM\nPLEASE CHOOSE WHAT YOU WOULD LIKE TO DO:\n");
printf("press 1 to add new account\n");
printf("press 2 to view balance\n");
printf("press 3 to view records\n");
printf("press 4 to edit an account\n");
printf("press 5 to make a transaction\n");
printf("press 6 to delete an account\n");
printf("press 7 to close program\n");
printf("enter value: ");
scanf("%d", &choose);
system("clear");

switch (choose) {
case 1:
new_account();
break;
case 2:
Balance();
break;
case 3:
view_records();
break;
case 4:
edit_account();
break;
case 5:
transaction();
break;
case 6:
delete_account();
break;
case 7:
close();
break;
}
}

int main(void) {

printf("Welcome to the bank management system\n");
password_start:
printf("please enter the correct password: \n");
int pass = 12345;
int pass2;

scanf("%d", &pass2);

if (pass2 == pass) {
	printf("Password successful\n");
	menu();
} else {
	printf("Password incorrect please try again\n");
	goto password_start;
}

return 0;
}
