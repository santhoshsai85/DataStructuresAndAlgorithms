#include<iostream>
#include<algorithm>

using namespace std;

/*void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
	return;
}*/

void heapify(int a[] ,int n,int i){
	int l=2*i + 1;
	int r=2*i + 2;
	int k=i;
	if(l < n and a[k] < a[l])
		k=l;
	if(r < n and a[k] < a[r])
		k=r;
	if(k != i){
		swap(a[i],a[k]);
		heapify(a,n,k);
	}
	return;
}

void heapsort(int a[],int n)
{
	for(int i=n/2-1;i >= 0; i--)
		heapify(a,n,i);
	for(int i=n-1;i >=0 ; i--)
	{
		swap(a[i],a[0]);
		heapify(a,i,0);
	}
}

void print(int a[],int n)
{
	for(int i=0;i < n ;i++)
		cout << a[i] << " ";
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	int n;	cin >> n;
	int a[n];
	for(int i=0;i < n ;i++)
		cin >> a[i];
	heapsort(a,n);
	print(a,n);
	return 0;
}