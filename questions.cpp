#include<iostream>
#include<queue>
#include<cstdlib>
#include<stack>
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
/*
BinaryNodeTreetest<int>*NodeIntake()
{
	int rootdata;
	cout<<"enter rootdata: ";
	cin>>rootdata;
	if(rootdata==-1)
	{
		return NULL;
	}
	BinaryNodeTreetest<int>*root=new BinaryNodeTreetest<int>(rootdata);
	queue<BinaryNodeTreetest<int>*>q;
	q.push(root);
	while(q.size()!=0)
	{
		BinaryNodeTreetest<int>*front=q.front();
		q.pop();
		int leftchild;
		cout<<"enter left child of "<<front->data<<":";
		cin>>leftchild;
		if(leftchild!=-1)
		{
			BinaryNodeTreetest<int>*child=new BinaryNodeTreetest<int>(leftchild);
			root->left=child;
			q.push(child);
		}
		int rightchild;
		cout<<"enter right child of "<<front->data<<":";
		cin>>rightchild;
		if(rightchild!=-1)
		{
			BinaryNodeTreetest<int>*child=new BinaryNodeTreetest<int>(rightchild);
			root->right=child;
			q.push(child);
		}
	}
	return root;
	
}

void printLevelWise(BinaryNodeTreetest<int>*root)
{
	queue<BinaryNodeTreetest<int>*> pn;
	pn.push(root);
	cout<<root->data;
	while(pn.size()!=0)
	{
		BinaryNodeTreetest<int>*front=pn.front();
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
*/	
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
//	cout<<root->data;
	while(pn.size()!=0)
	{
		BinaryNodeTree<int>*front=pn.front();
		cout<<endl;
		cout<<front->data<<":";
			pn.pop();
		if(front->left!=NULL)
		{
			cout<<"L"<<front->left->data;
			pn.push(front->left);
//			cout<<endl;	
		}
		
		if(front->right!=NULL)
		{
			cout<<"R"<<front->right->data;
			pn.push(front->right);
			cout<<endl;	
		}
		
		cout<<endl;
	}
}
int maxheight(BinaryNodeTree<int>*root)
{
	if (root==NULL)
	return 0;
	
	return 1+max(maxheight(root->left),maxheight(root->right));
}
bool balancedTree(BinaryNodeTree<int>*root)
{
	if(root==NULL)
	{
		return true;
	}
	else
	{
		int lh=maxheight(root->left);
		int rh=maxheight(root->right);
		if(abs(lh-rh<=1))
		{
			if(balancedTree(root->left)&& balancedTree(root->right))
			{
				return true;
			}
		}
	}
	return false;
}
/*
pair<int,int>minmaxvalue(BinaryNodeTree<int>*root)
{
	if(root==NULL)
	{
		pair<int,int>p;
		p.first=0;
		p.second=0;	
	}
	pair<int,int>findmin=minmaxvalue(root->left);
	pair<int,int>findmax=minmaxvalue(root->right);
	
	int	lmin=findmin.first;
	int	lmax=findmin.second;
	int	rmin=findmax.first;
	int	rmax=findmax.second;
	
	int	minvalue=min(lmin,rmin);
	int maxvalue=max(lmax,rmax);
	
		pair<int,int>p;
		p.first=minvalue;
		p.second=maxvalue;
		
		return p;
}
*/
int sumofnodes(BinaryNodeTree<int>*root)
{
	if(root==NULL)
	return 0;
	
	queue<BinaryNodeTree<int>*>pn;
	pn.push(root);
	int sum=0;
	while(pn.size()!=0)
	{
		
		BinaryNodeTree<int>*front=pn.front();
		sum+=front->data;
		pn.pop();
		if(front->left!=NULL)
		{
			pn.push(front->left);
		}
		if(front->right!=NULL)
		{
			pn.push(front->right);
		}
	}
	return sum;
}
void levelordertraversal(BinaryNodeTree<int>*root)
{
	queue<BinaryNodeTree<int>*>pn;
	pn.push(root);
	pn.push(NULL);
	cout<<root->data<<endl;
	while(pn.size()!=0)
	{
		BinaryNodeTree<int>*front=pn.front();
		pn.pop();
		if(front==NULL)
		{
			cout<<endl;
			if(pn.size()!=0)
			{
				pn.push(NULL);
			}
		}
		else
		{
			if(front->left!=NULL)
			{
				cout<<front->left->data<<" ";
				pn.push(front->left);
			}
			
			if(front->right!=NULL)
			{
				cout<<front->right->data<<" ";
				pn.push(front->right);
			}
		}
	}
}
BinaryNodeTree<int>*removeleafnode(BinaryNodeTree<int>*root)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->left==NULL && root->right==NULL)
	{
		return NULL;
	}
	root->left=removeleafnode(root->left);
	root->right=removeleafnode(root->right);
	
	return root;
}

void zigzagtraversal(BinaryNodeTree<int>*root)
{
	if(!root)
	{
		return ;
	}
	stack<BinaryNodeTree<int>*> cl;
	stack<BinaryNodeTree<int>*> nl;
	bool checker=true;
	cl.push(root);
	while(cl.empty())
	{
		BinaryNodeTree<int>* front=cl.top();
		cl.pop();
		if(front)
		{
			cout<<front->data<<" ";
			
			if(checker)
			{
				if(front->left)
				{
					nl.push(front->left);
				}
				if(front->right)
				{
					nl.push(front->right);
				}
			}
			else
			{
				if(front->right)
				{
					nl.push(front->right);
				}
					if(front->left)
				{
					nl.push(front->left);
				}
				
			}
		}
		if(cl.empty())
		{
			checker=!checker;
			swap(cl,nl);
			cout<<endl;
		}
		}	
}
//1 2 3 4 5 6 -1 -8 -1 -1 -1 -1 -1 -1 11 -1 -1
	int main()
{	
	BinaryNodeTree<int>*root;
	root=takeinputlevelwise();
/*	zigzagtraversal(root);
	printlevelwise(root);
	bool ans =balancedTree(root);
	if(ans)
	cout<<"tree is balanced"<<endl;
	else

	cout<<"tree is not balanced"<<endl;
	*/
/*	
	pair<int,int>p;
	cout<<"min value: "<<p.first<<endl;
	cout<<"min value: "<<p.second<<endl;
*/	
//	cout<<"sum of nodes is "<<sumofnodes(root)<<endl;
//	
//	levelordertraversal(root);
//	cout<<endl;
/*	
	cout<<"printing original tree:"<<endl;
	printlevelwise(root);


	root=removeleafnode(root);
	printlevelwise(root);
*/	
		return 0;

}

