#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pb push_back
#define ff first
#define sec second
#define int long long
#define vi vector<int>
#define vp vector<pair<int,int>>
#define fast_io ios_base :: sync_with_stdio(false); cin.tie(nullptr);
#define vvi vector<vector<int>>
#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,a,b) for(int i = a; i < b; i++)
// Define the each element of segment tree vector as follows:
// element.first = sum of segment
// element.second.first = a(first term of AP)
// element.second.second = d(common difference in AP)
vector<ll>st(800000);
vector<pair<long long, long long>> lazy(800000); 
 
void buildtree(int si, int ss, int se, vi &vec){
    if(ss == se){
        st[si] = vec[ss];
        return;
    }
 
    int mid = (ss + se)/2;
    
    buildtree(2*si, ss, mid, vec);
    buildtree(2*si+1, mid+1, se, vec);
 
    st[si] = st[2*si] + st[2*si+1];
    return;
}
 
void update(int si, int ss, int se, int qs, int qe, int a, int d){
    if(lazy[si].ff !=0 || lazy[si].sec!=0){
        ll x = lazy[si].ff;
        ll y = lazy[si].sec;
        st[si] += ((se-ss+1)*(2*x + (se-ss)*y))/2;
        lazy[si].ff = 0;
        lazy[si].sec = 0;
        if(ss != se){
            int mid = (ss + se)/2;
            lazy[2*si].ff += x;
            lazy[2*si].sec += y;
            lazy[2*si+1].ff += x + y*(mid+1 - ss);
            lazy[2*si+1].sec += y;
        }
        
    }
    // Segment completely outside the range
    if(ss > qe || se < qs){
        return;
    }
 
    // Segment completely inside the query range
    if(ss >= qs && se<= qe){
        int x =  a+(ss-qs)*d;
        st[si] += ((se-ss+1)*(2*x + (se-ss)*d))/2;
        if(ss != se){
            int mid = (ss + se)/2;
            lazy[2*si].ff += x;
            lazy[2*si].sec += d;
            lazy[2*si+1].ff += x+ d*(mid+1-ss);
            lazy[2*si+1].sec += d;
        }
        return;
    }
    // int xx = max(ss, qs);
    // int yy = min(qe, se);
    // st[si] += ((yy-xx+1)(2(a+(ss-qs)*d) + (yy-xx)*d))/2;
 
    int mid = (ss + se)/2;
    update(2*si, ss, mid, qs, qe, a, d);
    update(2*si+1, mid+1, se, qs, qe, a, d);
 
    st[si] = st[2*si] + st[2*si+1];
 
    return;
    
}
 
ll query(int si, int ss, int se, int qs, int qe){
    if(lazy[si].ff !=0 || lazy[si].sec!=0){
        ll x = lazy[si].ff;
        ll y = lazy[si].sec;
        st[si] += ((se-ss+1)*(2*x + (se-ss)*y))/2;
        lazy[si].ff = 0;
        lazy[si].sec = 0;
        if(ss != se){
            int mid = (ss + se)/2;
            lazy[2*si].ff += x;
            lazy[2*si].sec += y;
            lazy[2*si+1].ff += x + y*(mid+1-ss);
            lazy[2*si+1].sec += y;
        }
         
        
    }
    // Segment completely outside the range
    if(ss > qe || se < qs)
        return 0;
 
    if(ss >= qs && se <= qe)
        return st[si];
 
    int mid = (ss + se)/2;
 
    return query(2*si, ss, mid, qs, qe) + query(2*si+1, mid+1, se, qs, qe);
}
 
 
 
signed main(){
    fast_io;
    int t;
    // cin>>t;
    t = 1;
    while(t--){
        int n,q; cin>>n>>q;
        vi vec(n+1);
        Rep(i,1,n+1)
            cin>>vec[i];
 
        buildtree(1, 1, n, vec);
 
        while(q--){
            int code; cin>>code;
            if(code ==1){
                int a,b; cin>>a>>b;
                update(1, 1, n, a, b, 1, 1);
            }
 
            else{
                int a,b; cin>>a>>b;
                cout<<query(1, 1, n, a, b)<<endl;
            }
        }
    }
}
