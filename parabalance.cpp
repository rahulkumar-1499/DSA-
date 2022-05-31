#include<stack>
#include<iostream>
#include<string.h>
using namespace std;

bool balancedbrackets(string exp)
{
	stack <char>temp;
	for(int i=0;i<exp.length();i++)
	{
		if(temp.empty())
		{
			temp.push(exp[i]);
		}
		else if((temp.top()=='('&& exp[i]==')') || (temp.top()=='{'&& exp[i]=='}')||(temp.top()=='['&& exp[i]==']'))
		{
			temp.pop();
		}
		else
		{
			temp.push(exp[i]);
		}
	}
	if(temp.empty())
	{
		return true;
	}
	else
	return false;
}

int main()
{
	string s;
	cout<<"enter string: ";
	cin>>s;
	if(balancedbrackets(s))
	cout<<"string is balanced";
	else
	cout<<"string is unbalanced";
	
	return 0;
}
