#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e3+7;
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
 
 
int n,m;
 
int paths[MAX_N][MAX_N];
pair<int,int> parent[MAX_N][MAX_N];
string ans;
bool flag = false;
pair<int,int>start;
 
queue<pair<int,int>>q;
 
 
void retrace(pair<int,int>x)
{
  pair<int,int>pre;
  pre = parent[x.first][x.second];
 
  if(pre == make_pair(0,0))
  {
    return; //stating point
  }
  if(pre.first == x.first+1) 
  {
      ans += 'U';
  }
  else if(pre.first == x.first-1)
  {
    ans+='D';
  }
  else if(pre.second == x.second+1)
    {
      ans+='L';
    }
  else if(pre.second == x.second-1)
  {
    ans +='R';
  } 
 
  retrace(pre);
 
}
 
 
bool isCorner(pair<int,int>x)
{
  if(x.first == 1 || x.second == m || x.second == 1 || x.first == n)
  {
    return true;
  }
 
  return false;
}
 
 
void check(pair<int,int>current, pair<int,int>next)
{
  int distance = paths[current.first][current.second];
 
  if(distance + 1 < paths[next.first][next.second])
  {
 
    paths[next.first][next.second] = distance+1;
    q.push(next);
 
    parent[next.first][next.second] = current;
  }
}
 
 
bool monster = true;
 
void bfs()
{
 
  while(!q.empty())
  {
    pair<int,int>current = q.front();
    q.pop();
 
    pair<int,int>next = current;
 
    //case work
 
    next.first++;
    check(current, next);
 
    next = current;
    next.first--;
    check(current,next);;
 
    next=current;
    next.second--;
    check(current,next);
 
    next=current;
    next.second++;
    check(current,next);
 
    if(!monster && isCorner(current))
    {
      cout<<"YES\n";
      cout<<paths[current.first][current.second]<<'\n';
 
      retrace(current);
      flag = true;
      return;
    }
 
  }
}
 
 
 
 
int main()
{
  cin>>n>>m;
 
  for(int i = 1; i<=n; ++i)
  {
    string s;
    cin>>s;
 
    for(int j =1; j<=m; ++j)
    {
      paths[i][j] = INT_MAX;
 
      if(s[j-1] == '#')
      {
        paths[i][j] = 0;
      }
      else if(s[j-1] == 'M')
      {
        paths[i][j] = 0;
        q.push({i,j});
      }
      else if(s[j-1] == 'A')
      {
        start.first = i;
        start.second = j;
      }
    }
  }
 
  bfs(); 
 
  parent[start.first][start.second] = {0,0};
  paths[start.first][start.second] = 0;
  q.push(start);
 
 
  monster = false;
 
  bfs();
 
  if(flag)
  {
    reverse(ans.begin(), ans.end());
    cout<<ans<<'\n';
  }
  else
  {
    cout<<"NO";
  }
 
  return 0;
 
}
 
 
