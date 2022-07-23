#include<iostream>
#include<cmath>
using namespace std;

int balancetreeheight1(int *arr,int h)
{
	if(h<=1)
	return 1;
	
	//this is use when value is going above data type limit

	if(arr[h]!=INT_MAX)
	{
		return arr[h];
	}
	int mod=(int)(pow(10,9))+7;
	
	int x=balancetreeheight1(arr,h-1);
	int y=balancetreeheight1(arr,h-2);
	
	int ans1=(int)(((long)(x)*x)% mod);
	int ans2=(int)((2*(long)(x)*y)% mod);
	
	
	arr[h]=(ans1+ans2)%mod;
	
	return arr[h];
	
}
int balancetreeheight(int h)
{
	int*arr=new int[h+1];
	for(int i=0;i<h+1;i++)
	{
		arr[i]=INT_MAX;
	}
	return balancetreeheight1(arr,h);
}

int main()
{
	int h;
	cin>>h;
	cout<<"brute force: "<<balancetreeheight(h)<<endl;
	
}
