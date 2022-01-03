#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 +7;

int main()
{
	int n,target;
	cin>>n>>target;
	
	vector<long long>arr(n);
	
	for(auto&c:arr)cin>>c;
	
	vector<long long> ans(10000000,INT_MAX);
	ans[0] = 0;
	
	for(int i = 1; i <= target; ++i)
	{
		for(int j = 0; j<n; ++j)
		{
			if(i - arr[j] >= 0)
			{
				ans[i] = min(ans[i] , ans[i -arr[j]] + 1);
			}
		}
	}
	
	if(ans[target] == INT_MAX)
	{
		cout<<-1;
	}
	else
	{
		cout<<ans[target];
	}
	
	return 0;
}
