#include<stack>
#include<iostream>
using namespace std;

int main()
{
	stack <int>s;
	s.push(10);
	s.push(20);
	cout<<s.top()<<endl;
	s.push(43);
	s.push(54);
	cout<<s.size()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	cout<<s.size()<<endl;
	
	return 0;
}
