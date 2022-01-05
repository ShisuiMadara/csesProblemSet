#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 +7;


int main()
{
	int n;
	cin>>n;
	
	vector<int>arr(n);
	for(auto&c:arr)cin>>c;
	
	long long sum = 0;
	for(int i = 0 ; i<n; ++i)
	{
		sum += arr[i];
	}
	//the difference between scoreOfPlayer1 and scoreOfPlayer2 shhould be maximum
	vector<vector<long long>>diff(n+1,vector<long long>(n+1,0));
	diff[0][0] = 0;
	
	for(int l = n-1; l>-1; l--)
	{
		for(int r = l; r<n; ++r)
		{
			if(l == r)
			{
				diff[l][r] = arr[l];
			}
			
			
			diff[l][r] =  max(-diff[l+1][r] + arr[l], -diff[l][r-1] + arr[r] ); //player2 tries to decrease the score difference
		}
	}
	
	cout<<(diff[0][n-1]+sum)/2; //as sum = scoreOfPlayer1 + scoreOfPlayer2 
}


	
