#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main()
{
	unordered_map<string,int>ourmap;
	
	//insertion
	
	pair<string,int>p("abc",1);   //method 1 for insertion
	ourmap.insert(p);
	
	ourmap["def"]=2;				//method 2 for insertion
	
	//find/access
	
	cout<<ourmap["def"]<<endl;			//accessing method 1
	cout<<ourmap.at("def")<<endl;			//accessing method 2
	cout<<"size:"<<ourmap.size()<<endl;

		// cout<<ourmap.at("ghi")<<endl; 	//give message key not found
	cout<<ourmap["ghi"]<<endl;				//this will add absent key and set default value to zero
	cout<<"size:"<<ourmap.size()<<endl;


	//to check presence
	if(ourmap.count("ghi")>0)
	{
		cout<<"ghi is present";
	}

	//to erase/delete
	ourmap.erase("ghi");
	cout<<endl;
	cout<<"size:"<<ourmap.size()<<endl;





}

