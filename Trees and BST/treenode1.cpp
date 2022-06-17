  #include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class treeNode
{
	public:
		T data;
		vector<treeNode*> children;
		treeNode(T data)
		{
			this->data=data;
			
		 } 
		
};

treeNode<int>*takeinputlevelwise()
{
	int rootdata;
	cout<<"enter root data: ";
	cin>>rootdata;
	treeNode<int>*root=new treeNode<int>(rootdata);
	queue<treeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size()!=0)
	{
		treeNode<int>*front=pendingNodes.front();
		pendingNodes.pop();
		int n;
		cout<<"enter no. of childrem of root "<<front->data<<" : ";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int childdata;
			cout<<"enter data of "<<i<<" th child: ";
			cin>>childdata;
			treeNode<int>*child=new treeNode<int>(childdata);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}
/*
treeNode<int>*takeinput()
{
int rootdata;
cout<<"enter root data: ";
cin>>rootdata;
treeNode<int>*root=new treeNode<int>(rootdata);

int n;
cout<<"enter number of child: ";
cin>>n;

for(int i=0;i<n;i++)
{
	treeNode<int>*child=takeinput();
	root->children.push_back(child);
}

	return root;
}
void printTree(treeNode<int>*root)
{
	cout<<root->data<<" : ";
	for(int i=0;i<root->children.size();i++)
	{
		cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++)
	{
		printTree(root->children[i]);
	}
}
*/

void printlevel(treeNode<int>*root)
{
	queue<treeNode<int>*> pn;
	pn.push(root);
	while(pn.size()!=0)
	{
		treeNode<int>* front = pn.front();
		pn.pop();
		cout<<front->data<<": ";
		for(int i=0;i<front->children.size();i++)
		{
			cout<<front->children[i]->data<<",";
			pn.push(front->children[i]);
		}
		cout<<endl;
	}
	
}
int numberofnodes(treeNode<int>*root)
{
	int ans=1;
	for(int i=0;i<root->children.size();i++)
	{
		ans+=numberofnodes(root->children[i]);
	}
	return ans;
}

int printlevelsum(treeNode<int>*root)
{
	int sum=0;
	queue<treeNode<int>*> pn;
	pn.push(root);
	while(pn.size()!=0)
	{
		treeNode<int>* front = pn.front();
		sum+=front->data;
		pn.pop(); 
		
		for(int i=0;i<front->children.size();i++)
		{
		
			pn.push(front->children[i]);
		}
		cout<<endl;
	}
	return sum;
	
}
//	treeNode<int>*max1=NULL;
//	
//	void maximumNode(treeNode<int>*root)
//	{
//		if(root==NULL)
//			return ;
//		
//		if((max1)==NULL)
//			{
//				max1==root;
////				return maximum->data;
//			}
//		
//		else if(root->data>(max1->data))
//		{
//			max1=root;
////			return maximum->data;
//			}	
//		for(int i=0;i<root->children.size();i++)
//		{
//			maximumNode(root->children[i]);
//			}	
//	}

	int height(treeNode<int>*root)
	{
		queue<treeNode<int>*> q;
		q.push(root);
		q.push(NULL);
		int ctr=0;
		while(!q.empty())
		{
			treeNode<int>* front=q.front();
			q.pop();
			if(front==0)
			{
					ctr++;
			if(!q.empty())
			{
				q.push(0);
				}
			}
			else
			{
				for(int i=0;i<front->children.size();i++)
				{
					q.push(front->children[i]);
				}
			}
					
		}
		return ctr;
	}
	
	void printatlevel(treeNode<int>* root,int pos)
	{
		if(pos==0)
		{
			cout<<root->data<<endl;
			return;
		}
		else
		{
			for(int i=0;i<root->children.size();i++)
			{
				printatlevel(root->children[i],pos-1);
			}
		}
		
	}
	
	int leafnodes(treeNode<int>*root)
	{
		int max1=0;
		if(root->children.size()==0)
		return 1;
		else
		{
			for(int i=0;i<root->children.size();i++)
			{
				max1+= leafnodes(root->children[i]);
			}
		}
		return max1;
	}
	bool searchvar(treeNode<int>*root,int checkdata)
	{
		queue<treeNode<int>*> pn;
		pn.push(root);
		while(pn.size()!=0)
		{
		treeNode<int>* front = pn.front();
		if(front->data==checkdata)
		{
			return true;
			break;
		}
		pn.pop();
		
		for(int i=0;i<front->children.size();i++)
		{
		
			pn.push(front->children[i]);
		}
		cout<<endl;
		}
		return false;
		
	}
	
int countnodes(treeNode<int>*root, int x)
{
	int ctr=0;
	queue<treeNode<int>*> pn;
	pn.push(root);
	while(pn.size()!=0)
	{
		treeNode<int>* front = pn.front();
		if(front->data>x)
		{
			ctr++;
		}
		pn.pop();
		
		for(int i=0;i<front->children.size();i++)
		{
		
			pn.push(front->children[i]);
		}
		cout<<endl;
	}
	return ctr;
	
}
	bool identicalstructure(treeNode<int>*root1 ,treeNode<int>*root2)
	
{	if(numberofnodes(root1)!=numberofnodes(root2))
	{
		return false;
	}
	else
	{
		queue<treeNode<int>*> pn;
		queue<treeNode<int>*> tn;
		pn.push(root1);
		tn.push(root2);
		while(pn.size()!=0 || tn.size()!=0)
		{
		treeNode<int>* front1 = pn.front();
		treeNode<int>* front2 = tn.front();
		if(front1->data!=front2->data)
		{
			return false;
			break;
		}
		pn.pop();
		tn.pop();
		
		for(int i=0;i<front1->children.size();i++)
		{	
			pn.push(front1->children[i]);
		}
		for(int j=0;j<front2->children.size();j++)
		{	
			tn.push(front2->children[j]);
		}
		cout<<endl;
		}
	}

	return true;
}
	void nextlargernumber(treeNode<int>*root,int x,treeNode<int>**res )
	{
		if(root->data>x)
			if(!(*res)||(*res)->data>root->data)
				(*res)=root;
		
		
			for(int i=0;i<root->children.size();i++)
			{
				nextlargernumber(root->children[i],x,res);
			}
			return;
	}
	
	treeNode<int>*nextlarge(treeNode<int>*root,int x)
	{
		treeNode<int>*res=NULL;
		nextlargernumber(root,x,&res);
		return res;
	}
	void replacedepth(treeNode<int>*root,int depth)
	{
		root->data=depth;
		for(int i=0;i<root->children.size();i++)
		{
			replacedepth(root->children[i],depth+1);
		}
		
	}
	void helperfunction(treeNode<int>*root)
	{
//		int depth=0;
		replacedepth(root,0);
		
		
	}

	//1 2 3 5 2 7 8 0 0 0 
int main()
{
//	treeNode<int>*root=new treeNode<int>(1);
//	treeNode<int>*node1=new treeNode<int>(2);
//	treeNode<int>*node2=new treeNode<int>(3);
//	
//	root->children.push_back(node1);
//	root->children.push_back(node2);
//	
//	treeNode<int>*node3=new treeNode<int>(4);
//	
//	root->children.push_back(node3);
//	
//	treeNode<int>*node4=new treeNode<int>(5);
//	node1->children.push_back(node4);
	
	treeNode<int>*root;

	//treeNode<int>*root1;
	
//	root=takeinput();
	cout<<"input for tree 1"<<endl;
	root=takeinputlevelwise();
//	cout<<"\ninput for tree 2"<<endl;
//	root1=takeinputlevelwise();
//	printTree(root);

	printlevel(root);

	cout<<"nomber of nodes are "<<numberofnodes(root);

	cout<<"sum of all node is "<<printlevelsum(root);

//	maximumNode(root);

//	cout<<"max is "<<max1->data;

	cout<<"\nheight is "<<height(root)<<endl; 

	printatlevel(root,2);

	int max1=0;

	cout<<"\nno. of leaf node is "<<leafnodes(root);
	
	bool ans=searchvar(root,4);

	if(ans==1)

	cout<<"\ntrue";

	else

	cout<<"false";
	
	cout<<"\nnumber of nodes greater than "<<2<<" is "<<countnodes(root,2)<<endl; 
	
//	bool idans=identicalstructure(root,root1);
//	if(idans==0)
//	cout<<"\ndifferent\n";
//	else
//	cout<<"\nsame\n";
//	
cout<<"next larger node is "<<nextlarge(root,3)->data;

helperfunction(root);
printlevel(root);
	return 0;
}
