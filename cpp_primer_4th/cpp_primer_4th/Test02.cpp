#include <iostream>
#include <string>
#include <cstddef>
#include <vector>
#include "cpp_primer_config.h"

#include "Test02.h"

#ifdef USE_TEST02_C

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
	cout << "[" << this << "] has been destoryed ! " << endl;
}

void main(void)
{
	vector<Test02> BookStore;

#if 1
	{
		Test02 Temp("Think In C++", 2016001);
		BookStore.push_back(Temp);
		Test02 Temp1("Head First Java", 2016002);
		BookStore.push_back(Temp1);
	}
#endif

	cout << "\tWelcome to Book Store" << endl;
	while (1)
	{
		cout << "\t------------------------------" << endl;
		cout << "\t|	1. Add Book           |" << endl;
		cout << "\t|	2. Delete Book        |" << endl;
		cout << "\t|	3. Modify Book        |" << endl;
		cout << "\t|	4. Book Store Info    |" << endl;
		cout << "\t|	5. Clear Book Store   |" << endl;
		cout << "\t------------------------------" << endl;

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
				cout << "Please Input Book Name & ID : ";
				getline(cin, Name);
				cin >> ID;
				cin.ignore();
				Test02 Temp(Name, ID);
				BookStore.push_back(Temp);
				cout << "There are [" << BookStore.size() << "] Books in the Store" << endl << endl;
			}
			break;
		case 2:
			cout << "\t[" << BookStore.size() << "] Books in the Book Store." << endl;
			if (BookStore.size() == 0)
			{
				cout << "\tNothing to Delete" << endl;
			}
			else
			{
				vector<Test02>::size_type idx;
				cout << "\tWhich are :" << endl;
				for (idx = 0; idx != BookStore.size(); idx++)
				{
					cout << "\t[" << idx << "]";
					BookStore[idx].showBookInfo();
				}
				cout << endl;
				cout << "Which one do you want to delete (0 ~ "<< (idx - 1) << ") : ";
				unsigned int element_no;
				cin >> element_no;
				cin.ignore();
				if (element_no > BookStore.size())
				{
					cout << "Book which you choosed is out of range !" << endl;
				}
				else
				{
					vector<Test02>::const_iterator iter = BookStore.begin() + element_no;
					BookStore.erase(iter);
				}
			}
			break;
		case 3:
			cout << "\t[" << BookStore.size() << "] Books in the Book Store." << endl;
			if (BookStore.size() == 0)
			{
				cout << "\tNothing to Modify" << endl;
			}
			else
			{
				vector<Test02>::size_type idx;
				cout << "\tWhich are :" << endl;
				for (idx = 0; idx != BookStore.size(); idx++)
				{
					cout << "\t[" << idx << "]";
					BookStore[idx].showBookInfo();
				}
				cout << endl;
				cout << "\tWhich one do you want to modify (0 ~ " << (idx - 1) << ") : ";
				unsigned int element_no;
				cin >> element_no;
				cin.ignore();
				if (element_no > BookStore.size())
				{
					cout << "Book which you choosed is out of range !" << endl;
				}
				else
				{
					string Name;
					unsigned int ID;
					vector<Test02>::const_iterator iter = BookStore.begin() + element_no;
					cout << "\tPlease Input Book Name & ID : " << endl;
					getline(cin, Name);
					cin >> ID;
					cin.ignore();
					Test02 Temp(Name, ID);
					BookStore[element_no] =  Temp;
				}
			}
			break;
		case 4:
			cout << "\t[" << BookStore.size() << "] Books in the Book Store, Which are :" << endl;
			for (vector<Test02>::const_iterator iter = BookStore.begin(); iter != BookStore.end(); iter++)
			{
				iter->showBookInfo();
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