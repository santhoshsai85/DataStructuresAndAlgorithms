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

const int D = 256;  //All characters ascii values
const int P = 101; // Prime Number
/*
    Rabin Karp Algo
    Large Prime Number - Less collisions
    Hash formula - pow(d,idx(r -> l)) + character_value ,r = 0
*/


int main()
{
    string s,p; cin >> s >> p;
    int n = s.size() , m = p.size() ;
    //Precompute the value that is msb character that to be 
    //removed to optimize time complexity i.e., pow(D,len(p) - 1) % prime
    int h = 1;  //let h be precomputation value.
    for(int i = 0 ; i < m - 1 ; i++)
    {
        h = (h * D) % P;
    }

    int ph = 0 , sh = 0;

    //Calculte hash value for p and s.substr(0,len(p))
    for(int i = 0 ; i < m ; i++)
    {
        ph = (ph * D + p[i]) % P;
        sh = (sh * D + s[i]) % P;
    }

    for(int i = 0 ;i < n - m + 1 ;i++)
    {
        // cout << ph << " " << sh << "\n";
        if(ph == sh)
        {
            // cout << sh << "\n";
            int f = 0;
            for(int j = 0 ; j < m ; j++)
            {
                if(p[j] != s[i+j])
                {
                    f = 1;
                    break;
                }
            }
            if(f == 0)
                cout << "Pattern found at " << i << "\n";
        }
        if(i < n - m)
        {
            //shift value of string hash after remove the char
            //and add s[i + m] * pow(D,0);
            sh = (D*(sh - s[i]*h) + s[i + m]) % P;
            if(sh < 0)
                sh += P; 
        }
    }
}


