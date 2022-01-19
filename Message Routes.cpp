#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
 
vector<vector<int>>arr(MAX_N);
vector<int>visited(MAX_N, 0);
vector<int>parent(MAX_N,0);


stack<int>ans;

void solve(int x)
{
	if(parent[x] == x)
	{
		return;
	}
	ans.push(x);

	solve(parent[x]);

}



int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n,m;
	cin>>n>>m;

	for(int i = 0; i<m; ++i)
	{
		int a,b;
		cin>>a>>b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	queue<int>q;

	q.push(1);
	parent[1] = 1;

	while(!q.empty())
	{
		int x = q.front();
		visited[x] = 1;
		q.pop();

			for(auto&c:arr[x])
			{
				if(!visited[c])
				{
					parent[c] = x;
					q.push(c);
					visited[c] = 1;
				}
			}
		
	}

	solve(n);

	if(parent[n] == 0)
	{
		cout<<"IMPOSSIBLE";
		return 0;
	}

	cout<<ans.size()+1<<'\n';
	cout<<1<<" ";
	while(!ans.empty())
	{
		cout<<ans.top()<<" ";
		ans.pop();
	}


	return 0;


}
