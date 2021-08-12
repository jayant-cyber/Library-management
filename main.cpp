#include <bits/stdc++.h>
#include <string>
#include "book.h"
#include "member.h"
#include "transaction.h"
using namespace std;

class menu
{
public:
	void head(string str)
	{
		int lenghtOfString = str.size();
		string line('-', lenghtOfString);
		cout << "\n\n\t\t\t\t";
		cout << line;
		cout << "\n\n\t\t\t\t\t";
		cout << str;
		cout << "\n\n\t\t\t\t";
		cout << line;
	}
	void list(int x, char str1[100])
	{
		static int i = 15;
		cout << "\n\t\t\t\t\t" << x << "). " << str1;
		i++;
	}
	void last(char k[100])
	{
		cout << "\n\n\t\t\t\t\t" << k;
	}
};

int n;
int main()
{
	menu o;
	book b;
	trans t;
	o.head("WELCOME TO SIMPLE BOOKS LIBRARY SYSTEM");
	o.list(1, " Append Books to Books Master(B/b)");
	o.list(2, " Append Members to Members Master(M/m)");
	o.list(3, " Issue Book to a Member(I/i)");
	o.list(4, " Return Book from a Member(R/r)");
	o.list(5, " List Books in the System(L/l)");
	o.list(6, " List Members in the System(S/s)");
	o.list(7, " List Transactions in the System(T/t)");
	o.list(8, " Edit a Book/Member(E/e)");
	o.list(9, " Enquire a Book/Member/Transaction(N/n)");
	o.list(0, " Quit from this System(Q/q/Esc)");
	o.last("Please Enter Your Choice(0..9/Char/Esc)");
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