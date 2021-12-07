#include "Graph.h"
using namespace std;

void Graph::addEdge(vector<User> adj[], User u, User v)
{
  adj[u.getGraphIndex()].push_back(v);
  adj[v.getGraphIndex()].push_back(u);
}

void Graph::delEdge(vector<User> adj[], User u, User v)
{
  for (long unsigned int i = 0; i < adj[u.getGraphIndex()].size(); i++) {
    if (adj[u.getGraphIndex()][i] == v) {
      adj[u.getGraphIndex()].erase(adj[u.getGraphIndex()].begin() + i);
      break;
    }
  }
    for (long unsigned int i = 0; i < adj[v.getGraphIndex()].size(); i++) {
        if (adj[v.getGraphIndex()][i] == u) {
            adj[v.getGraphIndex()].erase(adj[v.getGraphIndex()].begin() + i);
            break;
        }
    }
}

bool Graph::hasEdge(vector<User> adj[], User u, User v) {
  for (long unsigned int i = 0; i < adj[u.getGraphIndex()].size(); i++) {
    if (adj[u.getGraphIndex()][i] == v) return true;
  }
  return false;
}

void Graph::printGraph(vector<User> adj[], int V, string username, int index)
{
  if (index < V) {
    cout << username << " is friends with" << " ";
    for (auto x : adj[index]) {
      cout << x << ", ";
    }
  }
  printf("\n");
}
void Graph::printEFNUsers(vector<User> adj[], int size, int radius)
{
  cout << "All users within EFN of " << radius << ": ";
  vector<bool> visited(size,0);
  for (int i = 0; i< size; i++){
    for (auto x : adj[i]) {
      if (visited[x.getGraphIndex()]) continue;
      int temp = minEdgeBFS(adj,0,x.getGraphIndex(), size);
      if(temp <= radius && temp != 0){
        cout << x << ", ";
      }
      visited[x.getGraphIndex()] = 1;
    }
  }
  printf("\n");
}



int Graph::minEdgeBFS(vector <User> edges[], int u,int v, int n)
{
    vector<bool> visited(n, 0);
 
    vector<int> distance(n, 0);
 

    queue <int> Q;
    distance[u] = 0;
 
    Q.push(u);
    visited[u] = true;
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
 
        for (long unsigned int i=0; i<edges[x].size(); i++)
        {
	  if (visited[(edges[x][i]).getGraphIndex()])
                continue;
 
	  distance[(edges[x][i]).getGraphIndex()] = distance[x] + 1;
	  Q.push((edges[x][i]).getGraphIndex());
	  visited[(edges[x][i]).getGraphIndex()] = 1;
        }
    }
    return distance[v];
}
 
