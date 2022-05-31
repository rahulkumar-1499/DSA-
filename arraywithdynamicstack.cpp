	#include<iostream>
using namespace std;

class arraywithdynamicstack
{
	int *data;
	int index,capacity;
		public:
		arraywithdynamicstack()
		{
			this->capacity=4;
			data=new int[4];
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
			if(index==capacity)
			{
				int *newdata=new int[2*capacity];
				for(int i=0;i<capacity;i++)
				{
					newdata[i]=data[i];
				}
				capacity=2*capacity;
				delete []data;
				data=newdata;
					
			}
			data[index]=elt;
				index++;
			
		
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
	arraywithdynamicstack obj1;
	
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
