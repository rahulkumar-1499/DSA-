#include<iostream>
using namespace std;

int fibo2(int n,int *arr)
{
//    int a,b;
    if(n<=1)
    {
    	return 0;
	}
	if(n==2)
	return 1;
    
    if(arr[n]!=-1)
    {
        return arr[n];

    }
    
    int a=fibo2(n-1,arr);
    int b=fibo2(n-2,arr);
   
   
   
    arr[n]=a+b;

    return arr[n];

}
int fibo1(int n)
{
    int *ans=new int[n+1];
    for(int i=0;i<n;i++)
    {
        ans[i]=-1;
    }
    return fibo2(n,ans);
}

int main()
{
    int n;
    cout<<"enter n: ";
    cin>>n;
    cout<<"\nfibonacci numbers is: "<<fibo1(n);
}

