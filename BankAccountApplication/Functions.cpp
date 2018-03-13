#include "Header.h"

/*Function to display the main menu*/
int main_menu() {
	int menu = 0;
	do {
		system("cls");
		cout << "\t\t\t\Bank Account Manager - Main Menu";
		cout << "\n\n\n1 - Create account";
		cout << "\n2 - Display all accounts";
		cout << "\n3 - Check balance";
		cout << "\n4 - Make a transaction";
		cout << "\n5 - Search for an account";
		cout << "\n6 - Sort the accounts";
		cout << "\n7 - Exit application";
		cout << "\n\nEnter your choice: ";
		cin >> menu;
	} while (menu > 7 || menu < 1);
	return menu;
}

/*Search menu display*/
int menu_search() {
	int menu = 0;
	do {
		system("cls");
		cout << "\t\t\nSearch for:";
		cout << "\n1 - Account Number";
		cout << "\n2 - Account PIN";
		cout << "\n3 - Cancel and return to main menu";
		cout << "\n\nEnter your choice: ";
		cin >> menu;
	} while (menu > 3 || menu < 1);
	return menu;
}

/*Search menu transaction*/
int menu_transaction() {
	int menu = 0;
	do {
		system("cls");
		cout << "\t\t\Choose transaction type:";
		cout << "\n1 - Withdraw Money";
		cout << "\n2 - Deposit Money";
		cout << "\n3 - Cancel and return to main menu";
		cout << "\n\nEnter your choice: ";
		cin >> menu;
	} while (menu > 3 || menu < 1);
	return menu;
}

/*Sort menu display*/
int menu_sort() {
	int menu = 0;
	do {
		system("cls");
		cout << "\t\t\Sort by:";
		cout << "\n1 - Account Number";
		cout << "\n2 - Account PIN";
		cout << "\n3 - Cancel and return to main menu";
		cout << "\n\nEnter your choice: ";
		cin >> menu;
	} while (menu > 3 || menu < 1);
	return menu;
}

void add_account(Account &aAccount, int &position) {
	cin >> aAccount;
	position++;
}

/*Overloading the >> (CIN) operator*/
istream &operator >> (istream & in_stream, Account &v) {
	int type;
	cout << "Account Number: ";
	in_stream >> v.accountNumber;
	cout << "Account PIN: ";
	in_stream >> v.pin;
	do {
		cout << "Account Type (1 = Checking | 2 = Saving): ";
		cin >> type;
	} while (type > 2 || type < 1);
	if (type == 1) {
		v.accType = true;
	}
	else { v.accType = false; }
	cout << "Account Balance: ";
	in_stream >> v.balance;
	cout << "Opening Day: ";
	in_stream >> v.openDate.day;
	cout << "Opening Month: ";
	in_stream >> v.openDate.month;
	cout << "Opening Year: ";
	in_stream >> v.openDate.year;
	return in_stream;
}

/*Function to display the account array*/
void display_accounts(Account aAccount[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "\nAccount Number: " << aAccount[i].accountNumber;
		cout << "\nAccount PIN: " << aAccount[i].pin;
		cout << "\nOpen Date: " << aAccount[i].openDate.month << "/" << aAccount[i].openDate.day << "/" << aAccount[i].openDate.year;
		if (aAccount[i].accType) {
			cout << "\nAccount Type: Checking";
		}
		else {
			cout << "\nAccount Type: Saving";
		}
		cout << "\nBalance: " << aAccount[i].balance;
		cout << "\n\n";
	}
}

/*Function to display the balances only*/
void display_balance(Account aAccount[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "\nAccount Number: " << aAccount[i].accountNumber;
		cout << "\nBalance: " << aAccount[i].balance;
		cout << "\n\n";
	}
}

/*Function to withdraw money from an account*/
void withdraw(Account *ptrFirst, Account *ptrLast, string search, float amount) {
	bool found = false;
	bool with = false;
	for (Account *i = ptrFirst; i != ptrLast; i++) {
		if (i->accountNumber == search) {
			if (i->balance >= amount) {
				i->balance -= amount;
				with = true;
			}
			found = true;
		}
	}
	if (found && with) {
		cout << "\n\nThe amount: " << amount << " was successfully withdrew.\n\n";
	}
	else if (!with && found) {
		cout << "\nInsufficient balance to withdraw.\n\n";
	}
	else if (!found && !with) {
		cout << "\nPlease check the entered account.\n\n";
	}
}

/*Function to deposit money to an account*/
void deposit(Account *ptrFirst, Account *ptrLast, string search, float amount) {
	bool found = false;
	for (Account *i = ptrFirst; i != ptrLast; i++) {
		if (i->accountNumber == search) {
			i->balance += amount;
			found = true;
		}
	}
	if (found) {
		cout << "\nThe amount: " << amount << " was successfully deposited.";
	}
	else {
		cout << "\nPlease check the entered account.";
	}
}

/*Overloading the << (COUT) operator*/
ostream &operator << (ostream & out_stream, Account &v) {
	string type;
	if (v.accType) {
		type = "Checking";
	}
	else {
		type = "Saving";
	}

	out_stream << "Account Number: " << v.accountNumber << endl <<
		"Account PIN: " << v.pin << endl
		<< "Open Date: " << v.openDate.month << "/" << v.openDate.day << "/" << v.openDate.year << endl <<
		"Account Type: " << type << endl <<
		"Balance: " << v.balance << "\n\n";
	return out_stream;
}

/*Function to search through an array*/
void search_array(Account *ptrFirst, Account *ptrLast, string search) {
	bool found = false;
	for (Account *i = ptrFirst; i != ptrLast; i++) {
		if ((i->accountNumber == search) || (i->pin == atoi(search.c_str()))) {
			found = true;
			cout << "\n\n";
			cout << *i;
			break;
		}
	}
	if (!found) {
		cout << "\nPlease check the entered account.";
	}
}

/*Function to sort the accounts*/
void sort_accounts(Account *ptrFirst, Account *ptrLast, int sort) {
	Account temp;
	for (Account *i = ptrFirst; i != ptrLast; i++) {
		for (Account *j = i; j != ptrLast; j++) {
			if (sort == 1) {
				if (i->accountNumber > j->accountNumber) {
					temp = *i;
					*i = *j;
					*j = temp;
				}
			}
			if (sort == 2) {
				if (i->pin > j->pin) {
					temp = *i;
					*i = *j;
					*j = temp;
				}
			}
		}
	}
}