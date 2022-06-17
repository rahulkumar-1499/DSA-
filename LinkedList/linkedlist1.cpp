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
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
}

int lengthlinkedlist(Node*head)
{
	int ctr=0;
	if(head==NULL)
	cout<<"list is empty";
	else
	{
		Node*temp=head;
		while(temp!=NULL)
		{
			ctr++;
			temp=temp->next;
		}
		return ctr;
	}
	
}
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

void insertnodeatithposition(Node*head)
{
	int ctr=0,pos,datas,count=0;
	
	cout<<"enter position for insertion: ";
	cin>>pos;
	if(head==NULL)
	cout<<"list is empty";
	else
	{
		count=lengthlinkedlist(head);
		if(count<=pos)
		{
			Node*temp=head;
		cout<<"enter datas ";
		cin>>datas;
		Node*newnode=new Node(datas);
		while(ctr<pos-2)
		{
			temp=temp->next;
			ctr++;
		}
	Node*wait=temp->next;
		temp->next=newnode;
		newnode->next=wait;
		cout<<"node added successfully"<<endl;
		}
		else
		cout<<"position is greater than total elements"<<endl;
		
	
	}

}

/*
void deletenode(Node*head)
{
	int pos,count,ctr=0;
	cout<<"enter position for deletion: ";
	cin>>pos;
	if(head==NULL)
	cout<<"list is empty"<<endl;
	else
	{
		count=lengthlinkedlist(head);
		if(count<=pos)
		{
			Node*temp=head;
			while(ctr<pos-1)
			{
				temp=temp->next;
			}
			Node*vari=temp->next;
			temp->next=vari->next;
			delete vari;
			cout<<"deletion completed";
		}
		
	}
}*/
int recurselength(Node*head)
{
	
	if(head==NULL)
	return 0;
	
	else
	{
		Node*temp=head;
		return 1+recurselength(temp->next);
		
	}
}
void nodefinder(Node*head)
{
	int selt,ctr=0;
	cout<<"enter element to be searched: ";
	cin>>selt;
	if(head==NULL)
	cout<<"no element present";
	if(head->data==selt)
	cout<<"element is found at 0 position";
	else
	{
		Node*temp=head;
		while(temp!=NULL)
		{
			ctr++;
			if(selt==temp->data)
			{
				cout<<"occured at position "<<ctr-1;
				break;
				
			}
			temp=temp->next;
		}
	}
}
void getfirstN(Node*head){
	int n,count,ctr=0;
	count=lengthlinkedlist(head);
	cout<<"enter N :";
	cin>>n;
	Node*temp=head;
	while(ctr<=count-n-1)
	{
		ctr++;
		temp=temp->next;
	}
	Node*temp1=temp;
	while(temp1!=NULL)
	{
		cout<<temp1->data<<" ";
		temp1=temp1->next;
	}
	Node*head1=head;
	while(head1!=temp)
	{
		cout<<head1->data<<" ";
		head1=head1->next;
	}


}
Node* reverselist(Node*head)
{
	Node*current=head;
	Node*varhead=head;
	Node*nexts=NULL,*prev=NULL;
	while(current!=NULL)
	{
		nexts=current->next;
		current->next=prev;
		prev=current;
		current=nexts;
	}
	varhead=prev;
	return varhead;

}
//
//void pallindromecheck(Node*head)
//{
//	Node* h1=head;
//	Node*h2;
//	int ctr=0;
//	int count=recurselength(head);
//	if(count%2==0)
//	{
//		while(ctr!=count/2)
//		{
//			h1=h1->next;
//		}
//		h2=h1->next;
//		h1->next=NULL;
//		Node*h2=reverselist(h2);
//		while(h2!=NULL)
//		{
//			if(h1->data==h2->data)
//			{
//				h1=h1->next;
//				h2=h2->next;
//			}
//			else
//			{
//				cout<<"not pallindrome";
//			}
//		}
//	}
//	else
//	{
//		while(ctr!=(count+1)/2)
//		{
//			h1=h1->next;
//		}
//		h2=h1->next;
//		h1->next=NULL;
//		Node*rev=reverselist(h2);
//		while(rev!=NULL)
//		{
//			if(h1->data==rev->data)
//			{
//				h1=h1->next;
//				rev=rev->next;
//			}
//			else
//			{
//				cout<<"not pallindrome";
//			}
//		}
//		
//	}
//}
//
//void middata(Node*head)
//{
//	if(head==NULL)
//	cout<<"error";
//	else
//	{
//		Node*slow=head;
//		Node*fast=head;
//		while(fast!=NULL)
//		{
//			slow=slow->next;
//			fast=fast->next->next;
//		}
//		cout<<"mid data is "<<slow->data;
//	}
//	
//}

int main()
{
	Node *temp=takedata();
//	printdata(temp);
//	int ctr=lengthlinkedlist(temp);
//	cout<<"total elements present in list is "<<ctr<<endl;
//	printithelement(temp);
//	insertnodeatithposition(temp);
//	printdata(temp);
//	deletenode(temp);
//	printdata(temp);
//cout<<"totla elementusing recursion is is"<<recurselength(temp);
//nodefinder(temp);
//getfirstN(temp);
//eleminateduplicate(temp);
//Node* varhead=reverselist(temp);
//printdata(varhead);
//printdata(temp);
//pallindromecheck(temp);
//middata(temp);
	return 0;
}
