#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;
const int MAX_N = 2e5;
#define int long long int
 
void solve()
{
    int n;
    cin>>n;
 
    vector<int>arr(n);
 
    for(auto&c:arr)cin>>c;
 
    int ans = INT_MAX;
    for(int i = 0; i < (1<<n); ++i)
    {
        int bag1 = 0, bag2 = 0;
        for(int j = 0; j < n; ++j)
        {
            if(i & (1<<j))
            {
                bag1 += arr[j];
            }
            else
            {
                bag2 += arr[j];
            }
        }
        ans = min(ans, abs(bag1 - bag2));
 
    }
 
    cout<<ans;
}
 
 
signed main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
 
    int t = 1;
    //cin>>t;
 
    while(t--)
    {
        solve();
    }
    return 0;
}