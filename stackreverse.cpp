#include<iostream>
#include<stack>
using namespace std;

template<typename T>
void insertbottom(stack<T> o,int a)
{
	if(o.size==0)
	o.push(a);
	else
	{
		<T>v=o.top();
		o.pop();
		insertbottom(a);
		o.push(v);
	}
}
int reverse(stack<T> s)
{
	if(s.size()>0)
	{
		<T> a=s.top();
		s.pop();
		reverse(s);
		inserbottom(s,a);
	} 
}
void print(stack<T> s)
{
	while(!s.empty())
	{
		cout<<s.top();
		s.pop();
	}
}
int main()
{
	stack <int>s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	reverse(&s);
	print(s);
	
	
	return 0;
}
