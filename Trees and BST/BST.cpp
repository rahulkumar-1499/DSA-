#include<iostream>
#include<queue>
using namespace std;

template <typename T>

class BST
{
	public:
		T data;
		BST* left;
		BST* right;
	BST(T data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
	~BST()
	{
		delete left;
		delete right;
	}
};
//----------------------------------------------------------------------
//input of binary tree

BST<int>* takeinputlevelwise()
{
	int rootdata;
	cout<<"enter rootdata: ";
	cin>>rootdata;
	if(rootdata==-1)
	{
	return NULL;
	}
	BST<int>* root=new BST<int>(rootdata);
	queue<BST<int>*> pn;
	pn.push(root);
	while(pn.size()!=0)
	{
		BST<int>*front=pn.front();
		pn.pop();
		int leftchild;
		cout<<"enter left child of "<<front->data;
		cin>>leftchild;
		if(leftchild!=-1)
		{
			BST<int>*child=new BST<int>(leftchild);
			front->left=child;
			pn.push(child);
		}
		int rightchild;
		cout<<"enter right child of "<<front->data<<": ";
		cin>>rightchild;
		if(rightchild!=-1)
		{
			BST<int>*child1=new  BST<int>(rightchild);
			front->right=child1;
			pn.push(child1);
		}
	}
	return root;
}


	void CopyLeftNode(BST<int>*root)
{
	if(root==NULL)
	{
		return ;
		
	}
	CopyLeftNode(root->left);
	CopyLeftNode(root->right);
	
	BST<int>*temp=new BST<int>(root->data);
	BST<int>*droot=root->left;
	 root->left=temp; 
	 temp->left=droot;
	  
}

void printlevelwise(BST<int>*root)
{
	queue<BST<int>*> pn;
	pn.push(root);
	cout<<root->data;
	while(pn.size()!=0)
	{
		BST<int>*front=pn.front();
		pn.pop();
		
		if(front->left!=NULL)
		{
			cout<<front->left->data;
			pn.push(front->left);
			cout<<" ";
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

BST<int>*CheckLCA(BST<int>*root,int n1,int n2)
{
	if(root==NULL)
	return NULL;
	
	if(root->data==n1 || root->data==n2)
	{
		return root;
	}
	BST<int>*leftnum=CheckLCA(root->left,n1,n2);
	BST<int>*rightnum=CheckLCA(root->right,n1,n2);
	if(leftnum==NULL)
	{
		return rightnum;
	}
	else if(rightnum==NULL)
	{
		return leftnum;
	}
	else if(leftnum==NULL&&rightnum==NULL)
	{
		return NULL;
	}
	else if(leftnum!=NULL&&rightnum!=NULL)
	{
		return root;
	}
}
class isBSTcheck1
{
	public:
		int minimum;
		int maximum;
//		int height;
		bool isBST;
};
isBSTcheck1 findBST1(BST<int>*root)
{
	if(root==NULL)
	{
		isBSTcheck1 obj;
		obj.isBST=true;
		obj.maximum=INT_MIN;
		obj.minimum-INT_MAX;
//		obj.height=INT_MIN;
		return obj;
	}
	
	isBSTcheck1 leftoutput=findBST1(root->left);
	isBSTcheck1 rightoutput=findBST1(root->right);
	
	int min1=min(root->data,min(leftoutput.minimum , rightoutput.minimum));
	int max1=max(root->data,max(leftoutput.maximum , rightoutput.maximum));
	
	bool returnvalue=(leftoutput.isBST) && (rightoutput.isBST)
	 && (root->data>leftoutput.maximum) && (root->data<=rightoutput.minimum);
	
	
	isBSTcheck1 obj;
	obj.isBST=returnvalue;
	obj.maximum=max1;
	obj.minimum=min1;
	
	return obj;
}

//10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
int main()
{
	BST<int>*root=takeinputlevelwise();
	CopyLeftNode(root);
	cout<<endl;
	printlevelwise(root);
	
//	if(CheckLCA(root,200,100)==NULL)
//	{
//		cout<<-1;
//	}
//	else
//	{
//		cout<<CheckLCA(root,200,100)->data<<endl;
//	}
	isBSTcheck1 obj=findBST1(root);
	cout<<endl;
	cout<<"min "<<obj.minimum<<endl;
	cout<<"max "<<obj.maximum<<endl;
	cout<<"isbool "<<obj.isBST;
	return 0;
	
}

