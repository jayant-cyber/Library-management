#include <conio.h>
#include <string.h>
#include <stdio.h>
using namespace std;

class menu
{ 
  public :
  void head(char str[100])
  {
  	int length=strlen(str);
  	cout<<"\n\n\t\t\t\t";
  	for(int i=0; i<length+8;i++)
    cout<<"=";
  	cout<<"\n\n\t\t\t\t\t";
  	cout<<str;
  	cout<<"\n\n\t\t\t\t";
  	for(int i=0; i<length+8;i++)
    cout<<"=";
  }
  void list(int x, char str1[100])
  { static int i=15;
  	cout<<"\n\t\t\t\t\t"<<x<<"). "<< str1;
  	i++;
  }
  void last(char k[100])
  {
  	cout<<"\n\n\t\t\t\t\t"<<k;
  }
};