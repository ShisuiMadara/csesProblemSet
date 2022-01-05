#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 +7;

int main()
{
	string s;
	cin>>s;
	int n = (int)s.length();
	
	unordered_map<char,int>mp;
	
	for(int i = 0; i<n; ++i)
	{
		mp[s[i]]++;
	}
	
	char ch;
	int cnt= 0;
	for(auto&c:mp)
	{
		if(c.second%2)
		{
			 cnt ++;
			 ch = c.first;
		 }
	}
	
	if(mp.size() == 1)
	{
		cout<<s;
		return 0;
	}
	
	if(cnt > 1)
	{
		cout<<"NO SOLUTION";
		return 0;
	}
	
	string half;
	string ans;
	
	for(auto&c:mp)
	{
		if(c.first != ch)
		{
			int x = c.second/2;
			while(x--)
			{
				half += c.first;
			}
		}
	}
	
	ans += half;
	
	while(mp[ch]--)
	{
		ans += ch;
	}
	reverse(half.begin(),half.end());
	
	ans += half;
	cout<<ans;
}
	
	
	
	
