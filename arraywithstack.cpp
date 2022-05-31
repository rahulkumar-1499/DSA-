	#include<iostream>
using namespace std;

class arraywithstack
{
	int *data;
	int index,capacity;
		public:
		arraywithstack(int t_size)
		{
			this->capacity=t_size;
			data=new int[t_size];
			index=0;
		}
		int size()
		{
			return index;
		}
		bool checkempty()
		{
			return index==0;
		}
		void push(int elt)
		{
			if(index<capacity)
			{
					data[index]=elt;
				index++;
			}
			else
			{
				cout<<"list full";
			}
		
		}
		void pop()
		{
			if(index==0)
			{
				cout<<"list is empty"<<endl;
			}
			else
			{
				cout<<"element popped is "<<data[index-1]<<endl;
			index--;
			}
			
		}
		void top()
		{
			if(size()==0)
			{
				cout<<"list is empty"<<endl;
			}
			else
			{
				cout<<"element @ top is "<<data[index-1]<<endl;		
			}
		
		}
		
};
int main()
{
	arraywithstack obj1(5);
	
	int ch=0,data1,size1=0;
	bool check;
	while(ch!=6)
	{
		cout<<"1.push\n2.pop\n3.top\n4.size\n5.empty"<<endl;
		cout<<"enter your choice(1-5): ";
		cin>>ch;
		switch(ch)
		{
				case 1:
				cout<<"push"<<endl;
				cout<<"enter data to push: ";
				cin>>data1;
				obj1.push(data1);
//				cout<<"data pushed successfully"<<endl;
				break;
			
			case 2:
			cout<<"pop"<<endl;
			obj1.pop();
//			cout<<"data popped successfully"<<endl;
			break;	
			
			case 3:
				cout<<"top element "<<endl;
				obj1.top();
				break;
			case 4:
			cout<<"size of list"<<endl;
			size1=obj1.size();
			cout<<"size of list is"<<size1<<endl;
				break;
			case 5:
			cout<<"check empty"<<endl;
			check=obj1.checkempty();
			cout<<check<<endl;
			break;
			default:
				break;
					
		}
	}
	return 0;
}
