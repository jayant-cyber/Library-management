#include <bits/stdc++.h>
#include <string>
#include <cctype>

#define CENTER "\n\n\t\t\t\t\t"

using namespace std;

class MENU
{
public:
	void head(string str);
	void listing(int x, string str);
	void last(string str);
	void print(string str);
};

class BOOK
{
	string memberCode[10];
	string bookCode;
	string bookName;
	string authorName;
	double bookPrice;
	int numberOfBookCopies;
	int numberOfBookAvaliable;

public:
	void addBook();
	void allBook();
	void editBook();
	void enqureBook();
};

class Member
{
	string Member_Code;
	string Member_Name;
	string Member_Phone;
	string Member_Address;
	string bookcode[5];
	int numberOfBookIssued;
	int bookStartingTime[5], bookEndingTime[5];

public:
	void addMember();
	void allMember();
	void editMember();
	void enqureMember();
};

class transaction
{
	char Transaction_Code[11];
	char Transaction_Date[11];
	char Transaction_Type[3];
	char Member_Code[11];
	char Book_Code[11];
	char Copies[6];

public:
	void issueBook();
	void returnBook();
	void allTransaction();
	void enqureTransaction();
};
void selectableMenu();
void optionMenu(int option);

int main()
{
	int option;
	selectableMenu();
	cin >> option;
	optionMenu(option);
	return 0;
}

void optionMenu(int option)
{
	switch (option)
	{
	case 1:
	case 'B':
	case 'b':
		cout << "b1";
		break;
	case 2:
	case 'M':
	case 'm':
		cout << "b2";
		break;
	case 3:
	case 'I':
	case 'i':
		cout << "b3";
		break;
	case 4:
	case 'R':
	case 'r':
		cout << "b4";
		break;
	case 5:
	case 'L':
	case 'l':
		cout << "b5";
		break;
	case 6:
	case 's':
	case 'S':
		cout << "b6";
		break;
	case 7:
	case 'T':
	case 't':
		cout << "b7";
		break;
	case 8:
	case 'E':
	case 'e':
		cout << "b8e";
		break;
	case 9:
	case 'N':
	case 'n':
		cout << "b9";
		break;
	case 0:
	case 'Q':
	case 'q':
		break;
	default:
		cout << "\n\t\t\t\t\t\t invalid responce\n\t\t\t\t\t\t Enter again";
		break;
	}
}
void selectableMenu()
{
	MENU o;
	o.head("WELCOME TO SIMPLE BOOKS LIBRARY SYSTEM");
	o.listing(1, " Append Books to Books Master(B/b)");
	o.listing(2, " Append Members to Members Master(M/m)");
	o.listing(3, " Issue Book to a Member(I/i)");
	o.listing(4, " Return Book from a Member(R/r)");
	o.listing(5, " List Books in the System(L/l)");
	o.listing(6, " List Members in the System(S/s)");
	o.listing(7, " List Transactions in the System(T/t)");
	o.listing(8, " Edit a Book/Member(E/e)");
	o.listing(9, " Enquire a Book/Member/Transaction(N/n)");
	o.listing(0, " Quit from this System(Q/q/Esc)");
	o.last("Please Enter Your Choice(0..9/Char/Esc)");
}

void MENU ::print(string str)
{
	cout << CENTER << str;
}
void MENU ::head(string str)
{

	string line(str.length() + 5, '-');
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
	cout << CENTER
		 << line
		 << CENTER
		 << str
		 << CENTER
		 << line;
}
void MENU ::listing(int x, string str)
{
	cout << CENTER << x << "). " << str;
}
void MENU ::last(string str)
{
	cout << CENTER << str;
}

void BOOK ::addBook()
{
	MENU o;
	o.print("Book code : ");
	cin >> bookCode;
	o.print("Book Name : ");
	cin >> bookName;
	o.print("Author Name : ");
	cin >> authorName;
	o.print("Book price : ");
	cin >> authorName;
	o.print("Number of copies : ");
	cin >> numberOfBookCopies;
}