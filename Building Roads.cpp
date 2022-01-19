#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
 
int n, m, visited[MAX_N] = {0};
vector<int> arr[MAX_N];

void dfs(int a)
{
	visited[a] = 1;
	for(auto&c:arr[a])
	{
		if(!visited[c])
		{
			dfs(c);
		}

	}
}

int main()
{
	#ifndef ONLINE_JUDGE
 
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
 
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
 
	#endif

	int m;
	cin>>n>>m;


	for(int i = 0; i<m; ++i)
	{
		int a,b;
		cin>>a>>b;
	

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	vector<int>ans;

	int cnt = 0;
	for(int i = 1; i<=n; ++i)
	{
		if(!visited[i])
		{
			dfs(i);
			ans.push_back(i);
			cnt++;
		}
	}

	cout<<ans.size()-1<<'\n';
	for(int i = 1; i<(int)ans.size(); ++i)
	{
		cout<<ans[i-1]<<" "<<ans[i]<<"\n";
	}

	return 0;


}
