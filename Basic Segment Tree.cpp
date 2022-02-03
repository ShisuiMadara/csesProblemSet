#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;

vector<int>arr(MAX_N);
vector<long long>seg_tree(4*MAX_N);


void build(int node, int left,int right)
{
	if(left == right)
	{
		seg_tree[node] = arr[left];
		return;
	}
	
	int mid = (left + right)/2;
	
	build(2*node, left,mid);
	build(2*node +1,mid+1,right);
	
	seg_tree[node] = seg_tree[2*node] + seg_tree[2*node +1];
}

void update(int node,int left,int right,int index,int val)
{
	if(left == right)
	{
		seg_tree[node] = val;
		return;
	}
	
	int mid = (left +right)/2;
	
	if(index <= mid && index >= left)
	{
		update(2*node,left,mid,index,val);
	}
	else
	{
		update(2*node +1,mid+1,right,index,val);
	}
	
	seg_tree[node] = seg_tree[2*node] + seg_tree[2*node +1];
}
	
long long query(int node,int left,int right,int qleft,int qright)
{
	if(qleft > right || qright < left)
	{
		return 0;
	}
	
	if(right <= qright && left >= qleft)
	{
		return seg_tree[node];
	}
	
	int mid = (left+right)/2;
	
	long long left_child = query(2*node,left,mid,qleft,qright);
	long long right_child = query(2*node +1,mid+1,right,qleft,qright);
	
	return (left_child + right_child);
}


int main()
{
	int n,q;
	cin>>n>>q;
	
	for(int i = 1; i<=n; ++i)
	{
		cin>>arr[i];
	}
	
	build(1,1,n);
	
	while(q--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		
		b++;
		
		if(a == 1)
		{
			
			update(1,1,n,b,c);
		}
		else
		{
			
			cout<<query(1,1,n,b,c)<<'\n';
		}
	}
	
	return 0;
}
		
	



	
	
