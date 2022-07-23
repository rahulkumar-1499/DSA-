#include<iostream>
using namespace std;


int minsquarehelper(int *arr,int n)
{
	if(n==1||n==2||n==3||n==0)
	{
		return n;
	}
	if(arr[n]!=INT_MAX)
	{
		return arr[n];
	}
	for(int i=1;i*i<n+1;i++)
	{
		arr[n]=min(arr[n],1+minsquarehelper(arr,n-i*i));
	}
	return arr[n];
	
}
int minsquare(int n)
{
	int*arr=new int[n+1];
	for(int i=0;i<n+1;i++)
	{
		arr[i]=INT_MAX;
	}
	return minsquarehelper(arr,n);
}

int main()
{
	int n;
	cout<<"enter n: ";
	cin>>n;
	cout<<minsquare(n);
}
