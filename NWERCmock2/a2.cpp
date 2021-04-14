/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-27 17:27:16
* @description: 
*  
* 
* @notes: 
* g++ -fsanitize=address -ftrapv 
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int mod = 1000000007; 
const ll oo = 1e18;
const ld eps = 1e-8;
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl


const int N=1e6 + 10;
int n, sz, b[N];
vector<int> a,pos[N];

int main()
{
	cin >> n;
	for(int i=1;i<=n;++i)
	{
		int x;
		cin >> x;
		if(a.empty() || a.back()!=x) a.push_back(x);
	}
	n = (int)a.size();
	for(int i = 0; i < n; ++ i) b[i] = a[i];
	sort(b,b + n);
	sz = unique(b,b+n) - b;
	for(int i = 0;i < n;++ i) {
		a[i] = lower_bound(b,b + sz,a[i]) - b;
		pos[a[i]].push_back(i);
	}
	pii s1 = MP(0,n), s2 = MP(0,n);
	for(int i = 0; i < sz - 1; ++ i)
	{
		pii t1 = s1,t2 = s2;
		for(int j = 0; j < (int)pos[i].size(); ++ j)
		{
			int p=pos[i][j];
			if(p==n-1 || a[p]+1!=a[p+1]) continue;
			pii s=MP(0,n);
			if(p ^ s1.S) s = s1; else s = s2;
			++ s.F;
			s.S = p +1;
			if(pos[i+1].size() == 1) s.S = n;
			if(s>t1) t2=t1,t1=s;
			else if(s>t2) t2=s;
		}
		s1 = t1;
		s2 = t2;
	}
	cout << n - s1.F - 1 << endl;
	return 0;
}
