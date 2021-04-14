/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-01-05 14:01:00
* @description: 
* /Users/jackbai/Desktop/CR694/c.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv c.cpp
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

int n, k;
int rec[1010][2020], gp[1010];
const int P = 1010;

void init() {
	// if (n >= 5000) {
		for (int rd = 0; rd <= 1000; rd ++) {
			for (int i = -1001; i <= 1001; i ++)
				rec[rd][P + i] = k;
			if (rd == 0) {
				gp[0] = 0;
				continue ;
			}
			for (int i = -rd; i <= rd; i ++) {
				if (i == -1)		rec[rd][P + i] = (rec[rd - 1][P + i - 1] + 1) / 2;
				else if (i ==  1)	rec[rd][P + i] = rec[rd - 1][P + i + 1] / 2;
				else 	 	 		rec[rd][P + i] = (rec[rd - 1][P + i - 1] + 1) / 2 + rec[rd - 1][P + i + 1] / 2;
			}
			int lst = 1000, rst = -1000;
			for (int i = -1000; i <= 1000; i ++)
				if (rec[rd][P + i] != k) {
					lst = min (lst, i);
					rst = max (rst, i);
				}
			gp[rd] =  max (rst, -lst);
			// if (rd <= 50)
				// cerr << ": " << rd << " " << gp[rd] << endl;
		}
	// }
}

int rd = 0;
int query (int pos) {
	cout << "? " << (pos + n) % n + 1 << endl;
	int res;
	cin >> res;
	return res;
}

void output(int p) {
	cout << "! " << (p + n) % n + 1 << endl;
	exit(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	init();

	int lst = 0, pt = 0, cur, cur2;
	int st, ed;
	query(0);
	while (true) {
		rd ++;
		cur = query (pt);
		if (cur == k) {
			lst = pt;
			pt += max(0, gp[rd] - 1);
			continue ;
		}
		else {
			if (cur < k) {
				st = pt + 1;
				ed = pt + rd;
			}
			else {
				st = pt - rd;
				ed = pt;
			}
			break;
		}
	}
	// cerr << "locate: " << st << " " << ed << endl;
	while (st != ed) {
		int mid = (st + ed) >> 1;
		int vm = query(mid);
		if (vm < k)
			st = mid + 1;
		else if (vm > k)
			ed = mid - 1;
		else if (vm == k) {
			output(mid);
		}
	}
	if (query(st) == k) {
		output(st);
	}
	// cout << "fucked up" << endl;





    return 0;
}