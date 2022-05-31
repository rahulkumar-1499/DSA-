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
			this->next=NULL;
		}
	
};
Node* takedata()
{
	int data;
	cout<<"enter data\n";
	cin>>data;
	Node*head=NULL;
	Node*tail=NULL;
	while(data!=-1)
	{
		Node*newnode=new Node(data);
		if(head==NULL)
		{
			head=newnode;
			tail=newnode;
		}
		
		else
		{
			tail->next=newnode;
			tail=tail->next;
		}
		cout<<"enter data \n";
		cin>>data;
	}
	return head;
}
void printdata(Node*head)
{
	if(head==NULL)
	{
		cout<<"list is empty";
	}
	else
	{
		Node* temp=head;
		cout<<"displaying data\n";
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
}

//void mergesortlinkedlist(Node*h11,Node*h22)
//{
//	Node*fh=NULL,*ft=NULL;
//	Node*h1=h11,*h2=h22;
//	if(h1->data<h2->data)
//	{
//		fh=ft=h1;
//		while(h1!=NULL || h2!=NULL)
//		{
//			if(h1->data>h2->data)
//			{
//				ft->next=h2;
//				ft=h2;
//				h2=h2->next;
//			}
//			else
//			{
//				ft->next=h1;
//				ft=h1;
//				h1=h1->next;
//			}
//		}
//		if(h1==NULL)
//		{
//			ft->next=h2;
//		}
//		else
//		{
//			ft->next=h1;
//		}
//		Node*temp=fh;
//		while(fh!=NULL)
//		{
//			cout<<"merged array is: ";
//			cout<<fh->data<<" ";
//			fh=fh->next;
//		}
//	}
//	
//}
void printithelement(Node*head)
{

	int ctr=0,pos;

	cout<<"enter position: ";

	cin>>pos;

	if(head==NULL)

	cout<<"list is empty";

	else
	{
		Node*temp=head;

		while(temp!=NULL)
		{
			ctr++;
			if(ctr==pos)
			{
				cout<<temp->data<<endl;
				break;
			}
			temp=temp->next;
			
		}
	}
}
void midvalue(Node* head,Node**first,Node**second)
{
	Node*slow=head,*fast=head->next;
	
	while(fast!=NULL)
	{
		fast=fast->next;
	
		if(fast!=NULL)
		{
			fast=fast->next;
			slow=slow->next;
		}
		 
	}
	 
	*first=head;
	
	*second=slow->next;
	
	slow->next=NULL; 
}

Node*mergeboth(Node*first,Node*second)
{
	Node*answer=NULL;

	if(!first)
	return second;

	else if(!second)
	return first;
	
	if(first->data<=second->data)
	{
		answer=first;
		answer->next=mergeboth(first->next,second);
	}

	else
	{
		answer=second;
		answer->next=mergeboth(first,second->next);
	}

return answer;	
	
}

void mergesorting(Node**head)
{
	Node*curr=*head;
	
	Node*first,*second;
	
	if(curr==NULL || curr->next==NULL)
	
	return;
	
	midvalue(curr,&first,&second);
	
	mergesorting(&first);
	
	mergesorting(&second);
	
	*head=mergeboth(first,second);
	
}
//Node* recursivereverse(Node*temp)
//{
//	if(temp==NULL || temp->next==NULL)
//	return temp;
//	
//		Node *ans=recursivereverse(temp->next);
//		Node*head=ans;
//		while(head!=NULL)
//		{
//			head=head->next;
//		}
//		head->next=temp;
//		temp->next=NULL;
//		return ans;	
//	
//}


int main()
{
	Node*temp1=takedata();
	
//	Node*temp2=takedata();

//	printdata(temp1);

//	printdata(temp2);

//	mergesortlinkedlist(temp1,temp2);

//	printithelement(temp1);

//midvalue(temp1);

//	mergesorting(&temp1);
	
//	printdata(temp1);
//	recursivereverse(temp1);	
//	printdata(temp1);
	return 0;
}
