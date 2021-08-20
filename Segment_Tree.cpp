#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
vector<int> seg;
 
void build(vector<int>& a,int idx,int l,int r)
{
	if(l == r)
	{
		seg[idx] = a[l];
		return;
	}
	int m = l + (r - l) / 2;
	build(a,2*idx+1,l,m);
	build(a,2*idx+2,m+1,r);
	seg[idx] = min(seg[2 * idx + 1],seg[2 * idx + 2]);
	return;
}
 
void update(vector<int>& a, int idx,int l,int r,int val,int node)
{
	if(l == r)
	{
		a[idx] = val;
		seg[node] = val;
		return;
	}
	int m = l + (r - l) / 2;
	if(idx >= l && idx <= m)
	{
		update(a,idx,l,m,val,2 * node + 1);
	}
	else
	{
		update(a,idx,m + 1, r ,val,2 * node + 2);
	}
	seg[node] = min(seg[2 * node + 1] , seg[2 * node + 2]);
 
}
 
int rangeQuery(int idx,int i,int j,int l,int r)
{	//i - j  l - r
	//3 - 8  3 - 4 lies inside completely 
	if(i >= l && j <= r)	//completely lies in range (3,4) ->(3,8).
	{
		return seg[idx];
	}
	if(l > j || r < i)
	{
		return INT_MAX;
	}
	int m = i + (j - i) / 2;
	int left = rangeQuery(2 * idx + 1, i , m , l , r);
	int right = rangeQuery(2 * idx + 2 , m + 1 , j, l ,r);
	return min(left,right); 
}
 
signed main()
{
	int	n,q;	cin >> n >> q;
	seg.resize(4*n);
	vector<int> a(n);
	for(int i = 0; i < n ; i++)
	{
		cin >> a[i];
	}
	build(a,0,0,n-1);
	// for(auto &i : seg)
	// 	cout << i << " ";
	// cout << "\n";
	while(q--)
	{
		int type;	cin >> type;
		if(type == 1)
		{
			int idx,val;	cin >> idx >> val;
			idx--;
			// a[idx] = val;
			update(a,idx,0,n - 1,val,0);
		}
		if(type == 2)
		{
			int l,r;	cin >> l >> r;
			l--,r--;
			cout << rangeQuery(0,0,n - 1,l,r) << "\n"; 
		}
	}
	// for(auto &i : seg)
	// 	cout << i << " ";
	// cout << "\n";
}