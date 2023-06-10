#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
template <class t >
struct node
{
	t data;
	struct node<t> *left;
	struct node<t> *right;	
};
template <class t >
class BinarySearchTree
{
	private:
	  struct node<t> *root;
	  void insert(struct node<t> *&,struct node<t> *&);
	  void preOrderTravel(struct node<t> *);
	  void inOrderTravel(struct node<t> *);
	  void postOrderTravel(struct node<t> *);
	  node<t>* findRemove(struct node<t> *,const t &);
      node<t> * minValueRight(struct node<t>*);
      int treeHeight(struct node<t>*);
	public:
		BinarySearchTree();
		void insertTree(const t&);
		void preOrder();
		void inOrder();
		void postOrder();
		void removePos(const t&);
		void height();
		
		
		
		
};
template <class t>
BinarySearchTree<t>::BinarySearchTree()
{
	root=NULL;
}
template <class t>
void BinarySearchTree<t>::insertTree(const t &info)
{
	struct node<t> *n=NULL;
	n=new node<t>;
	
	
	n->data=info;
	n->left=NULL;
	n->right=NULL;
	insert(root,n);
	
}
template <class t >
void BinarySearchTree<t>::insert(struct node<t> *&rootnode, struct node<t> *&newnode)
{
	if(rootnode==NULL)
	{
		rootnode=newnode;
	}
	
	
	else if (rootnode->data>newnode->data)
	{
		insert(rootnode->left,newnode);
	}
	else 
	{
		insert(rootnode->right,newnode);
	}
}
template <class t>
void BinarySearchTree<t>::preOrder()
{
	preOrderTravel(root);
	
}
template <class t>
void BinarySearchTree<t>::preOrderTravel(struct node<t>  *rootnode)
{
	if(rootnode==NULL)
	{
		return ;
	}
	cout<<rootnode->data <<" ";
	preOrderTravel(rootnode->left);
	preOrderTravel(rootnode->right);
}
template<class t>
void BinarySearchTree<t>::inOrder()
{
	inOrderTravel(root);
}
template <class t>
void BinarySearchTree<t>::inOrderTravel(struct node<t> *rootnode)
{
	if(rootnode==NULL)
	{
		return ;
	}
	inOrderTravel(rootnode->left);
	cout<<rootnode->data<<" ";
	inOrderTravel(rootnode->right);
	
}
template <class t>
void BinarySearchTree<t>::postOrder()
{
	postOrderTravel(root);
}
template <class t>
void BinarySearchTree<t>::postOrderTravel(struct node<t> *rootnode)
{
	if(rootnode==NULL)
	{
		return ;
	}
	 postOrderTravel(rootnode->left);
	 postOrderTravel(rootnode->right);
	 cout<<rootnode->data<<" ";
}
template <class t>
void BinarySearchTree<t>::removePos(const t& value)
{
	findRemove(root,value);
}
template <class t>
node<t>* BinarySearchTree<t>::findRemove(struct node<t> *rootnode, const t& value)
{
	
	if(rootnode==NULL)
	{
		return rootnode;
	}
	if(value<rootnode->data)
	{
		cout<<rootnode->data<<" if(value<rootnode->data) \n ";
		
		
		rootnode->left=findRemove(rootnode->left,value);
	    
	}
	else if(value>rootnode->data)
	{
	  cout<<rootnode->data<<" if(value>rootnode->data) \n ";
	  rootnode->right=findRemove(rootnode->right,value);
	  
    }
    else
    {
    	if(rootnode->left && rootnode->right==NULL)
    	{
		  cout<<rootnode->data<<" if(value>rootnode->data) \n ";
		  return NULL;
    	
		}
		if(rootnode->left==NULL)
		{
			struct node<t> *temp=new node<t>;
		
			temp=rootnode->right;
			free(rootnode);
			return temp;
		}
		else if(rootnode->right==NULL)
		{
			struct node<t> *temp=new node<t>;
			temp=rootnode->left;
			free(rootnode);
			return temp;
		}
		struct node<t> *temp=new node<t>;
		temp=minValueRight(rootnode->right);
		rootnode->data=temp->data;
		rootnode->right=findRemove(rootnode->right,temp->data);
		
		
	}
	return rootnode;
}
template <class t>
node<t> * BinarySearchTree<t>::minValueRight(struct node<t> *nodes)
{
	struct node<t> * temp=new node<t>;
	temp=nodes;
	
	while(temp && temp->left !=NULL)
	{  temp=temp->left;	
	}
	return temp;
}
template<class t>
void BinarySearchTree<t>::height()
{
	int tree_height=treeHeight(root);
	
	cout<<"Height of tree is "<<tree_height<<endl;
}
template <class t>
int BinarySearchTree<t>::treeHeight(struct node<t> *rootnode)
{
	if(rootnode==NULL)
	{
		return 0;
	}
	else{
		int heightl=treeHeight(rootnode->left);
		int heightr=treeHeight(rootnode->right);
		cout<<"tree of left : "<<heightl<<"tree right : "<<heightr<<endl;
		
		if(heightl>heightr)
		{
			return(heightl+1);
		}else 
		{
			return (heightr+1);
		}
	}
	
}
int main()
{
	BinarySearchTree<int> obj;

	int choose;
	do{
		cout<<"Enter the choose \n";
		cout<<"1 for Insert the data \n";
		cout<<"2 for preoder travels \n";
		cout<<"3 for inodre travels \n";
		cout<<"4 for post oder travels \n";
		cout<<"5 for remove the element \n";
		cout<<"6 for find the height of binary tree\n";
		cout<<"0 for exit \n";
		cin>>choose;
 	switch(choose)
		{
			case 1 : int info,nelem;
					cout<<"Enter number element : ";
			        cin>>nelem;
			        for(int i=0;i<nelem;i++){
					
					cout<<"Enter data : ";
					cin>>info;
					obj.insertTree(info);
				} 
			  break;
			case 2 : obj.preOrder();
			  break;
			case 3 :obj.inOrder();
			  break;
			case 4 :obj.postOrder();
			  break;
			case 5 :int key ;
					cout<<"Enter the key : ";
					cin>>key;
					 obj.removePos(key);
			  break;
			case 6 :obj.height();
			  break;
			default :cout<<"wrong choose ";
			
		}
		cout<<endl;
	}while(choose !=0);
	
	
	
	getch();
	return 0;
}
