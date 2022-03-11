#include<bits/stdc++.h>
using namespace std;
 
const int MAX_N = 2e5 + 10;
typedef long long ll;
 
//TOOK MOTIVATION FROM KARTIK ARORA VIDEO, do check it out for more detail
vector<int> tree[200001];
ll subtreeAns[200001];
ll ans[200001];
int subtreeSize[200001];
 
void preprocessing(int src, int par)
{
    int numOfNodes = 1;
    ll ansForSubtree = 0;
    for(int child : tree[src])
    {
        if(child != par)
        {
            preprocessing(child, src);
            numOfNodes += subtreeSize[child];
            ansForSubtree += subtreeSize[child] + subtreeAns[child];
        }
    }
    subtreeSize[src] = numOfNodes;
    subtreeAns[src] = ansForSubtree;
}
 
 
 
void solve(int src, int par, ll par_ans, int& totalNodes)
{
    ans[src] = subtreeAns[src] + (par_ans + (totalNodes - subtreeSize[src]));
 
    for(int child : tree[src])
    {
        if(child != par)
            solve(child, src, ans[src] - (subtreeAns[child] + subtreeSize[child]), totalNodes);
    }
}
 
int main() {
 
   
        int n;
        cin >> n;
        for(int i = 1; i<n; ++i)
        {
            int u,v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        preprocessing(1, 0);
        solve(1, 0, 0, n);
        for(int i = 1; i<=n; ++i)
            cout << ans[i] <<' ';
   
   return 0;
}
