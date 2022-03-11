#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9 +7;
const int MAXN = 1000000;
 
 
vector<vector<int>> adj(MAXN);
vector<int>subtree_size(MAXN);
 
int calc (int node) {
   if (adj[node].size() == 0) {
      return 1;
   } else {
       for (int i = 0; i < adj[node].size(); i++) {
          subtree_size[node] += calc(adj[node][i]);
       }
   }
   return subtree_size[node] + 1;
}
 
int main() {
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
      int boss;
      cin >> boss;
      adj[boss].push_back(i);
  }
  calc(1);
  for (int i = 1; i <= n; i++) {
      cout << subtree_size[i] << " ";
  }
  return 0;
}
