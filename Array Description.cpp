#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 +7;

int main()
{
	int n;
	cin>>n;
	
	int till;
	cin>>till;
	
	vector<int>arr(n);
	for(auto&c:arr)
	{
		cin>>c;
	}
	
	
	vector<vector<int>>dp(n,vector<int>(till+1,0));
	
	
	if(arr[0] == 0)
	{
		for(int i = 1; i<= till; ++i)
		{
			dp[0][i] = 1; 
		}
	}
	else 
	{
		dp[0][arr[0]] = 1;
	}
	
	
	
	for (int i = 1; i < n; i++) 
	{
		if (arr[i] == 0) {
			for (int j = 1; j <= till; j++) 
			{
				for (int k : {j-1,j,j+1}) 
				{
					if (k >= 1 && k <= till)
					{
						dp[i][j] = dp[i][j]%mod + dp[i-1][k] % mod;
					}
				}
			}
		}
		else
		{
			for(int k : {arr[i]-1,arr[i],arr[i]+1})
			{
				if(k >= 1 && k<=till)
				{
					dp[i][arr[i]] = dp[i][arr[i]]%mod + dp[i-1][k]%mod;
				}
			}
		}
	}
	
	//for(auto&c:dp)
	//{
		//for(auto&d:c)
		//{
			//cout<<d<<" ";
		//}
		//cout<<"\n";
	//}
	
	int ans = 0;
	
	for(int i = 1; i <= till; ++i)
	{
		ans = ans%mod + dp[n-1][i]%mod;
	}
	cout<<ans%mod;
	
	return 0;
}

			
			
			
		
	
