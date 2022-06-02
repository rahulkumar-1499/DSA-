#include<iostream>
#include<queue>
using namespace std;

template <typename T>

class BinarySearchTree1
{
	public:
		T data;
		BinarySearchTree1* left;
		BinarySearchTree1* right;
	BinarySearchTree1(T data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
	~BinarySearchTree1()
	{
		delete left;
		delete right;
	}
};

BinarySearchTree1<int>* takeinputlevelwise()
{
	int rootdata;
	cout<<"enter rootdata: ";
	cin>>rootdata;
	if(rootdata==-1)
	{
	return NULL;
	}
	BinarySearchTree1<int>* root=new BinarySearchTree1<int>(rootdata);
	queue<BinarySearchTree1<int>*> pn;
	pn.push(root);
	while(pn.size()!=0)
	{
		BinarySearchTree1<int>*front=pn.front();
		pn.pop();
		int leftchild;
		cout<<"enter left child of "<<front->data;
		cin>>leftchild;
		if(leftchild!=-1)
		{
			BinarySearchTree1<int>*child=new BinarySearchTree1<int>(leftchild);
			front->left=child;
			pn.push(child);
		}
		int rightchild;
		cout<<"enter right child of "<<front->data<<": ";
		cin>>rightchild;
		if(rightchild!=-1)
		{
			BinarySearchTree1<int>*child1=new  BinarySearchTree1<int>(rightchild);
			front->right=child1;
			pn.push(child1);
		}
	}
	return root;
}

BinarySearchTree1<int>* createBST(int arr[],int start,int end)
	{
		if(start >end)
		{
			return NULL;
		}
		
		
			int mid=(start+end)/2;
			
			BinarySearchTree1<int>*root=new BinarySearchTree1<int>(arr[mid]);
			
			root->left=createBST(arr,start,mid-1);
			root->right=createBST(arr,mid+1,end);
			
			return root;			
		
		
		
	}
	



	 void Preordertraversal(BinarySearchTree1<int>*root)
{
	if(root==NULL)
	return;
	cout<<" "<<root->data<<" ";
	Preordertraversal(root->left);
	Preordertraversal(root->right);
}


	vector<int>*getRootToNode(BinarySearchTree1<int>*root,int data)
	{
		if(root==NULL)
		{
			return NULL;
		}
		if(root->data==data)
		{
			vector<int>*output=new vector<int>();
			output->push_back(root->data);
			return output;
			
		}
		vector<int>*leftOutput=getRootToNode(root->left,data);
		if(leftOutput!=NULL)
		{
			leftOutput->push_back(root->data);
			return leftOutput;
			
		}
		vector<int>*rightOutput=getRootToNode(root->right,data);
		if(rightOutput!=NULL)
	{
		rightOutput->push_back(root->data);
		return rightOutput;
	}
		else
		{
			return NULL;
		}
		
	}


int main()
{
//	int arr[]={1,2,3,4,5,6,7};
//	int start=0;
//	int end=sizeof(arr)/sizeof(arr[0]);
//	 BinarySearchTree1<int>*root;
//	 
//	 root=createBST(arr,start,end-1);
//	 Preordertraversal(root);
	BinarySearchTree1<int>*root=takeinputlevelwise();
	vector<int>*output=getRootToNode(root,2);
	cout<<endl;
	for(int i=0;i<output->size();i++)
	{
		cout<<output->at(i)<<endl;
	}
	return 0;
}
