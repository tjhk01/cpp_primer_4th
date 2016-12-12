#include <iostream>
#include <string>
#include <cstddef>
#include <vector>
#include "cpp_primer_config.h"

#include "Test02.h"

#ifdef USE_TEST02_C
#define DEBUG	1

using namespace std;

void Test02::showBookInfo(void) const
{
	cout << "\t" << this->BookID << "\t - \t" << this->BookName << endl;
}

Test02::Test02(string Name, unsigned int ID)
{
	this->BookName = Name;
	this->BookID = ID;
}

Test02::~Test02()
{
#if 1 //DEBUG
	cout << "[" << this << "] has been destoryed ! " << endl;
#endif
}

void main(void)
{
	vector<Test02> BookStore;

#if DEBUG
	{
		Test02 Temp = Test02("Think In C++", 2016001);
		BookStore.push_back(Temp);
		Temp = Test02("Head First Java", 2016002);
		BookStore.push_back(Temp);
	}// Destructor Call will be called 3 times, 1st and 2st are called by [push_back]'s temp parameter destory, 3st was called by [Temp]'s destory.
#endif

	cout << "\t\tWelcome to Book Store" << endl;
	while (1)
	{
		cout << "\t-------------------------------" << endl;
		cout << "\t|	1. Add Book           |" << endl;
		cout << "\t|	2. Delete Book        |" << endl;
		cout << "\t|	3. Modify Book        |" << endl;
		cout << "\t|	4. Book Store Info    |" << endl;
		cout << "\t|	5. Clear Book Store   |" << endl;
		cout << "\t-------------------------------" << endl;

		cout << "Choose what do you want to do ( -1 for quit) : ";
		int option = 0;
		cin >> option;
		cin.ignore();
		switch (option)
		{
		case 1:
			{
				string Name;
				unsigned int ID;
				cout << "Please Input Book Name : ";
				getline(cin, Name);
				cout << "Please Input Book ID : ";
				cin >> ID;
				cin.ignore();
				Test02 Temp(Name, ID);
				BookStore.push_back(Temp);
				cout << "There are [" << BookStore.size() << "] Books in the Store" << endl << endl;
			}
			break;
		case 2:
			cout << "There are [" << BookStore.size() << "] Books in the Book Store." << endl;
			if (BookStore.size() == 0)
			{
				cout << "Nothing to Delete" << endl;
			}
			else
			{
				vector<Test02>::size_type idx;
				cout << "Which are :" << endl;
				for (idx = 0; idx != BookStore.size(); idx++)
				{
					cout << "\t[" << idx << "]";
					BookStore[idx].showBookInfo();
				}
				cout << endl;
				cout << "Which one do you want to delete (0 ~ "<< (idx - 1) << ", -1 back to main menu) : ";
				int element_no;
				cin >> element_no;
				cin.ignore();
				if (element_no < 0)
				{
					cout << "Delete nothing  !" << endl;
				}
				else if(element_no > (int)BookStore.size())
				{
					cout << "The book which you choosed is out of range !" << endl;
				}
				else
				{
					vector<Test02>::const_iterator iter = BookStore.begin() + element_no;
					BookStore.erase(iter);
				}
			}
			break;
		case 3:
			cout << "\tThere are [" << BookStore.size() << "] Books in the Book Store." << endl;
			if (BookStore.size() == 0)
			{
				cout << "Nothing to Modify" << endl;
			}
			else
			{
				vector<Test02>::size_type idx;
				cout << "Which are :" << endl;
				for (idx = 0; idx != BookStore.size(); idx++)
				{
					cout << "\t[" << idx << "]";
					BookStore[idx].showBookInfo();
				}
				cout << endl;
				cout << "Which one do you want to modify (0 ~ " << (idx - 1) << ", -1 back to main menu) : ";
				int element_no;
				cin >> element_no;
				cin.ignore();
				if (element_no < 0)
				{
					cout << "Modify nothing  !" << endl;
				}
				else if (element_no > (int)BookStore.size())
				{
					cout << "Book which you choosed is out of range !" << endl;
				}
				else
				{
					string Name;
					unsigned int ID;
					vector<Test02>::const_iterator iter = BookStore.begin() + element_no;
					cout << "Please Input Book Name : " << endl;
					getline(cin, Name);
					cout << "Please Input Book ID : " << endl;
					cin >> ID;
					cin.ignore();
					Test02 Temp(Name, ID);
					BookStore[element_no] =  Temp;
				}
			}
			break;
		case 4:
			cout << "[" << BookStore.size() << "] Books in the Book Store. " << endl;
			if (BookStore.size() > 0)
			{
				cout << "Which are :" << endl;
				for (vector<Test02>::const_iterator iter = BookStore.begin(); iter != BookStore.end(); iter++)
				{
					iter->showBookInfo();
				}
			}
			cout << endl << endl;
			break;
		case 5:
			BookStore.clear();
			cout << "Book Store has been clear up !" << endl;
			break;
		case -1:
		default:
			cout << "System Exit !" << endl;
			exit(0);
			break;
		}
	}
}
#endif