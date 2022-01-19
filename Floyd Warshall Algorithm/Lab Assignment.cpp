/*Implement Floyd Warshall algorithm in a weighted directed graph to find all pair shortest paths.
Print the all pair shortest paths.*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 9999;
vector<vector<int>> graph;
vector<vector<int>> cost;
vector<vector<int>> path;

// Recursive call print
void path_print(vector<vector<int>> path, int v, int u)
{
    if (path[v][u] == v) {
        return;
    }
    path_print(path,v,path[v][u]);
    cout << path[v][u] << "-> ";
}


//printing path
void print_shortestPath(vector<vector<int>> cost, vector<vector<int>> path)
{
    int N = cost.size();
    for (int v=0;v<N;v++)
    {
        for (int u=0;u<N;u++)
        {
            if (u != v && path[v][u] != -1)
            {
                cout << "Shortest path from " << v << " to " << u << " is :"
                << v << "->";
                path_print(path, v, u);
                cout << u << endl;
            }
        }
    }
}
//floyd algo
void floyd(vector<vector<int>> adjMatrix)
{
    int n = adjMatrix.size();
    if (n == 0) {
        return;
    }
    vector<vector<int>> cost(n, vector<int>(n));
    vector<vector<int>> path(n, vector<int>(n));
    for (int v=0;v<n;v++)
    {
        for (int u=0;u<n;u++)
        {
            cost[v][u] = adjMatrix[v][u];
 
            if (v==u) {
                path[v][u] = 0;
            }
            else if (cost[v][u]!=INT_MAX) {
                path[v][u]=v;
            }
            else {
                path[v][u]=-1;
            }
        }
    }
  
    for (int k = 0; k < n; k++)
    {for (int i = 0; i < n; i++)
        {for (int j = 0; j < n; j++)
            { if (cost[i][k] + cost[k][j] < cost[i][j])
                {
                    cost[i][j] = cost[i][k] + cost[k][j];
                    path[i][j] = path[k][j];
                } }
            if (cost[i][i] < 0)
            {cout << "Negative weight cycle exist"; return;}
        }
    }
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (graph[i][j] == 9999)
        printf("%3c",126);
      else
        printf("%3d",graph[i][j]);
    }
    printf("\n");
  }
 cout<<endl<<endl;
    cout<<"Shortest Paths:\n\n";
    print_shortestPath(cost, path);
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
   {   int x;
   cin>>x;
       if(x==0&&i!=j)
       {
        temp.push_back(9999);
       }
       else
        temp.push_back(x);
   }
   graph.push_back(temp);
   temp.clear();
  }
cout<<endl<<"The Distance Matrix Is:\n"<<endl;
floyd(graph);
 
    return 0;
}