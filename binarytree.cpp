#include<iostream>
#include<queue>
using namespace std;

template <typename T>

class BinaryNodeTree
{
	public:
		T data;
		BinaryNodeTree* left;
		BinaryNodeTree* right;
	BinaryNodeTree(T data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
	~BinaryNodeTree()
	{
		delete left;
		delete right;
	}
};
void printTree(BinaryNodeTree<int>*root)
{
	if(root==NULL)
	return;
	cout<<root->data<<" : ";
	if(root->left!=NULL)
	{
		cout<<"L"<<root->left->data;
	}
	if(root->right!=NULL)
	{
		cout<<"R"<<root->right->data;
	}
	cout<<endl;
	printTree(root->left);
	printTree(root->right);
}
BinaryNodeTree<int>* takeinput()
{
	int rootdata;
	cout<<"enter rootdata: ";
	cin>>rootdata;
	if(rootdata==-1)
	{
	return NULL;
	}
	BinaryNodeTree<int>*root=new BinaryNodeTree<int>(rootdata);
	BinaryNodeTree<int>*leftchild=takeinput();
	BinaryNodeTree<int>*rightchild=takeinput();
	root->left=leftchild;
	root->right=rightchild;
	return root;
}
BinaryNodeTree<int>* takeinputlevelwise()
{
	int rootdata;
	cout<<"enter rootdata: ";
	cin>>rootdata;
	if(rootdata==-1)
	{
	return NULL;
	}
	BinaryNodeTree<int>* root=new BinaryNodeTree<int>(rootdata);
	queue<BinaryNodeTree<int>*> pn;
	pn.push(root);
	while(pn.size()!=0)
	{
		BinaryNodeTree<int>*front=pn.front();
		pn.pop();
		int leftchild;
		cout<<"enter left child of "<<front->data;
		cin>>leftchild;
		if(leftchild!=-1)
		{
			BinaryNodeTree<int>*child=new BinaryNodeTree<int>(leftchild);
			front->left=child;
			pn.push(child);
		}
		int rightchild;
		cout<<"enter right child of "<<front->data;
		cin>>rightchild;
		if(rightchild!=-1)
		{
			BinaryNodeTree<int>*child1=new  BinaryNodeTree<int>(rightchild);
			front->right=child1;
			pn.push(child1);
		}
	}
	return root;
}

//printing level wise

void printlevelwise(BinaryNodeTree<int>*root)
{
	queue<BinaryNodeTree<int>*> pn;
	pn.push(root);
	cout<<root->data;
	while(pn.size()!=0)
	{
		BinaryNodeTree<int>*front=pn.front();
		pn.pop();
		
		if(front->left!=NULL)
		{
			cout<<front->left->data;
			pn.push(front->left);
			cout<<endl;
		}
		cout<<endl;
		if(front->right!=NULL)
		{
			cout<<front->right->data;
			pn.push(front->right);
			cout<<endl;
		}
		
	}
}
	//counting of nodes
	int countbinarynodes(BinaryNodeTree<int>*root)
{
	queue<BinaryNodeTree<int>*> pn;
	pn.push(root);
	int ctr=0;
	while(pn.size()!=0)
	{
		BinaryNodeTree<int>*front=pn.front();
		pn.pop();
		cout<<endl<<front->data<<": ";
		if(front->left!=NULL)
		{
			ctr++;
			pn.push(front->left);
		}
	
		if(front->right!=NULL)
		{
			ctr++;
			pn.push(front->right);
		}
		cout<<endl;
	}
	return ctr+1;	
}

//searching of node
	bool searchbinarynodes(BinaryNodeTree<int>*root,int snode)
{
	queue<BinaryNodeTree<int>*> pn;
	pn.push(root);
	
	while(pn.size()!=0)
	{
		BinaryNodeTree<int>*front=pn.front();
		pn.pop();

		if(front->left!=NULL)
		{
			
			pn.push(front->left);
			if(snode==front->left->data)
			{
				return true;
				break;
			}
		}
	
		if(front->right!=NULL)
		{
			pn.push(front->right);
			if(snode==front->right->data)
			{
				return true;
				break;
			}
		}
		cout<<endl;
	}
	return false;	
}
//height of tree;

int HeightOfTree(BinaryNodeTree<int>*root)
{
	queue<BinaryNodeTree<int>*> pn;
	pn.push(root);
	pn.push(NULL);
	int ctr=0;
	while(pn.size()!=0)
	{
		BinaryNodeTree<int>*front=pn.front();
		pn.pop();
		
		if(front==NULL)
		{
			ctr++;
			if(pn.size()!=0)
			{
				pn.push(NULL);
			}
		}
		else
		{
				if(front->left!=NULL)
		{
			
			pn.push(front->left);
			
		}
	
		if(front->right!=NULL)
		{
			pn.push(front->right);
			
		}
		
		}

	
	}
	return ctr;	
}

//mirror of tree

void printmirror(BinaryNodeTree<int>*root)
{
	if (root==NULL)
	return;
	else
	{
		printmirror(root->left);
		printmirror(root->right);
		BinaryNodeTree<int>*temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
}
void Preordertraversal(BinaryNodeTree<int>*root)
{
	if(root==NULL)
	return;
	cout<<"\n"<<root->data<<" ";
	Preordertraversal(root->left);
	Preordertraversal(root->right);
}
void Postordertraversal(BinaryNodeTree<int>*root)
{
	if(root==NULL)
	return;
	
	Postordertraversal(root->left);
	Postordertraversal(root->right);
	cout<<"\n"<<root->data<<" ";
}
void Inordertraversal(BinaryNodeTree<int>*root)
{
	if(root==NULL)
	return;
	
	Inordertraversal(root->left);
	cout<<"\n"<<root->data<<" ";
	Inordertraversal(root->right);
}
int search(int arr[],int s,int e,int data)
{
	for(int i=s;i<e;i++)
	{
		if(arr[i]==data)
		{
			return i;
			break;
		}
	}
}
 BinaryNodeTree<int>* builtTree(int pre[],int In[],int start,int end)
{
	static int prenodeindex=0;
	if(start>end)
	{
		return NULL;
	}
	BinaryNodeTree<int>*temp=new BinaryNodeTree<int>(pre[prenodeindex++]);
	if(start==end)
	{
		return temp;
	}
	int inindex=search(In,start,end,temp->data);

	temp->left=builtTree(pre,In,start,inindex-1);
	temp->right=builtTree(pre,In,inindex+1,end);
	
	return temp;
	
}
pair<int,int>heightdiameter(BinaryNodeTree<int>*root)
{
	if(root==NULL)
	{
		pair<int,int>p;
		p.first=0;
		p.second=0;
		return p;	
	}
	pair<int, int> leftans=heightdiameter(root->left);
	pair<int, int> rightans=heightdiameter(root->right);
	
	int lh=leftans.first;
	int ld=leftans.second;
	int rh=rightans.first;
	int rd=rightans.second;
	int height=1+max(lh,rh);
	int diameter=max(lh+rh,max(ld,rd));
	pair<int,int>p;
		p.first=height;
		p.second=diameter;
		return p;
}

//1 2 3 4 5 6 -1 7 -1 -1 -1 -1 -1 -1 -1

int main()
{
//	BinaryNodeTree<int>*root=new BinaryNodeTree<int>(1);
//	BinaryNodeTree<int>*node1=new BinaryNodeTree<int>(2);
//	BinaryNodeTree<int>*node2=new BinaryNodeTree<int>(3);
//	root->left=node1;
//	root->right=node2;
//----------------------------------------------------------
//	BinaryNodeTree<int>* root;/
//	root=takeinputlevelwise();
//	printlevelwise(root);

//	cout<<"no of nodes are "<<countbinarynodes(root)<<endl;	//counting	

/*															//searching
	bool ans=searchbinarynodes(root,15);
	if(ans)
	cout<<"node is found"<<endl;
	else
	cout<<"node not found"<<endl;
*/

//	cout<<"\nheight of the node is "<<HeightOfTree(root);	//height
//
//	printmirror(root);										//mirror image
//	printlevelwise(root);
//	cout<<"\nPreordertraversal"<<endl;
//	Preordertraversal(root);
//	
//	cout<<"\nPostordertraversal"<<endl;
//	Postordertraversal(root);
//	
//	cout<<"\nInordertraversal"<<endl;
//	Inordertraversal(root);

//	printlevelwise(root);

//int arr1[7]={1 , 2 , 4 ,5 ,3 ,6 ,7 };	//pre
//int arr2[7]={4 ,2 , 5 , 1 , 6 , 3 , 7};	//in
//BinaryNodeTree<int>* root1=builtTree(arr1,arr2,0,6);
//printlevelwise(root1);
	BinaryNodeTree<int>* root;
	root=takeinputlevelwise();
//	printlevelwise(root);
	pair<int,int>p;
	cout<<"\nheight is"<<p.first<<endl;
	cout<<"\ndiameter is"<<p.second<<endl;

	return 0;
}

