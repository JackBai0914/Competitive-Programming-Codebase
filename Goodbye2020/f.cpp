/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-30 16:02:33
* @description: 
* /Users/jackbai/Desktop/Goodbye2020/f.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv f.cpp
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
const ll INF = 1e18;
const ld eps = 1e-8;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

struct edge {
	int st, ed;
	edge() {}
	edge(int stt, int edd) {st = min(stt, edd), ed = max(stt, edd);}
} e[1000010];

int n, m, est = 0;

int rt[1000010];
int if_c[1000010];
int getr(int x) {return (x == rt[x] ? x : rt[x] = getr(rt[x]));}

bool mk[1000010];

int main() {
	scanf("%d %d", &n, &m);
	for (int k, a, b, i = 1; i <= n; i++) {
		scanf("%d", &k);
		if (k == 1) {
			scanf("%d", &a);
			e[++ est] = edge(a, a);
		}
		else {
			scanf("%d %d", &a, &b);
			e[++ est] = edge(a, b);
		}
	}

	for (int i = 1; i <= m; i ++)
		rt[i] = i, if_c[i] = 0;

	int cnt = 0;

	for (int i = 1; i <= n; i ++) {
		int st = e[i].st, rst = getr(st);
		int ed = e[i].ed, red = getr(ed);
		// cerr << ": " << st << " " << ed << " " << rst << " " << red << endl;
		if (st == ed) {
			if (if_c[rst])
				continue ;
			else {
				if_c[rst] = true;
				mk[i] = true;
				cnt ++;
				continue ;
			}
		}
		if (rst == red) {
			//circle
			continue ;
		}
		else {
			if (if_c[rst] && if_c[red])
				continue ;
			rt[red] = rst;
			if_c[rst] |= if_c[red];
			mk[i] = true;
			cnt ++;
			continue ;
		}
	}

	ll fans = 1;
	int cntt = cnt;
	while (cnt --)
		fans = fans * 2 % mod;
	printf("%lld %d\n", fans, cntt);
	for (int i = 1; i <= n; i ++)
		if (mk[i])
			printf("%d ", i);
	printf("\n");
    return 0;
}