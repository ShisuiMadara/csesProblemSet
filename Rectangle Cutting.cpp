#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 +7;

int main()
{
	int a,b;
	cin>>a>>b;
	
	vector<vector<int>>dp(a+1,vector<int>(b+1,INT_MAX));
	
	
	for(int i = 1; i<=a; ++i)
	{
		for(int j = 1; j<=b; ++j)
		{
			if( i == j)
			{
				dp[i][j] = 0;
			}
			
			for(int k = 1; k<i; ++k)
			{
				dp[i][j] = min(dp[i][j],dp[i-k][j]+dp[k][j]+1);
			}
			for(int k =1; k<j; ++k)
			{
				dp[i][j] = min(dp[i][j],dp[i][j-k]+dp[i][k]+1);
			}
		}
	}
	//for(auto&c:dp)
	//{
		//for(auto&d:c)
		//{
			//cout<<d<<" ";
		//}
		//cout<<'\n';
	//}
	cout<<dp[a][b];
	return 0;
}
			
		
