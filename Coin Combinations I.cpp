#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 +7;

int main()
{
	int n,target;
	cin>>n>>target;
	
	vector<long long>arr(n);
	for(auto&c:arr)cin>>c;
	
	vector<long long>ways(target + 1,0);
	ways[0] = 1;
	
	
	for(int i = 1; i<= target; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(i - arr[j] >= 0)
			{
				ways[i] = ways[i]%mod + ways[i -arr[j]]%mod ; // (a+b)%mod = a%mod + b%mod
			}
		}
	}
	
	cout<<ways[target];
}
	
