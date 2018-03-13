#ifndef BAA_H
#define BAA_H

#include <iostream>
#include <string>

using namespace std;

/*Structure DATE*/
struct Date {
	int day;
	int month;
	int year;
};

/*Structure Account*/
struct Account {
	string accountNumber;
	int pin;
	Date openDate;
	bool accType;
	float balance;
};


/*Menu function protypes*/
int menu_sort();
int menu_search();
int main_menu();
int menu_transaction();

/*Functions protypes*/
void add_account(Account &aAccount, int &position);
void display_accounts(Account aAccount[], int size);
void display_balance(Account aAccount[], int size);
void withdraw(Account *ptrFirst, Account *ptrLast, string search, float amount);
void deposit(Account *ptrFirst, Account *ptrLast, string search, float amount);
void search_array(Account *ptrFirst, Account *ptrLast, string search);
void sort_accounts(Account *ptrFirst, Account *ptrLast, int sort);

/*Operator overloading protypes*/
istream &operator >> (istream & in_stream, Account &v);
ostream &operator << (ostream & out_stream, Account &v);

#endif