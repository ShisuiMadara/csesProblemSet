#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
const int MAX_N = 2e5 +10, int_max = 0x3f3f3f3f;


int n;
vector<pair<ll,ll>>arr[MAX_N];
vector<int>visited(MAX_N, 0);

priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;

vector<ll>dist(MAX_N,LLONG_MAX);

void djikstra(int node)
{

  q.push({0,node});
  dist[node] = 0;

  while(!q.empty())
  {
    pair<ll,ll>here = q.top();
    q.pop();
    visited[node] = 1;

    //relaxation will happen only once

    if(dist[here.second] < here.first)
    {
      continue;
    }

    visited[here.second] = 1;

    for(auto&c:arr[here.second])
    {
      if(!visited[c.first])
      {
        dist[c.first] =  here.first + c.second;
        q.push({dist[c.first], c.first});
      }
    }
  }

  
}


int main()
{
  int m;
  cin>>n>>m;

  for(int i = 0; i<m; ++i)
  {
    ll a,b,c;
    cin>>a>>b>>c;

    arr[a].push_back({b,c});
    
  }


  djikstra(1);

  for(int i = 1; i<=n; ++i)
  {
    cout<<dist[i]<<" ";
  }
}
