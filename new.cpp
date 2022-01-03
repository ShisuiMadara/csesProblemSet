#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 +7;

int main()
{
	int n,target;
	cin>>n>>target;
	
	vector<long long>arr(n);
	for(auto&c:arr)cin>>c;
	
	vector<vector<int>> dp(n+1,vector<int>(target+1,0));
	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) 
	{
		for (int j = 0; j <= target; j++) 
		{
			dp[i][j] = dp[i-1][j];
			
			if (j -arr[i-1] >= 0) 
			{
				(dp[i][j] += dp[i][j-arr[i-1]]) %= mod;
			}
		}
	}	
  
	cout << dp[n][target];
}
	
