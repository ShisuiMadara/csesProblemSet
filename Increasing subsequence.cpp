#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 +7;


int main()
{
	int n;
	cin>>n;
	
	vector<int>arr(n);
	for(auto&C:arr) cin>>C;
	
	vector<int>ans;
	
	for(int i = 0; i<n; ++i)
	{
		auto x = lower_bound(ans.begin(),ans.end(),arr[i]);
		
		if(x != ans.end())
		{
			*x = arr[i]; //array is updated to this least element
		} 
		else
		{
			ans.push_back(arr[i]);
		}
		
		//for(auto&c:ans)
		//{
			//cout<<c<< " ";
		//}
		
		//cout<<'\n';	
		
		
	}
	cout<<ans.size();
	
	return 0;
}
			
			
		
	
