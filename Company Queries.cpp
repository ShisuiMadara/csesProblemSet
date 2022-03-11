#include<bits/stdc++.h>
using namespace std;
     
const int MAX_N = 2e5 + 10;
const int MOD = 1e9 + 7;
 
vector<int>tree[MAX_N];
 
int parent[300000][20];
 
void precompute(int node, int par)
{
 
    parent[node][0] = par;
 
    for(int i = 1; i<20; ++i)
    {
        if(parent[node][i-1] == -1)
        {
            parent[node][i] = -1;
            continue;
        }
        parent[node][i] = parent[parent[node][i-1]][i-1];
    }
 
    for(auto&c:tree[node])
    {
        if(c != par)
        {
            precompute(c, node);
        }
    } 
}
 
void solve(int a, int b)
{
 
        for(int i = 19; i>=0; i--)
        {
            if(b == (1 << i))
            {
                
                cout<<parent[a][i]<<'\n';
                return;
            }
 
            if(b > (1 << i))
            {
                b -= (1 << i);
                a = parent[a][i];
 
                if(a <= 0)
                {
                    cout<<-1<<'\n';
                    return;
                }
            }
        }
    
}
 
 
 
int main()
{
    int n;
    cin>>n;
    int q;
    cin>>q;
 
    tree[1].push_back(-1);
    for(int i = 2; i<=n; ++i)
    {
        int x;
        cin>>x;
 
        tree[x].push_back(i);
        tree[i].push_back(x);
   }
 
   precompute(1,-1);
 
//    for(int i = 0; i<5; ++i)
//    {
//        for(int j = 0; j<20; ++j)
//        {
//            cout<<parent[i][j]<<" ";
//        }
//        cout<<'\n';
//    }
 
    while(q--)
    {
        int a,b ;
        cin>>a>>b;
 
        //b in binary then iterate the binary towards its down side
 
        solve(a,b);
    }
 
}
