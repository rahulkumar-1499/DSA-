#include<iostream>
using namespace std;


//DP use

int mincostDP(int **arr,int m,int n)
{
	int **output=new int*[m];
	for(int i=0;i<m;i++)
	{
		output[i]=new int[n];
	}
	output[m-1][n-1]=arr[m-1][n-1];
	for(int j=n-2;j>=0;j--)
	{
		output[m-1][j]=arr[m-1][j]+output[m-1][j+1];
	}
	for(int i=m-2;i>=0;i--)
	{
		output[i][n-1]=arr[i][n-1]+output[i+1][n-1];
	}
	for(int i=m-2;i>=0;i--)
	{
		for(int j=n-2;j>=0;j--)
		{
			output[i][j]=arr[i][j]+min(output[i][j+1],
			min(output[i+1][j+1],output[i+1][j]));
		}
	}
	return output[0][0];
	
}

//memoising recursion

int mincost(int **dummy,int **arr,int m,int n,int i,int j)
{
	if(i==m-1 && j==n-1)
	{
		return arr[i][j];
	}
	
	if(i>=m || j>=n)
	{
		return INT_MAX;
	}
	if(dummy[i][j]!=INT_MAX)
	{
		return dummy[i][j];
	}
	int x=mincost(dummy,arr,m,n,i,j+1);
	int y=mincost(dummy,arr,m,n,i+1,j+1);
	int z=mincost(dummy,arr,m,n,i+1,j);
	
	int a=min(x,min(y,z))+arr[i][j];
	
	dummy[i][j]=a;
	
	return a;
}



int mincost(int **arr,int m,int n)
{
	int **dummy=new int*[m];
	for(int i=0;i<m;i++)
	{
		dummy[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			dummy[i][j]=INT_MAX;
		}
	}
	return mincost(dummy,arr, m, n,0,0);
}

int main()
{
	int m,n;
	cout<<"enter row and column: ";
	cin>>m>>n;
	int **arr=new int*[m];
	for(int i=0;i<m;i++)
	{
		arr[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	cout<<"minimum cost path using memoising is "<<mincost(arr,m,n)<<endl;
	cout<<"minimum cost path using DP is "<<mincostDP(arr,m,n);

}
