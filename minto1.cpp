#include<iostream>
#include<cmath>
using namespace std;


//int min1(int n)		//normal recursion
//{
//	if(n<=1)
//	{
//		return 0;
//	}
//	int x=min1(n-1);
//	int y=INT_MAX,z=INT_MAX;
//	if(n%2==0)
//	{
//		y=min1(n/2);
//	}
//	if(n%3==0)
//	{
//		z=min1(n/3);
//	
//	}
//	int res2=min(x,min(y,z))+1;
//	return res2;
//}

int min1(int n,int *arr)		//memoising recursion
{
	if(n<=1)		//here arr is storing minimum of x,y,z
	{
		return 0;
	}
	if(arr[n]!=-1)
	{
		return arr[n];
	}
	
	int x=min1(n-1,arr);
	
	int y=INT_MAX,z=INT_MAX;
	
	if(n%2==0)
	{
		y=min1(n/2,arr);
	}
	if(n%3==0)
	{
		z=min1(n/3,arr);
	}
	int res2=min(x,min(y,z))+1;

	arr[n]=res2;

	return res2+1;
}

int minto1(int n)
{
	int *arr=new int[n+1];
	for(int i=0;i<n;i++)
	{
		arr[i]=-1;
	}
	return min1(n,arr);
}

int main()
{
	int n;
	cin>>n;
	cout<<minto1(n);
}
