#include<bits/stdc++.h>
using namespace std;

#define int double
#define ld long double
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define ft first
#define sd second
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define RFOR(i,a,n) for(int i=a;i>=n;i--)
#define MAX 100001
#define pdd pair<double,double>
#define pii pair<int,int>
#define pip pair<int,pair<int,int>>
#define ppi pair<pair<int,int>,int>
#define pll pair<ll,ll>
#define ppl pair<pair<ll,ll>,ll>
#define all(a) a.begin(), a.end()
#define rll(a) a.begin(), a.end(),greater<int>() 
#define MOD 1000000007

const int precision = 1e-6;
/*int gcd(int a,int b)
{
	while(b)
	{
		a %= b;
		swap(a,b);
	}
	return a;
}
*/
int dist(pii a,pii b)
{
	int x = a.ft - b.ft;
	int y = a.sd - b.sd;
	x *= x;
	y *= y;
	return sqrt(x + y);
}


// Calculates Y cord for given X;
int fun(vector<int>& v,int X,pii a[],int32_t n)
{
	int Y = -1 * (v[2] + (v[0] * X)) / v[1];
	pii p(X,Y);
	int ans = 0;
	for(int32_t i = 0 ; i < n ;i++)
	{
		ans += dist(p,a[i]);
	}
	return ans;
}



/*Ternery Search

dec then inc
If(m1 > m2)	L = m1;
ELse R = m2

inc then dec
If(m1 < m2) L = m1;
ELse R = m2;

*/

void solve()
{
	int32_t n;	cin >> n;
	pii a[n];
	for(int32_t i = 0 ; i < n ;i++)
		cin >> a[i].ft >> a[i].sd;
	vector<int> v{1,-1,-3};
	// Ternery Search
	int L = -1e6 , R = 1e6;

	while(R - L > precision)
	{
		int m1 = L + (R - L) / 3;
		int m2 = R - (R - L) / 3;
		// cout << m1 << " " << m2 << "\n";
		int d1 = fun(v,m1,a,n);
		int d2 = fun(v,m2,a,n);

		if(d1 > d2)
			L = m1;
		else
			R = m2;
	}
	cout << fun(v,(L + R)/2,a,n);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t;  cin >> t; 
    // while(t--)
    // {
        solve();
    // }
    return 0;
}

