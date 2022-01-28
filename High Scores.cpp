#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
const int MAX_N = 1e4 +10, int_max = 0x3f3f3f3f;
const ll INF = 1e18;



ll n,m;
vector<tuple<ll,ll,ll>>arr;
vector<ll>inQ(MAX_N, 0);
vector<ll>dist(MAX_N,INF);
vector<int>cnt(MAX_N,0);
queue<ll>q;
vector<int>visited1(MAX_N, 0);
vector<int>visited2(MAX_N,0);
vector<ll>parent(MAX_N, -1);
vector<ll>cycle;
vector<ll>adj1[MAX_N], adj2[MAX_N];

void dfs1(ll x)
{
  if(visited1[x])
  {
    return;
  }
  visited1[x] = 1;

  for(auto&c:adj1[x])
  {
    if(!visited1[c])
    {
      dfs1(c);
    }
  }
}

void dfs2(ll x)
{
  if(visited2[x])
  {
    return;
  }

  visited2[x] = 1;

  for(auto&c:adj2[x])
  {
    if(!visited2[c])
    {
      dfs2(c);
    }
  }
}

void floyd()
{
  dfs1(1);
  dfs2(n);

  dist[1] = 0;

  for(ll i = 0; i<n; ++i)
  {
    
    for(auto &c:arr)
    {
     ll a,b,w;
     a = get<0>(c);
     b = get<1>(c);
     w = get<2>(c);

     //cout<<a<<" "<<b<<" "<<w<<"\n";
      if(dist[b] > dist[a] + w)
      {
        dist[b] = min(dist[b], dist[a]+w);

        if(i == n-1 && visited1[b] && visited2[b])
        {
          cout<<-1<<'\n';
          return;
        }
      }
    }
    
  }

  cout<<-dist[n]<<'\n';
  return;

}


int main()
{
  cin>>n>>m;

  for(int i =0; i<m; ++i)
  {
    ll a,b,w;
    cin>>a>>b>>w;

    arr.push_back({a,b,-w});
    adj1[a].push_back(b);
    adj2[b].push_back(a);
  }
  floyd();

  return 0;

}
