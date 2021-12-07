#include <bits/stdc++.h>
#include <vector>
#include "User.h"
using namespace std;

class Graph {
private:
public:
  void addEdge(vector<User> adj[], User u, User v);
  void delEdge(vector<User> adj[], User u, User v);
  void printGraph(vector<User> adj[], int V, string, int);
  int minEdgeBFS(vector <User> edges[], int u, int v, int n);
  bool hasEdge(vector<User> adj[], User u, User v);
  void printEFNUsers(vector<User> adj[], int , int );
};
