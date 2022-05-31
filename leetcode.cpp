#include<iostream>
using namespace std;

int checkduplicate(int *arr,int size)
{
	int sum1=0;
        int sum2=0;
        for(int i=0;i<size;i++)
        {
            sum1+=*(arr+i);
        }
//        return sum1;
        int a=size;
        int b=size-1;
        sum2=(a*b)/2;
        int sum3=sum1-sum2;
	     return sum3;
	
}
int main()
{
	 int arr[]={3,1,3,4,2};
	
	cout<<checkduplicate(arr,5);
	return 0;
}
