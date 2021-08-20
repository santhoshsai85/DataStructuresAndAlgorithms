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

/*
	1 2 3 4 5 6 7 8
	^			  ^
	^	  ^ ^     ^
	dp[i][pow = 8] = min(dp[i][pow=4],dp[i + pow = 4 + 1][pow=4]
	dp[i][j] = min(dp[i][j - 1],dp[i + (1 << (j - 1)) + 1][j - 1])

	9(1001) -> 8 + 1 but in sparse we dont need logn time
	as min function is idempotent i.e A . A = A
	so we can just check for min([l,l+8],[r-8,r];

	//O(1) -> min,max,and,or,gcd (A . A = A)(Imdempotent)
	//O(logN)->sum,xor (A . A = 0)(Inversion)
	//Precomputation for log2(R-L+1) to obtain O(1) complexity for q queries.
	//log(base x) is nothing but how many time n to be divided by x to get 1.
	/for not imdepotent
	//[1,5]=> 5-1+1 = 4+1 => [1,4]+[5,5]
	//start from max possible length 2^k
	int R,L;
	int s=0;
	for(int j = k ; j >= 0 ; j++)
	{
		if((1<<j) <= R-L+1){
			s+=dp[L][j];
			L+=(1<<j);
		}
	}
*/

signed main()
{

	int N,q;	cin >> N >> q;
	vector<int> a(N);
	for(auto &i : a)
	{
		cin >> i;
	}
	int log[N+1];
	log[1] = 0;
	for (int i = 2; i <= N; i++)
	    log[i] = log[i/2] + 1;
	int LOG = (int)log2(N);
	int dp[N + 1][LOG + 1];
	memset(dp,INT_MAX,sizeof(dp));
	for(int i = 0 ; i < N ; i++)
		dp[i][0] = a[i];		//min element of segment of length 1 i.e 2^0.
	for(int j = 1 ; j <= LOG ; j++)
	{
		for(int i = 0; i + (1 << j) <= N ;i++)
		{
			dp[i][j] = min(dp[i][j - 1],dp[i + (1 << (j - 1))][j - 1]);
		}
	}
	// for(int j = 0 ; j <= LOG ; j++)
	// {
	// 	for(int i = 0; i + (1 << j) <= N ;i++)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	while(q--)
	{
		int L,R;	cin >> L >> R;
		L--,R--;
		int j = log[R - L + 1];
		int minimum = min(dp[L][j], dp[R - (1 << j) + 1][j]);
		cout << minimum << "\n";
	}
}