#include<bits/stdc++.h>
using namespace std;
 
const int MAX_N = 2e5 + 10;
 
vector<int>arr[MAX_N];
vector<int>dist(MAX_N, -1);
 
//expand the graph along the diameter
//the maximum distance for a node will be the maximum distance from either of the ends of the diameter

pair<int,int>bfs(int node)
{
	queue<pair<int,int>>q;
	vector<int>visited(MAX_N, 0);
 
	pair<int,int>current;
 
	q.push({node, 0});
 
	while(!q.empty())
	{
		current = q.front();
		q.pop();
		visited[current.first] = 1;
 
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
 
void find_distance(int node)
{
	vector<int>visited(MAX_N, 0);
	queue<pair<int,int>> q;
 
	q.push({node, 0});
 
	while(!q.empty())
	{
		pair<int,int> here = q.front();
		visited[here.first] = 1;
		q.pop();
 
		for(auto&c:arr[here.first])
		{
			if(!visited[c])
			{
				
				dist[c] = max(dist[c], here.second + 1);
				q.push({c, here.second + 1});
			}
		}
	}
}
 
int main()
{
	int n;
	scanf("%d", &n);
 
	for(int i = 1; i<n; ++i)
	{
		int a,b;
		scanf("%d %d", &a,&b);
 
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
 
	pair<int,int> end1 = bfs(1);
	pair<int,int> end2 = bfs(end1.first);
 
	dist[end1.first] = end2.second;
	dist[end2.first] = end2.second;
 
	find_distance(end1.first);
	find_distance(end2.first);
 
	for(int i = 1; i<=n; ++i)
	{
		
		printf("%d \n", dist[i]);
	}
}
