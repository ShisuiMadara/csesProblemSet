#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int MOD =  998244353;
const int MAX_N = 1e6;
 
vector<int>arr[MAX_N];
vector<int>visited(MAX_N, 0);
ll cnt = 0;
 
void dfs(int previous, int current)
{
    for(auto&c:arr[current])
    {
        if(c != previous)
        {
            dfs(current, c);
            //cout<<"HERE "<<current<<" "<<c<<"\n";
 
            if(!visited[c] && !visited[current])
            {
                visited[c] = 1;
                visited[current] = 1;
                cnt++;
            }
        }
    }
}
 
int main()
{
    int n;
    scanf("%d", &n);
 
    for(int i = 0; i<n-1; ++i)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        arr[a].push_back(b);
        arr[b].push_back(a);
    } 
    dfs(0,1);   
 
    printf("%lld", cnt);
    return 0;
}
