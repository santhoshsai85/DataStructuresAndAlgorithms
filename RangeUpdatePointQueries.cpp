#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mk make_pair
#define pb push_back
#define ft first
#define sd second
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define RFOR(i,a,n) for(int i=a;i>=n;i--)
#define MAX 100001
#define pdd pair<double, double>
#define pii pair<int,int>
#define pip pair<int,pair<int,int>>
#define pll pair<ll,ll>
#define ppl pair<pair<ll,ll>,ll>
#define all(a) a.begin(), a.end()
#define rll(a) a.begin(), a.end(),greater<int>()
#define MOD 1000000007


vector<int> BIT;

void update(int i,int n,int val)
{
	while(i <= n)
	{
		BIT[i] += val;
		i += (i & -i);
	}
}

int point(vector<int>& a,int i)
{
	int s = 0,k = a[i];
	while(i > 0)
	{
		s += BIT[i];
		i -= (i & -i);
	}
	return s;
}


signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;	cin >> n >> q;
	vector<int> a(n + 1);
	BIT.resize(n + 1,0);
	a[0] = 0;
	FOR(i,1,n+1)
	{
		cin >> a[i];
		update(i,n,a[i] - a[i - 1]);
	}
	// for(auto &i : BIT)
	// 	cout << i << " ";
	// cout << "\n";
	while(q--)
	{
		int type;	cin >> type;
		if(type == 1)
		{
			int l,r,val;	cin >> l >> r >> val;
			update(l,n,val);
			update(r + 1 ,n,-val);
		}
		else
		{
			int idx;	cin >> idx;
			cout << point(a,idx) << "\n";
		}
	}
	cout << "\n";
	
}



