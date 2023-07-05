#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
class BFS_DFS
{
	private:
		int v;
		vector<int> *graph;
		void BFS(int);
		void DFS(int);

	public:
		BFS_DFS(int);
		void getdata();
		void display(vector<int>*,int);
		void BFS();
		void DFS();

};
BFS_DFS::BFS_DFS(int V)
{
	
	//The constructor implementation initializes the number of vertices (v)
    v=V;	
    // dynamically allocates memory for the graph.
	graph=new vector<int>[v];
	

}
void BFS_DFS::getdata()
{
	
	/*The getdata function prompts the user to input the type of graph (directed or undirected)
	 and the presence of edges between vertices. It populates the graph adjacency list accordingly.
	*/
	int choice;
	cout<<"Type of Graph:"<<endl;
	cout<<"1 for Directed Graph"<<endl;
	cout<<"2 for Undirected Graph"<<endl;
	cout<<"Your choice =  ";
	cin>>choice;
	
	cout <<"value of v "<<v;
	int x;
	cout<<"\nEnter 1 if there exists an edge and 0 if does not.\n";
	for(int i=0;i<v;++i)
		for(int j=0;j<v;++j)
			if(choice==2){
				if(i<j){
					cout<<" Is there an edge = ("<<i<<","<<j<<"): ";
					cin>>x;
				
					if(x==1){
						graph[i].push_back(j);
						graph[j].push_back(i);
					}
				}
			}
			else{
				if(i!=j){
					cout<<"("<<i<<" to "<<j<<"): ";
					cin>>x;
					if(x==1)
						graph[i].push_back(j);
				}		
			}
  
   
   
}
void BFS_DFS::display(vector<int> *adj,int n)
{
	
	/*
	The display function takes an adjacency list and the number 
	of vertices as input and displays the graph, showing the edges for each vertex.
	*/
	for(int i=0;i<n;i++)
	{
		cout<<"vetrix v have edge with : ("<<i<<") ";
		
		for(int j=0;j<adj[i].size();j++)
		{
			cout<<"<--"<<adj[i][j];
		}
		
	}
}
void BFS_DFS::BFS()
{
	//The BFS and BFS(int s) functions implement the Breadth-First Search algorithm.
	// BFS function prompts the user to enter the source vertex and calls the BFS(int s) function to perform the traversal.
	
	int v;
	cout<<"\nEnter the source code:-";
	cin>>v;
	cout << "Following is Breadth First Traversal (starting from vertex "<<v<<"): ";
	BFS(v);
}

void BFS_DFS::BFS(int s)
{

    // Mark all the vertices as not visited
    bool visited[v];
    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }
 
    int queue[v];
    int front = 0, rear = 0;
 
    visited[s] = true;
    queue[rear++] = s;
 
    while (front != rear) {
 
        s = queue[front++];
        printf("%d ", s);
 
 
        for (int i = 0; i <v;i++) {
            if (graph[s][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

void BFS_DFS::DFS(){
	
	
	
	//The DFS and DFS(int start) functions implement the Depth-First Search
	//algorithm. DFS function prompts the user to enter the source vertex and
	// calls the DFS(int start) function to perform the traversal.
	
	int i;
	cout<<"\nEnter the source code: ";
	cin>>i;
	cout << "Breadth First Traversal with source vertex "<<i<<": ";
	DFS(i);
}

void BFS_DFS::DFS(int start) {
    vector<bool> visited(v, false);
    stack<int> s;
    s.push(start);
    visited[start] = true;
    cout << start << " ";

    while (!s.empty()) {
        int k = s.top();
        s.pop();

        for (int i = 0; i < graph[k].size(); i++) {
            int neighbor = graph[k][i];
            if (!visited[neighbor]) {
                cout << neighbor << " ";
                visited[neighbor] = true;
                s.push(k);
                s.push(neighbor);
                break;
            }
        }
    }
}
int main()
{
	int v;
	cout<<"Enter the number of vertix ";
	cin>>v;
	BFS_DFS obj(v);
	
	obj.getdata();
	
	int choose ;
	do{
		cout<<"Enter the choose \n";
		cout<<"1 for  BFS \n";
		cout<<"2 for DFS  \n ";
		cin>>choose;
		
		switch(choose)
		{
			case 1 : obj.BFS();
			  break;
			case 2 : obj.DFS();
			  break;
			default:cout<<"wrong choose "<<endl;
		}
	}while(choose!=0);
	
	
	getch();
	return 0;
}
