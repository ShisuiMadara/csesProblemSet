#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 +7;

int main()
{
	int n;
	cin>>n;
	
	int money;
	cin>>money;
	
	vector<int>cost(n),pages(n);
	
	for(auto&c:cost)cin>>c;
	
	for(auto&c:pages)cin>>c;
	
	vector<vector<int>>dp(n+1,vector<int>(money+1,0));
	
//bottom up approach
	for(int i = 1; i<= n; ++i)
	{
		for(int j = 0; j<=money; ++j)
		{
			dp[i][j] = dp[i-1][j];
			if(j -cost[i-1] >= 0)
			{
				dp[i][j] = max(dp[i][j], dp[i-1][j - cost[i-1]] + pages[i-1]);
			}
		}
	}
	
	cout<<dp[n][money];
	return 0;
}
				
			
			
		
	
