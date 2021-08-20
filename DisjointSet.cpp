#include<bits/stdc++.h>
using namespace std;

int par[100];
int Rank[100];

int find(int i)
{
	if(i == par[i])
		return i;
	return par[i] = find(par[i]);
}

void _union(int u,int v)
{
	u = find(u), v = find(v);
	if(Rank[u] < Rank[v])
		par[u] = v;
	else if(Rank[u] > Rank[v])
		par[v] = u;
	else
	{
		par[v] = u;
		Rank[u]++;
	}
}

void solve()
{
	for(int i = 1 ; i <= 26 ; ++i)
	{
		par[i] = i;
		Rank[i] = 0;
	}
	int m;	cin >> m;
	while(m--)
	{
		int u,v;	cin >> u >> v;
		_union(u,v);
	}
	if(find(2) != find(3))
		cout << "Diff component";
	else
		cout << "Same component";

}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;  
    // cin >> t;
    while(t--)
        solve(); 
    return 0;
}