#include<iostream>
#include"mymap.h"
using namespace std;

int main()
{
    mymap<int> map1;
    for(int i=0;i<5;i++)
    {
        char c='0'+i;
        string key="abc";
        key=key+c;
        int value=i+1;
        map1.insert(key,value);
    }
    cout<<map1.size();

}