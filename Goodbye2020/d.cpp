/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-30 13:55:05
* @description: 
* /Users/jackbai/Desktop/Goodbye2020/d.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv d.cpp
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

int n;
ll w[1000010];

int dg[1000010];
int col[1000010];

priority_queue <pair <long long, int> > q;

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		ll sum = 0;
		cin >> n;
		while (!q.empty())
			q.pop();
		for (int i = 1; i <= n; i ++) {
			cin >> w[i];
			dg[i] = 0;
			col[i] = 1;
			sum += w[i];
			q.push(MP(w[i], i));
		}
		for (int a, b, i = 1; i < n; i ++) {
			cin >> a >> b;
			dg[a] ++;
			dg[b] ++;
		}
		cout << sum << ' ';
		int pt = 2;
		while (!q.empty() && pt != n) {
			int c = q.top().S;
			ll wc = q.top().F;
			// cerr << c << " : " << col[c] << " " << dg[c] << endl;
			if (col[c] == dg[c]) {
				q.pop();
				continue ;
			}
			sum += wc;
			col[c] ++;
			pt ++;
			cout << sum << ' ';
		}
		cout << endl;
	}

    return 0;
}