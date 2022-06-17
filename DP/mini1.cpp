#include<iostream>
using namespace std;


int min1(int n)
	{
		int  minimum;
	if(n<=1)
	{
	
		return 0;
	}
	int c=min1(n-1);
	int a,b;
	if(n/2==0)
	{
	 a=min1(n/2);	
	
	}

	if(n/3==0)
	{
	 b=min1(n/3);	
//		return n/3;

	}

	
    int ans=min(a,min(b,c))+1;
	
return ans;
}

int main()
{
	int n;
	cin>>n;
	cout<<min1(n);
}