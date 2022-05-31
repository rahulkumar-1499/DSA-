#include<iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node* next;
	Node(int data)
	{
		this->data=data;
		next=NULL;
	}
};

class Queue1
{
	Node*head,*tail;
	int size;
	public:
	Queue1()
	{
		head=NULL;
		tail=NULL;
		size=0;
		}	
	
	void enqueue(int elt)
	{
		Node*newnode=new Node(elt);
		if(head==NULL)
		{
			head=tail=newnode;
		}
		else
		{
			tail->next=newnode;
			tail=newnode;
		}
		size++;
		}
		
	int getsize()
	{
		return size;
		}	
	int front()
	{
		return head->data;
		}
	int rear()
	{
		return tail->data;
			}
	int dequeue()
	{
		if(head==NULL)
		return 0;
		int ans= head->data;
		head=head->next;
		size--;
		return ans;
	}		
			
};

int main()
{
//	int size,elt;
	Queue1 obj;
	obj.enqueue(2);
	obj.enqueue(3);
	obj.enqueue(4);	
	obj.enqueue(5);	
	obj.enqueue(6);	
	cout<<"size is "<<obj.getsize();
	cout<<"\nfront element is "<<obj.front();
	cout<<"\nrear element is "<<obj.rear();
	cout<<"\ndequeue element is "<<obj.dequeue();
	cout<<"size is "<<obj.getsize();
	cout<<"\nfront element is "<<obj.front();
	return 0;
}
