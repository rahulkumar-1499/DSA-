#include<iostream>
using namespace std;

template<typename T>
class Node
{
	public:
		T data;
		Node<T>*next;
		Node(T data)
		{
			this->data=data;
			next=NULL;
		}
};
template<typename T>
class Stack
{
	Node<T>*head;
	T size;
	public:
		Stack()
		{
			head=NULL;
			size=0;
		}
	void push(T elt)
	{
		Node<T>*newnode=new Node<T>(elt);
		if(head==NULL)
		{
			head=newnode;
		}
		else
		{
			newnode->next=head;
			head=newnode;
		}
		size++;
	}
	void pop()
	{
		if(head==NULL)
		{
			cout<<"no pop can be performed"<<endl;
		}
		else
		{
			Node<T>*a=head;
			head=head->next;
			delete a;
			size--;
		}
	}
	int getsize()
	{
		cout<<"size is "<<size;
	}
	int gettop()
	{
		if(size==0)
		{
			return -1;
		}
		return head->data;
	}
};
int main()
{
	Stack <int>s;
	int ch=0,elt;
	while(ch!=3)
	{
		cout<<"\n1.push\n2.pop\n3.size\n4.top ";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"enter element: ";
					cin>>elt;
					s.push(elt);
					break;
			
			case 2:
					s.pop();
					break;
			
			case 3:
					s.getsize();
					break;
					
			case 4:
					cout<<"top element is "<<s.gettop();
					break;				
			default:
					continue;				
		}
	}
	
	return 0;
}
