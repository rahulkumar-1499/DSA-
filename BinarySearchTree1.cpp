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



int main()
{
	int arr[]={1,2,3,4,5,6,7};
	int start=0;
	int end=sizeof(arr)/sizeof(arr[0]);
	 BinarySearchTree1<int>*root;
	 
	 root=createBST(arr,start,end-1);
	 Preordertraversal(root);
	
	return 0;
}
