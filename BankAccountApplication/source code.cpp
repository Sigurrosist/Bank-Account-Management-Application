#include <iostream>
#include <string>

using namespace std;

struct Date
{
	int day;
	int month;
	int year;
};
struct Account
{
	string account_number;
	int pin;
	Date open_date;
	string account_type;
	double balance;
};


void display_main();


void load_accounts(Account*, Account*);
void display_accounts(Account*, Account*);
void deposit(Account*, double*);
void withdraw(Account* acc, double* amount);
template <class AnyType> void swap(AnyType *x, AnyType *y);
Account* search_account_by_number(Account*, Account*, string*);
Account* search_account_by_pin(Account*, Account*, int*);
ostream & operator << (ostream& out_stream, Account* acc);
istream & operator >> (istream& in_stream, Account* acc);

int main() 
{

	int choice = 1;
	// static array or array created during compile-time
	int max;

	cout << "Enter the number of account to create : ";
	cin >> max;

	Account* acc_arr = new Account[max];
	Account* pf, *pl;
	pf = &acc_arr[0];
	pl = &acc_arr[max - 1];
    
	load_accounts(pf, pl);

	do
	{
		string target;
		string* p_target = &target;
		double amount;
		double *p_amount = &amount;
		Account *crr_acc;
		int target_int;
		int* p_target_int = &target_int;
		int opt = 0;

		display_main();
		cin >> choice;

		switch (choice)
		{
		case 1: //deposit
			system("cls");
			cout << "Please enter the account number to deposit : ";
			cin >> target;
			crr_acc = search_account_by_number(pf, pl, p_target);	
			cout << "Please enter the amount to depposit to this account : ";
			cin >> amount;
			deposit(crr_acc, p_amount);
			system("pause");

			break;
		case 2: // withdraw
			system("cls");
			cout << "Please enter the account number to deposit : ";
			cin >> target;
			crr_acc = search_account_by_number(pf, pl, p_target);
			cout << "Please enter the amount to withdraw from this account : ";
			cin >> amount;
			withdraw(crr_acc, p_amount);
			system("pause");

			break;
		case 3: // search
			system("cls");
			cout << "\n\nTo search an account by account number, please enter 1." << endl;
			cout << "To search an account by PIN, please enter 2." << endl;
			cin >> opt;
			if ((opt == 1) || (opt == 2))
			{
				if (opt == 1)
				{
					cout << "Please enter the account number to search : ";
					cin >> target;
					cout << search_account_by_number(pf, pl, p_target);
				}
				if (opt == 2)
				{
					cout << "Please enter the PIN to search : ";
					cin >> target_int;
					cout << search_account_by_pin(pf, pl, p_target_int);
				}
				system("pause");
			}
			else
			{
				cout << "you have entered a wrong option to choose." << endl;
				cout << "Going back to the main menu." << endl;
				system("pause");
			}
			break;
		case 4: // sort
			system("cls");

			cout << "\n\nTo sort an account by account number, please enter 1." << endl;
			cout << " To sort them by pin number, please enter 2." << endl;
			cin >> opt;
			if ((opt == 1) || (opt == 2))
			{
				//swap(pf, pl);
			}
			else
			{
				cout << "you have entered a wrong option to choose." << endl;
				cout << "Going back to the main menu." << endl;
				system("pause");
			}
			display_accounts(pf, pl);

		case 5: //display
			display_accounts(pf, pl);
			break;
		case 0: // exit
			cout << "\n\nEnd of the application" << endl;
			break;
		default:
			cout << "\n\nPlease input the right option." << endl;
			cout << "Going back to the main menu." << endl;
			system("pause");
			break;			
		}
	} while (choice != 0);
	system("pause");
	return 0;
}

ostream & operator << (ostream& out_stream, Account* acc)
{
	cout << "*   *   *   *   *   *   *   *   *   *   *   *   *   *   *" << endl;
	cout << "Account Number        : " << acc->account_number << endl;
	cout << "Account Type          : " << acc->account_type << endl;
	cout << "Open Date (DD/MM/YYYY): " << acc->open_date.day << "/" << acc->open_date.month << "/" << acc->open_date.year <<endl;
	cout << "PIN                   : " << acc->pin << endl;
	return out_stream;
}
istream & operator >> (istream& in_stream, Account* acc)
{
	cout << "*   *   *   *   *   *   *   *   *   *   *   *   *   *   *" << endl;
	cout << "Account Number        : ";
	cin >> acc->account_number;
	cout << "Account Type          : ";
	cin >> acc->account_type;
	cout << "Balance : ";
	cin >> acc->balance;
	cout << "<< Open Date >>" <<endl;
	cout << "Day   : ";
	cin >> acc->open_date.day;
	cout << "Month   : ";
	cin >> acc->open_date.month;
	cout << "Year   : ";
	cin >> acc->open_date.year;
	cout << "PIN                   : ";
	cin >> acc->pin;

	return in_stream;
}

void display_main()
{
	system("cls");

	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "-	                Bank Account Management Application                  -" << endl;
	cout << "-                                                                       -" << endl;
	cout << "-                1    : Deposit                                         -" << endl;
	cout << "-                2    : Withdraw                                        -" << endl;
	cout << "-                3    : Search account                                  -" << endl;
	cout << "-                4    : Sort accounts                                   -" << endl;
	cout << "-                5    : Display accounts                                -" << endl;
	cout << "-                                                                       -" << endl;
	cout << "-                                                                       -" << endl;
	cout << "-                0    : Exit this application                           -" << endl;
	cout << "Enter the number  : ";
}
void load_accounts(Account *pf, Account *pl)
{
	Account* index; 
	for (index = pf; index <= pl; index++)
	{
		cin >> index;
	}
	system("pause");
}

void display_accounts(Account *pf, Account *pl)
{
	Account* index;
	for (index = pf; index <= pl; index++)
	{
		cout << index;
	}
	system("pause");
}
Account* search_account_by_number(Account* pf , Account* pl, string* target)
{
	Account i;
	Account* index = &i;
	for (index = pf; index <= pl; index++)
	{
		if (index->account_number == *target)
		{
			break;
		}
	}
	return index;
	system("pause");
}
Account* search_account_by_pin(Account* pf, Account* pl, int* target)
{
	Account i;
	Account* index = &i;
	for (index = pf; index <= pl; index++)
	{
		if (index->pin == *target)
		{
			break;
		}
	}
	return index;
	system("pause");
}
void deposit(Account* acc, double* amount)
{
	acc->balance += *amount;
	cout << *amount << " dollars are placed in the account " << acc->account_number << " successfully." << endl;
	cout << "Current balance is $" << acc->balance << "." << endl;
}
void withdraw(Account* acc, double* amount)
{
	acc->balance -= *amount;
	if (acc->balance >= 0)
	{
		cout << "Request :: $" << *amount << " from the account " << acc->account_number << " has been taken." << endl;
		cout << "Current balance is $" << acc->balance << "." << endl;
	}
	else
	{
		cout << "Please check the balance. The record shows that you have got insufficient balance to complete your request." << endl;
		acc->balance += *amount;
		cout << "Current balance is $" << acc->balance << "." << endl;
		system("pause");
	}
}
template <class AnyType>
void swap(AnyType *x, AnyType *y, int* opt)
{
	//Account* index;
	//Account* temp;
	//if (opt == 1)
	//{
	//	for (index = x; index <= y; index++)
	//	{
	//		if (index->account_number > (index + 1)->account_number)
	//		{
	//			Account *a = index;
	//			Account *b = index + 1;
	//			temp = a;
	//			a = b;
	//			b = temp;
	//		}
	//	}
	//}
	//else
	//{
	//	for (index = x; index <= y; index++)
	//	{
	//		if (index->pin > (index + 1)->pin)
	//		{
	//			Account *a = index;
	//			Account *b = index + 1;
	//			temp = a;
	//			a = b;
	//			b = temp;
	//		}
	//	}
	//}
}
