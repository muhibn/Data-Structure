#include <bits/stdc++.h>
using namespace std;
class GraphList
{
	private:
		vector<int> *graph;
		int v;
	public:
		GraphList(int);
		void edgeGraph(int,int);
		void printGraph();
		
};
GraphList::GraphList(int V)
{
	v=V;
	graph=new vector<int>(v);
}
void GraphList::edgeGraph(int source,int destination)
{
	graph[source].push_back(destination);
	graph[destination].push_back(source);
}
void GraphList::printGraph()
{
	for(int i=0;i<v;++i)
	{
		cout<<"Adjancy list of vetrix v ("<<i<<")->";
		for(auto x : graph[i])
		{
			cout<<"->"<<j;
		}
		cout<<endl;
		
	}
	
}
int main()
{
	int v=5;
	GraphList obj(v);
	
	
    obj.edgeGraph(0, 1);
    obj.edgeGraph(0, 4);
    obj.edgeGraph(1, 2);
    obj.edgeGraph(1, 3);
    obj.edgeGraph(1, 4);
    obj.edgeGraph(2, 3);
    obj.edgeGraph(3, 4);

    obj.printGraph();
    return 0;
	
}
