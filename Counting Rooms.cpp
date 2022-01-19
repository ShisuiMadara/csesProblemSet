#include <bits/stdc++.h>
using namespace std;



vector<vector<int>>matrix(10000, vector<int>(10000, '#'));
 
void search(int i, int j){
    if(matrix[i][j] != '.') return;
 
    matrix[i][j] = '1';
 
    search(i+1, j);
    search(i-1, j);
    search(i, j+1);
    search(i, j-1);
 
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
		freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif

	int n,m;
    cin>>n>>m;
 
    
    for(int i = 1; i<=n; ++i){
        string s;
        cin>>s;
        for(int j =0; j< m; ++j){
            matrix[i][j+1] = s[j];
        }
    }
    int cnt = 0;
 
 
    for(int i = 1; i <=n; ++i){
        for(int j = 1; j<=m;++j){
 
            if(matrix[i][j] == '.'){
                search(i,j); //this calls a recursive function which marks all the connected components
                cnt ++;
 
            } 
        }
    }
 
    cout<<cnt;
}
