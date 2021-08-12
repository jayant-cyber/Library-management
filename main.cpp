#include <bits/stdc++.h>
#include <string>
#include <cctype>
#include "book.h"
#include "member.h"
#include "transaction.h"

#define CENTER "\n\n\t\t\t\t\t"

using namespace std;

class menu
{
public:
	void head(string str)
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
	void listing(int x, string str)
	{
		cout << CENTER << x << "). " << str;
	}
	void last(string str)
	{
		cout << CENTER << str;
	}
};
int selectableMenu()
{
	menu o;
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

int n;
int main()
{
	book b;
	trans t;
	selectableMenu();
	cin >> n;
	switch (n)
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
	return 0;
}