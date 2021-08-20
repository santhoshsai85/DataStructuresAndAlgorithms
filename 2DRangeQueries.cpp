#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define mk make_pair
#define pb push_back
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



vector<int> maxSubMatrixSumQueries(vector<vector<int>>& a, int n, int m,vector<pair<int, int>> &qy, int q){
    vector<vector<int>> pre(n,vector<int>(m,0));
    for(int i = 0 ;  i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(j == 0)
                pre[i][j] = a[i][j];
            else
                pre[i][j] = a[i][j] + pre[i][j - 1];
        }
    }
    for(int j = 0 ; j < m ; j++)
    {
        for(int i = 1 ;  i < n ; i++)
        {
            pre[i][j] += pre[i - 1][j];
        }
    }
    // for(int i = 0 ;  i < n ; i++)
    // {
    //     for(int j = 0 ; j < m ; j++)
    //     {
    //         cout << pre[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    vector<int> res;
    for(int k = 0 ; k < q ; k++)
    {
        pair<int,int> t = qy[k];
        // cout << t.first << " " << t.second << "\n";
        // traverse all rows with given length and columns
        int s = 0,mx = 0,cur = 0;
        for(int i = 0 ; i < n - t.first + 1 ; i++)
        {
            for(int j = 0 ; j < m - t.second + 1 ; j++)
            {
                if(i == 0)
                {
                    if(j == 0)
                        s = pre[i + t.first - 1][j + t.second - 1];
                    else
                        s = pre[i + t.first - 1][j + t.second - 1]
                            - pre[i + t.first - 1][j - 1];
                }
                else
                {
                    if(j == 0)
                        s = pre[i + t.first - 1][j + t.second - 1] - pre[i - 1][j + t.second - 1];
                    else
                        s = pre[i + t.first - 1][j + t.second - 1]
                            - pre[i + t.first - 1][j - 1] - pre[i - 1][j + t.second - 1] + pre[i - 1][j - 1];
                }
                mx = max(s,mx);
            }
        }
        res.push_back(mx);
    }
    return res;
}

signed main(){
    int n,m;	cin >> n >> m;
    vector<vector<int>>	a(n,vector<int>(m));
    FOR(i,0,n)
    {
    	FOR(j,0,m)
    	{
    		cin >> a[i][j];
    	}
    }
    int q;	cin >> q;
    vector<pii>	qy;
    FOR(i,0,q)
    {
    	int x,y;	cin >> x >> y;
    	qy.pb({x,y});
    }
    vector<int> res = maxSubMatrixSumQueries(a,n,m,qy,q);
    for(auto &i : res)
    {
    	cout << i << " ";
    }
    return 0;
}