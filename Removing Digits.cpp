#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 +7;

int main()
{
	int n;
	cin>>n;
	
	vector<int>ways(n + 1,INT_MAX);
	ways[0] = 0;
	
	for(int i = 1; i<= n; ++i)
	{
		string s;
		s = to_string(i);
		
		for(int j = 0; j<(int)s.length(); ++j)
		{
			ways[i] = min(ways[i], 1 + ways[i-(s[j]-'0')]);
		}
	}
	cout<<ways[n];
  return 0;
}
		
	
