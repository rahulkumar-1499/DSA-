#include<iostream>
using namespace std;
bool findX(int *arr,int s,int x)
{
    if(s==0)
    {
        return false;
    }
    if(arr[0]==x)
    {
        return true;
    }
    bool check=findX(arr+1,s-1,x);
    return check;
}
int main()
{
    int arr[]={1,2,7,4,5};
    int s=5;
    int x=4;
    bool ans= findX(arr,s,x);
    if(ans)
    {
        cout<<"found";
    }
    else
    {
        cout<<"not found";
    }
}