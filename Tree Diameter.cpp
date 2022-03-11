#include<bits/stdc++.h>
using namespace std;
 
const int MAX_N = 2e5 + 10;
 
vector<int>arr[MAX_N];
 
pair<int,int> bfs(int node)
{
	queue<pair<int,int>>q;
	
	vector<int>visited(MAX_N, 0);
	
	q.push({node,0});
	pair<int,int>current;
 
	while(!q.empty())
	{
	     current = q.front();
		visited[current.first] = 1;
		q.pop();
 
		for(auto&c:arr[current.first])
		{
			if(!visited[c])
			{
				q.push({c, current.second + 1});
			}
		}
	}
 
	return current;
 
}
int main()
{
	int n;
	cin>>n;
 
	for(int i =1; i<n; ++i)
	{
		int a,b;
		scanf("%d %d", &a, &b);
 
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
 
	//to just make the whole tree as a giant string
 
	pair<int,int> first = bfs(1);
	pair<int,int> final = bfs(first.first);
 
	printf("%d", final.second);
 
}
