#include <iostream>
#include <conio.h>
#include "Queue.cpp"
#include "Stack.cpp"
using namespace std;

template <class t>
struct Nodes
{
	t data;
	struct Nodes<t> *next;
};
template <class t>
struct adjnode
{
	struct Nodes<t> *head;
};
template <class t>
class Graph
{
	private:
	   int v;
	   adjnode<t> *arr;
	   bool *visited;
	public:
		Graph(int);
		void addedge(const t& ,const t&);
		void printGraph();
		void BFS();
		void DFS();
};
template <class t>
Graph<t>::Graph(int v)
{
	this->v=v;
	arr=new adjnode<t>[v];
	for(int i=0;i<v;i++)
	{
		arr[i].head=NULL;
	}
	
	visited=new bool(v);
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}

}   
template <class t>
void Graph<t>::addedge(const t& src,const t& dest)
{
     Nodes<t> *newnode=new Nodes<t>;
     
	 newnode->data=dest;
     newnode->next=NULL;
     newnode->next=arr[src].head;
     arr[src].head=newnode;
     
     newnode=new Nodes<t>;
     
     newnode->data=src;
     newnode->next=NULL;
     newnode->next=arr[dest].head;
     arr[dest].head=newnode;
     
     
}
template <class t>
void Graph<t>::printGraph()
{
	for(int i=0;i<v;i++)
	{
		Nodes<t> *temp=new Nodes<t>;
		temp=arr[i].head;
		cout<<"[ "<<i<<" ]";
		while(temp!=NULL)
		{
			cout<<temp->data<<"-->";
			temp=temp->next;
			
			
		}
		cout<<endl;
	}
}
template <class t>
void Graph<t>::BFS()
{
	
}
int main()
{
	Graph<int> obj(4);
	obj.addedge(0,1);
	obj.addedge(1,2);
	obj.addedge(0,3);
	obj.addedge(0,2);
	obj.addedge(3,4);
	obj.addedge(2,4);
	obj.addedge(4,5);
	
	obj.printGraph();
	
	
	getch();
	return 0;
}
