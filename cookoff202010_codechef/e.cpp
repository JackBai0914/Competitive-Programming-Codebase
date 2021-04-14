/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-18 17:44:14
* @description: 
* /Users/jackbai/Desktop/OI/cookoff202010_codechef/e.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv e.cpp
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
const int MOD = 1000000007; 
const ll INF = 1e18;
const ld eps = 1e-8;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int n, tot = 0;

int b[110];

int query (int x, int k) {
	cout << "? " << x << " " << k << endl;
	int ans;
	cin >> ans;
	return ans;
}

int how_many_larger_than(int x) {
	int cur = query(n + 1, x);
	return cur - tot;
}

//in index [st, ed], there are num numbers equal to val
void work2 (int st, int ed, int num2, int val, int all) {
	if (num2 == 0)
		return ;
	if (st == ed) {
		b[st] = val;
		return ;
	}
	int mid = (st + ed) >> 1;

}

vector <pii> v;
int s[20];

//in value [st, ed], there are num numbers
void work (int st, int ed, int num) {
	if (num == 0)
		return ;
	if (st == ed) {
		// work2(1, n, num, st, num);
		v.push_back(MP(st, num));
		return ;
	}
	int mid = (st + ed) >> 1;
	int cnt = how_many_larger_than(mid);
	work (st, mid, num - cnt);
	work (mid + 1, ed, cnt);
}


int main() {
	int t;
	cin >> t;
	while (t --) {
		memset(b, 0, sizeof b);
		cin >> n;
		tot = query (n + 1, 1000000);
		work (1, 1000000, n);
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i ++)
			s[i] = (i ? s[i - 1] + v[i].S : v[i].S);
		for (int i = 0; i < v.size(); i ++) {
			work2 (1, n, v[i].S, v[i].F, )
		}
	}

    return 0;
}