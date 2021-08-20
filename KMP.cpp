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
    Knuth Moris Patt Algo  O(n + m) 
    Precomputations LPS[] (longest pre and suff)
*/

int main(){
    string s,p; cin >> s >> p;
    int n = s.size() , m = p.size();
    vector<int> lps(m,0);
    //fill lps using two pointers
    //i & j if char at i & j dont match j++;
    //Else lps[j] = i + 1
    int i = 0 , j = 1;
    while(j < m)
    {
        if(p[i] == p[j])
        {
            lps[j++] = ++i;
        }
        else
        {
            if(i != 0)
                i = lps[i - 1];
            else
                j++;
        }
    }
    //Searching
    i = 0 , j  = 0;
    while(i < n)
    {
        if(s[i] == p[j])
        {
            i++;
            j++;
        }
        if(j == m)
        {
            cout << "Patter found at " << i - j << "\n";
            //Reset j as j is out of bounds for lps[]
            j = lps[j - 1];
        }
        else if(i < n && s[i] != p[j])
        {
            //Check prev idx of j in lps
            //and start from there
            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return 0;
}