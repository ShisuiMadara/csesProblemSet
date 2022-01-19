#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
 
vector<vector<int>>arr(MAX_N);
vector<int>team(MAX_N, 0);
vector<int>visited(MAX_N,0);

bool dfs(int x, int c)
{
	visited[x] = 1;
	team[x] = c;

	for(auto&d:arr[x])
	{
		if(!visited[d])
		{
			if(!dfs(d, (c^1)))
			{
				return false;
			}
		}
		else
		{
			if(team[d] == team[x])
			{
				return false;
			}
		}
	}

	return true;
}



int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n,m;
	cin>>n>>m;

	for(int i = 0;i<m;++i)
	{
		int a,b;
		cin>>a>>b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	int flag = 1;
	for(int i = 1; i<=n; ++i)
	{
		if(!visited[i])
		{
			if(!dfs(i,0))
			{
				flag = 0;
				break;
			}
		}
	}

	if(!flag)
	{
		cout<<"IMPOSSIBLE";
	}
	else
	{
		for(int i = 1; i<=n; ++i)
		{
			cout<<team[i]+1<<" ";
		}
	}




	return 0;


}
