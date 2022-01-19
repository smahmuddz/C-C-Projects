//Print all Hamiltonian Cycles in an Undirected Graph
//Using Backtracking algorithm & recursion

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;

bool isAddable(int v, vector<vector<int>> graph, vector<int> path, int p)
{
   if (graph[path[p-1]][v] == 0)
		return false;
   for (int i=0;i<p;i++)
		if (path[i]==v)
			return false;

   return true;
}
bool cycle;
void recursive(vector<vector<int>> graph, int p, vector<int> path, bool is_Visited[], int N)
{
	if (p==N) {
    if (graph[path[path.size()-1]][path[0]] != 0) {
         path.push_back(0);
		 for (int i =0;i<path.size();i++) {
				cout<<path[i]<<" ";
				if(i!=path.size()-1)
				{cout<<"-> ";}
			}
			cout<<endl;
         path.pop_back();
         cycle=true;
		}
		return;
	}
    for (int v=0;v<N;v++) {
    if (isAddable(v,graph,path,p)&&!is_Visited[v]) {
         path.push_back(v);
		 is_Visited[v]=true;
         recursive(graph,p+1,path,is_Visited,N);
         is_Visited[v]=false;
			path.pop_back();
		}
	}
}

//Backtracking 
void Hamiltonian(vector<vector<int>> graph,int N)
{ 
	cycle=false;
   vector<int> path;
	path.push_back(0);
   bool is_Visited[N];
   for (int i=0;i<N;i++)
		{is_Visited[i]=false;}
   is_Visited[0]=true;
   recursive(graph,1,path,is_Visited,N);
   if(cycle)
   {cout<<endl<<"Those are the desired Hamiltonian Cycle"<<endl<<endl;}
	if (!cycle) {
		cout<<"No Cycle Exists"<<endl<<endl;
		return;
	}
}
int main()
{
	int V;
	cout<<"Enter the number of vertex: ";
    cin>>V;
	cout<<endl<<"Enter the elements in adjacent matrix: "<<endl;
    //Adj Matrix Input
	for(int i=0;i<V;i++)
    {
     vector<int> temp;
   for(int j=0;j<V;j++)
   {int x;
   cin>>x;
   temp.push_back(x);
   }
   graph.push_back(temp);
   temp.clear();
   }
   cout<<endl<<endl;
   cout<<"Result:\n";
   Hamiltonian(graph,V);
   return 0;
}


//This Code is written by Sabbir Mahmud Afridi 

/*
Sample Inputs: 

Input:
Ham Cycle
0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 1
0 1 1 1 0
Not Ham Cycle
0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 0
0 1 1 0 0
*/