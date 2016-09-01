//============================================================================
// Name        : Algorithms_onGraphs_Week1_HW2.cpp
// Author      : Daniel Ramirez
// Version     :
// Copyright   : HW2_Week1
// Description : Finding an Exit from a Maze in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;
using std::vector;
using std::pair;

//prototypes
void explore(vector<vector<int> > &adj, vector<bool> &adj_v, int x);
int number_of_components(vector<vector<int> > &adj);

//global variables
/*******************************************************************************
*
* "n" = number of vertices in the graph
* "m" = number of edges in the graph
*
*******************************************************************************/
size_t n, m, cc;
pair <size_t,size_t> v_connected;

void explore(vector<vector<int> > &adj, vector<bool> &adj_v, int x){
   vector<int>::iterator it;
   adj_v[x]=true;
   v_connected=make_pair(x,cc);
   for(it=adj[x].begin();it!=adj[x].end();it++){
     if(adj_v[*it]==false)
        explore(adj,adj_v,*it);
   }
}

int number_of_components(vector<vector<int> > &adj) {
  vector<bool> adj_v(n,false);
  cc=1;
  for(int i=0;i<n;i++){
      if(adj_v[i]==false){
         explore(adj,adj_v,i);
         cc++;
      }
  }
  return cc-1;
}

int main() {
  std::cin >> n >> m;
  if( (n>=1&&n<=1e3) && (m>=0&&m<=1e3)){
     vector<vector<int> > adj(n, vector<int>());
     for (size_t i = 0; i < m; i++) {
       int x, y;
       cin >> x >> y;
       adj[x - 1].push_back(y - 1);
       adj[y - 1].push_back(x - 1);
     }
     cout << number_of_components(adj);
  }
  else
      cout << 0;
}
