#include<bits/stdc++.h>
using namespace std;

/*
	Ranged Queries + Updates
	Update -> O(logN)
	range sum -> O(logN)
*/

/*
	(l,r) this range sum is stored
	l -> number(r) formed by turning rightmost bit + 1
	r -> r 
	Ex : (i)Lets take 3 -> 11 of bit -> 10(2) + 1 = 3
	So,it (3,3)
		(ii)Lets take 4 -> 100 of bit -> 000(0) + 1 = 1
		So, it is(1,4)
	2's compliment is 1's compliment + 1
	Ex: 3 -> 11 -> 00 + 1 -> 01(1)
	INPUT:
	2 1 1 3 2 3 4 5 6 7 8 9
	3
	1 1 6
	2 3 6
	1 1 6
	OUTPUT:
	0 2 3 1 7 2 5 4 21 6 13 8 30 
	12
	18

*/

/*
	UPADTES n : O(logn)
	- 2's Compliment of n
	- & with n
	- Add the above obtained number with n
	Formula : n = n + (n & -n)
*/

// const int N = 13;
vector<int> BIT;

void update(int i,int N,int val)
{
	while(i <= N)
	{
		// cout << "B" << BIT[i] << "\n";
		BIT[i] += val;
		// cout << "A" << BIT[i] << "\n";
		i = i + (i & (-i));
	}
}

int sum(int i)
{
	// cout << i << "\n";
	int s = 0;
	while(i > 0)
	{
		s += BIT[i];
		i = i - (i & (-i));
	}
	// cout << s << "\n";
	return s;
}

int rangeSum(int l,int r)
{
	return sum(r) - sum(l - 1);
}



int main()
{
	int N,q;	cin >> N >> q;
	BIT.resize(N+1,0);
	vector<int> a(N);
	for(int i = 1 ; i <= N ; i++)
	{  
		int val;	cin >> val;
		a[i - 1] = val;
		update(i,N,val);
	}
	for(int i : BIT)
		cout << i << " ";
	cout << "\n";
	// int q;	cin >> q;
	while(q--)
	{
		int type;	cin >> type;
		if(type == 2)
		{
			int l,r;	cin >> l >> r;
			cout << rangeSum(l,r) << "\n";
		}
		else
		{
			int idx,upval;	cin >> idx >> upval;
			upval -= a[idx - 1];
			update(idx,N,upval);
		}
	}
}