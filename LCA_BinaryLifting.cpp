#include<bits/stdc++.h>


#define ll long long
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


using namespace std;
/*
	LCA -> Find paths of two nodes stores them in vector. O(N)
	FOR Q queries -> O(Q*N);
	So if we use binary lifting we can do it in O(Q*logN)

				1 <- common ancestor but not lowest
			   / \
		 lca->2   3
			 / \  /\
		 a->4   5 6 7
		   /	^
		  8		|
		 /		b
		9 <- a
	We precompute the ancestors of each node.
	i.e 1st ancestor of node 9 is 8 , 2nd is 4 , 4th is 1
	So how about 3rd ?? 
	As we know 3 = 0011(binary) instead of moving
	9 -> 8 -> 4 -> 2 n steps we move
	9 -> 4 -> 2  log(n)	steps
	So to do these we need som precomputation
	let dp store (1,2,4,8,16....)ancestor of nodes
	dp[i][j] means (2^j)th ancestor of node i.
	dp[N][log(N/H)] total size.
	N -> number of nodes, H -> height of tree
	
	LCA(a,b)	If a & b are not on same lvl
		then bring the deepmost node to same lvl as other,
		then start binary lift if(dp[a][j] != dp[b][j])

	*/	

const int N = 1e5 + 5;
const int LOG = 17;
int dp[N][LOG];
// int parent[N];
vector<int> children[N];
int depth[N];

void dfs(int a)
{
	for(int b : children[a])
	{
		dp[b][0] = a;
		depth[b] = depth[a] + 1;
		for(int j = 1 ; j < LOG ; j++)
		{
			dp[b][j] = dp[dp[b][j-1]][j-1];
		}
		dfs(b);
	}
}


int get_lca(int a,int b)
{
	if(depth[b] > depth[a])
		swap(a,b);
	/*while(depth[a] > depth[b]) // O(n)
	{
		a = dp[a][0];
	}
	if(a == b)
		return a;
	while(a != b)  // O(n)
	{
		a = dp[a][0];
		b = dp[b][0];
	}*/
	int k = depth[a] - depth[b];

	for(int j = LOG ; j >= 0;j--)
	{
		if(k & (1 << j))
			a = dp[a][j];
	}
	if(a == b)
		return a;
	for(int j = LOG ; j >= 0 ; j--)
	{
		if(dp[a][j] != dp[b][j])	//ancestor not same move as all ancestors are same
		{							//form lowest to root
			a = dp[a][j];
			b = dp[b][j];
		}
	}
	return dp[a][0];

}

int main()
{
	int n;	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		int m;	cin >> m;
		for(int j = 0 ; j < m ; j++)
		{
			int v;	cin >> v;
			children[i].pb(v);
		}
	}
	memset(depth,0,sizeof(depth));
	dfs(0);
	int q;	cin >> q;
	FOR(i,0,q)
	{
		int a,b;	cin >> a >> b;
		cout << get_lca(a,b) << "\n";
	}

}