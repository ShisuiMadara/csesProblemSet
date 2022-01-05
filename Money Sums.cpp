#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 +7;

int main()
{
	int n;
	cin>>n;
	
	vector<int>arr(n);
	for(auto&c:arr)cin>>c;
	
	int money = *max_element(arr.begin(),arr.end());
	money = money*n;
	//cout<<"MONEY IS "<<money;
	
	//sort(arr.begin(),arr.end());
	
	vector<vector<bool>>dp(n + 1, vector<bool>(money+1,false));
	dp[0][0] = true;
	
	for(int i = 1; i<=n; ++i)
	{
		for(int j = 0; j<=money; ++j)
		{
			dp[i][j] = dp[i-1][j];
		
			
			if(j-arr[i-1] >= 0 && dp[i-1][j-arr[i-1]] )
			{
				dp[i][j] = true;
			}
			
		}
	}
	
	vector<int>ans;
	
	
	
	
	for(int i= 1; i<=money; ++i)
	{
		if(dp[n][i])
		{
			ans.push_back(i);
		}
	}
	
	cout<<(int)ans.size()<<'\n';
	for(auto&c:ans)
	{
		cout<<c<<' ';
	}
	return 0;
}
			
			
			
		
	
