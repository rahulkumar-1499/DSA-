#include<iostream>
using namespace std;

class dynamicarraywithQueue
{
	int *data;
	int index,capacity,firstindex,size;
	public:
		arraywithQueue()
		{
			this->capacity=5;
			data=new int[capacity];
			index=0;
			firstindex=-1;
			size=0;
		}
		void enqueue(int elt)
		{
			if(size==capacity)
			{
				int *newdata=new int[2*capacity];
				int j=0;
				for(int i=firstindex;i<capacity;i++)
				{
					newdata[j]=data[i];
					j++;
				}
				for(int i=0;i<firstindex;i++)
				{
					newdata[j]=data[i];
					j++;
				}
				delete []data;
				data=newdata;
				firstindex=0;
				index=capacity;
				capacity*=2;
			}
			data[index]=elt;
			index=(index+1)% capacity;
			if(firstindex==-1)
			{
				firstindex=0;
			}
			size++;
		}
		int getsize()
		{
			return size;
		}
		bool checkempty()
		{
			return size==0;
		}
			
		void front()
		{
			if(checkempty())
			cout<<"list is empty"<<endl;
			else
			cout<<"front data is "<<data[firstindex];
			
		}
		void dequeue()
		{
			if(checkempty())
			{
				cout<<"list is empty"<<endl;	
			}
			
			
			
			cout<<"popped data is "<<data[firstindex];
			firstindex= firstindex % capacity;
			size--;	
			if(size==0)
			{
				firstindex=-1;
				index=0;
			}
			
			
					
		}
	
};
	
	int main()
	{
		dynamicarraywithQueue obj1;
	
	int ch=0,data1,size1=0;
	bool check;
	while(ch!=6)
	{
		cout<<"\n1.enqueue\n2.dequeue\n3.front\n4.size\n5.empty"<<endl;
		cout<<"enter your choice(1-5): ";
		cin>>ch;
		switch(ch)
		{
				case 1:
				cout<<"enqueue"<<endl;
				cout<<"enter data to push: ";
				cin>>data1;
				obj1.enqueue(data1);
//				cout<<"data pushed successfully"<<endl;
				break;
			
			case 2:
			cout<<"dequeue"<<endl;
			obj1.dequeue();
//			cout<<"data popped successfully"<<endl;
			break;	
			
			case 3:
				cout<<"front element "<<endl;
				obj1.front();
				break;
			case 4:
			cout<<"size of list"<<endl;
			size1=obj1.getsize();
			cout<<"size of list is"<<size1<<endl;
				break;
			case 5:
			cout<<"check empty"<<endl;
			check=obj1.checkempty();
			if(check)
			cout<<"true"<<endl;
			else
			cout<<"false"<<endl;
			break;
			default:
				break;
					
		}
	}
		
		
		return 0;
	}
