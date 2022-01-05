#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 +7;


int main()
{
	int n;
	cin>>n;
	
	vector<long long>arr(n);
	long long sum = 0;
	
	for(int i = 1; i<=n; ++i)
	{
		arr[i-1] = i;
		sum += i;
	}
	
	if(sum%2)
	{
		cout<<0;
		return 0;
	}
	
	sum = sum/ 2;
	
		
	vector<vector<long long>>ways(n+1,vector<long long>(sum+1,0));
	
	ways[0][0] = 1;
	
	for(int i = 1; i<= n; ++i)
	{
		for(int j = 0; j<=sum; ++j)
		{
			ways[i][j] = ways[i-1][j];
			
			if(j - arr[i-1] >= 0 && ways[i][j-arr[i-1]] > 0)
			{
				ways[i][j] = ways[i][j]%mod + ways[i-1][j-arr[i-1]]%mod;
			}
		}
	}
	
	
	cout<<ways[n-1][sum]%mod;
  return 0;
  
}
	
			
