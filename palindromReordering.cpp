#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;



void solve()
{
    string s;
    cin>>s;

    int n = s.length();

    map<char, int>mp;

    for(int i = 0; i<n; ++i)
    {
        mp[s[i]] ++;
    }

    int odd = 0;
    for(auto&c:mp)
    {
        if(c.second%2)
        {
            odd++;
        }
    }   

    if(odd > 1)
    {
        cout<<"NO SOLUTION";
        return;
    }

    string ans;

    char mark;
    int count = -1;

    for(auto&c:mp)
    {
        if(c.second%2)
        {
            mark = c.first;
            count = c.second;
            continue;
        }

        for(int i = 0; i<c.second/2; ++i)
        {
            ans += c.first;
        }
    }

    string temp;

    temp = ans;
    if(count != -1)
    {
        for(int i = 0; i<count/2; ++i)
        {
            ans += mark;
        }
        ans += mark;

        temp = ans.substr(0,ans.length()-1);
    }


   

    reverse(temp.begin(), temp.end());

    ans += temp;

    cout << ans;
    return;
}



int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

     ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
