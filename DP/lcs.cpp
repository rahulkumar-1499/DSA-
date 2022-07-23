#include<iostream>
#include<string.h>
using namespace std;

int lcs(string s,string t )		//normal recursion
{
	if(s.size()==0 || t.size()==0)
	{
		return 0;
	}
	if(s[0]==t[0])
	{
		return 1+lcs(s.substr(1),t.substr(1));
	}
	else
	{
		int x=lcs(s.substr(1),t);
		int z=lcs(s,t.substr(1));
		return max(x,z);
	}
	
	
}
//memoising recursion

int lcshelper(string s,string t,int **arr )
{
	int m=s.size();
	int n=t.size();
	if(s.size()==0 || t.size()==0)
	{
		return 0;
	}
	if(arr[m][n]!=INT_MIN)
	{
		return arr[m][n];
	}
	int ans;						//arr[i][j]=lcs of s(len i) & t(len j)
	if(s[0]==t[0])
	{
		ans= 1+lcshelper(s.substr(1),t.substr(1),arr);
	}
	
	else
	{
		
		int x=lcshelper(s.substr(1),t,arr);
		int y=lcshelper(s.substr(1),t.substr(1),arr);
		int z=lcshelper(s,t.substr(1),arr);
		 ans= max(x,max(y,z));
	
	}
		arr[m][n]=ans;
		return ans;
	
}
int lcsmemo(string s,string t)
{
	int m=s.size();
	int n=t.size();
	int **arr=new int*[m+1];
	for(int i=0;i<=m;i++)
	{
		arr[i]=new int[n+1];	//n+1 becz [0,n] both included
		for(int j=0;j<=n;j++)
		{
			arr[i][j]=INT_MIN;
		}
		
	}
	return lcshelper(s,t,arr);
}

//DP iteration

int lcsDP(string s,string t)
{
	int m=s.size();
	int n=t.size();
	int **arr=new int*[m+1];
	for(int i=0;i<m+1;i++)
	{
		arr[i]=new int[n+1];
	}
	for(int j=0;j<n+1;j++)
	{
		arr[0][j]=0;
	}
	for(int i=1;i<m+1;i++)
	{
		arr[i][0]=0;
	}
	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(s[m-i]==t[n-j])
			{
				arr[i][j]=arr[i-1][j-1]+1;
			}
			else
			{
				arr[i][j]=max(arr[i-1][j-1],max(arr[i][j-1],arr[i-1][j]));
			}
		}
	}
	return arr[m][n];
	
	
}
int main()
{
	string s,t;
	cout<<"s: ";
	cin>>s;
	cout<<"t: ";
	cin>>t;
	cout<<"lcs by simple recursion: "<<lcs(s,t)<<endl;
	cout<<"lcs by memoising recursion: "<<lcsmemo(s,t)<<endl;
	cout<<"lcs by DP iteration: "<<lcsDP(s,t);
}
