#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;



void solve()
{
    int a,b;
    cin>>a>>b;

    if(((a+b)%3==0 &&(2*a>=b) && (2*b>=a)))
    {
        cout<<"YES\n";
        return;
    }

    cout<<"NO\n";
    return;

}



int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


     ll test=1;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
