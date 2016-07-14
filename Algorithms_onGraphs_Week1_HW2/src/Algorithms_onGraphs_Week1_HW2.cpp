//============================================================================
// Name        : Algorithms_onGraphs_Week1_HW2.cpp
// Author      : Daniel Ramirez
// Version     :
// Copyright   : HW2_Week1
// Description : Finding an Exit from a Maze in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  //write your code here
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
