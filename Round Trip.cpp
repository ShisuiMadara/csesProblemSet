#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
 
vector<vector<int>>arr(MAX_N);
vector<int>parent(MAX_N, 0);
vector<int>visited(MAX_N,0);
 

int n, m, vis[MAX_N], pre[MAX_N];
vector<int> adj[MAX_N];
 
void dfs(int u, int p = 0) 
{

    vis[u] = 1; 
    pre[u] = p;

    for (int v : adj[u]) 
    {
        if (vis[v] == 0) 
        {
            dfs(v, u);
        }
         else if (vis[v] == 1)
          {
            if (v == p)
            {
              continue;
            }

            vector<int> ans;
            ans.push_back(v);

            while(u != v)
            {
              ans.push_back(u);
              u = pre[u];

            }

            ans.push_back(v);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for (int x : ans) cout << x << " ";
            cout << "\n";
            exit(0);
        }
    }
    vis[u] = 2;
}
 
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int u = 1; u <= n; u++) {
        if (vis[u]) continue;
        dfs(u);
    }
    cout << "IMPOSSIBLE\n";
}
