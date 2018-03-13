/*
Author: Walter Henrike Ferreira Macieira
Submitted to: Houria Houmel
Created date: 12/march/2018
Description: Midterm Exam
Version: 1.0
*/

#include "Header.h"


int main() {

	int size = 0;
	int position = 0;

	cout << "How many accounts will be created? ";
	cin >> size;

	Account *accounts = new Account[size];

	Account *ptrFirst = &accounts[0];
	Account *ptrLast = &accounts[size];

	int choice = 0;
	string search;
	float amount;


	do {
		/*Switch case for the main menu*/
		switch (main_menu()) {
			/*Case 1, enter a new accounts*/
		case 1:
			system("cls");
			cout << "1 - Entering a new account\n\n";
			if (position < size) {
				add_account(accounts[position], position);
			}
			else {
				cout << "\nYou have reached the limit of accounts.";
				cout << "\nThe limit you entered was: " << size;
				cout << "\nThe limit can only be set at the application start.\n";
			}

			cout << "\nPress any key to go back to the main menu";
			system("pause>>null");
			break;
		case 2:
			/*Case 2, displaying all the accounts*/
			system("cls");
			cout << "2 - Displaying all the accounts\n\n";
			display_accounts(accounts, position);

			cout << "Press any key to go back to the main menu";
			system("Pause>>null");
			break;
		case 3: 
			/*Case 3, check balance*/
			system("cls");
			cout << "3 - Displaying the accounts balance:";
			display_balance(accounts, size);
			cout << "Press any key to go back to the main menu";
			system("Pause>>null");
			break;
		case 4:
			/*Case 4, make transaction*/
			switch (menu_transaction()) {
			case 1: {
				/*withdraw money*/
				cin.ignore();
				cout << "Enter the 'Account Number' to withdraw: ";
				getline(cin, search);
				cout << "Enter the 'amount' to withdraw: ";
				cin >> amount;

				withdraw(ptrFirst, ptrLast, search, amount);

				cout << "\nPress any key to go back to the main menu";
				system("Pause>>null");
				break;
			}
			case 2: {
				/*withdraw money*/
				cin.ignore();
				cout << "Enter the 'Account Number' to deposit: ";
				getline(cin, search);
				cout << "Enter the 'amount' to deposit: ";
				cin >> amount;

				deposit(ptrFirst, ptrLast, search, amount);
				cout << "\nPress any key to go back to the main menu";
				system("Pause>>null");
				break;
			}
			case 3:
				cout << "\nPress any key to go back to the main menu";
				system("Pause>>null");
				break;
			default:
				break;
			}
			break;
		case 5: {
			/*Case 5, searching through the account array*/
			switch (menu_search()) {
			case 1: {
				/*Search by account id*/
				cin.ignore();
				cout << "Enter the 'Account Number' to search: ";
				getline(cin, search);
				search_array(ptrFirst, ptrLast, search);
				cout << "\nPress any key to go back to the main menu";
				system("Pause>>null");
				break;
			}
			case 2: {
				/*Search by pin number*/
				cin.ignore();
				cout << "Enter the 'PIN' to search: ";
				getline(cin, search);
				search_array(ptrFirst, ptrLast, search);
				cout << "\nPress any key to go back to the main menu";
				system("Pause>>null");
				break;
			}
			case 3:
				cout << "\nPress any key to go back to the main menu";
				system("Pause>>null");
				break;
			default:
				break;
			}
			break;
		}
		case 6: {
			/*Sorting the account array*/
			switch (menu_sort()) {
			case 1: {
				/*Sort accounts by account number*/
				sort_accounts(ptrFirst, ptrLast, 1);
				cout << "\nAccounts sorted by Account Number";
				cout << "\nPress any key to go back to the main menu";
				system("Pause>>null");
				break;
			}
			case 2: {
				/*Sort accounts by account pin*/
				sort_accounts(ptrFirst, ptrLast, 2);
				cout << "\nAccounts sorted by Account PIN";
				cout << "\nPress any key to go back to the main menu";
				system("Pause>>null");
				break;
			}
			case 3:
				cout << "Press any key to go back to the main menu";
				system("Pause>>null");
				break;
			default:
				break;
			}
			break;
		}
				break;
		case 7:
			/*Closes the program*/
			choice = 7;
			break;
		default:
			break;
		}
	} while (choice != 7);

	return 0;


	system("pause");
	return 0;
}