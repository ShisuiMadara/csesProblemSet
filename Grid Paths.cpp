#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 +7;

int main()
{
	int n;
	cin>>n;
	
	vector<vector<char>>in(n+1, vector<char>(n+1));
	
	for(int i = 0; i<n; ++i)
	{
		for(int j = 0; j<n; ++j)
		{
			char c;
			cin>>c;
			in[i][j] = c;
		}
	}
	
	vector<vector<long long>>paths(n+1, vector<long long>(n+1,0));
	paths[0][0] = 1;
	
	for(int i = 0; i<n; ++i)
	{
		for(int j = 0; j<n; ++j)
		{
			if(in[i][j] != '*')
			{
				if(i>0)
				{
					
					paths[i][j] = paths[i][j]%mod + paths[i-1][j]%mod; //(a+b)%mod = a%mod + b%mod
				}
				if(j>0)
				{
					paths[i][j] = paths[i][j]%mod + paths[i][j-1]%mod;
				}
				
			}
			else
			{
				paths[i][j] = 0; //what is the first or the last position are itself blocked
			}
		}
	}
	
	cout<<paths[n-1][n-1]%mod;

	
}
		
	
