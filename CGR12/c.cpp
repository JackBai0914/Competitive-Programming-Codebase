/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-06 14:59:57
* @description: 
* /Users/jackbai/Desktop/CGR12/c.cpp 
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

int n;
int mp[330][330];

// bool is_line (int a, int b, int c) {return (a == 3 && b == 3 && c == 3) || (a == 2 && b == 2 && c == 2);}

// int calc_val (int x, int y) {
// 	int ans = 0;
// 	if (x > 2)			ans += is_line(mp[x - 2][y], mp[x - 1][y], mp[x][y]);
// 	if (x > 1 && x < n)	ans += is_line(mp[x + 1][y], mp[x - 1][y], mp[x][y]);
// 	if (x < n - 1)		ans += is_line(mp[x + 2][y], mp[x + 1][y], mp[x][y]);
// 	if (y > 2)			ans += is_line(mp[x][y - 2], mp[x][y - 1], mp[x][y]);
// 	if (y > 1 && y < n)	ans += is_line(mp[x][y + 1], mp[x][y - 1], mp[x][y]);
// 	if (y < n - 1)		ans += is_line(mp[x][y + 2], mp[x][y + 1], mp[x][y]);
// 	return ans;
// }
// int val[330][330];
// priority_queue <pii> q[6];

// void eval (int x, int y) {
// 	if (x < 1 || x > n || y < 1 || y > n)
// 		return ;
// 	if (!mp[x][y])
// 		return ;
// 	int cur = calc_val(x, y);
// 	mp[x][y] ^= 1;
// 	int aft = calc_val(x, y);
// 	mp[x][y] ^= 1;
// 	val[x][y] = cur - aft;
// 	if (val[x][y] >= 0)
// 		q[val[x][y]].push(MP(x, y));
// }


int main() {
	int t;
	cin >> t;
	while (t --) {
		int bar[3];
		int b2[3];
		bar[0] = bar[1] = bar[2] = 0;
		b2[0] = b2[1] = b2[2] = 0;
		// for (int i = 0; i < 6; i ++)
		// 	while (!q[i].empty())
		// 		q[i].pop();
		cin >> n;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++) {
				char c;
				cin >> c;
				mp[i][j] = (c == '.' ? 0 : (c == 'X' ? 2 : 3));
				if (mp[i][j] == 2) {
					bar[(i + j) % 3] ++;
				}
				if (mp[i][j] == 3) {
					b2[(i + j) % 3] ++;
				}
			}
		int mn = 1000000, a, b;
		for (int i = 0; i < 3; i ++)
			for (int j = 0; j < 3; j ++)
				if (i != j && bar[i] + b2[j] < mn) {
					mn = bar[i] + b2[j];
					a = i;
					b = j;
				}
		cerr << bar[0] << " " << bar[1] << " " << bar[2] << endl;
		cerr << b2[0] << " " << b2[1] << " " << b2[2] << endl;
		int num = 0;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++) {
				if (mp[i][j] == 2 && (i + j) % 3 == a) {
					mp[i][j] ^= 1;
					num ++;
				}
				if (mp[i][j] == 3 && (i + j) % 3 == b) {
					mp[i][j] ^= 1;
					num ++;
				}
			}


		cerr << "num : " << num << endl;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				if (mp[i][j] == 0)	cout << '.';
				if (mp[i][j] == 2)	cout << 'X';
				if (mp[i][j] == 3)	cout << 'O';
			}
			cout << endl;
		}
		// int all = 0;
		// for (int i = 1; i <= n; i ++)
		// 	for (int j = 1; j <= n; j ++)
		// 		if (mp[i][j]) {
		// 			int cur = calc_val(i, j);
		// 			all += cur;
		// 			mp[i][j] ^= 1;
		// 			int aft = calc_val(i, j);
		// 			mp[i][j] ^= 1;
		// 			val[i][j] = cur - aft;
		// 			// cerr << ": " << i << " " << j << " " << cur << " " << aft << endl;
		// 			if (val[i][j] >= 0)
		// 				q[val[i][j]].push(MP(i, j));
		// 		}
		// all /= 3;
		// int num = 0;
		// while (all != 0) {
		// 	int v = 5;
		// 	while (q[v].empty())
		// 		v --;
		// 	pii p = q[v].top();
		// 	q[v].pop();
		// 	if (v != val[p.F][p.S])
		// 		continue ;
		// 	num ++;
		// 	all -= v;
		// 	cerr << "change " << p.F << " " << p.S << " " << v << endl;
		// 	mp[p.F][p.S] ^= 1;
		// 	eval(p.F, p.S);
		// 	eval(p.F - 1, p.S);
		// 	eval(p.F - 2, p.S);
		// 	eval(p.F + 1, p.S);
		// 	eval(p.F + 2, p.S);
		// 	eval(p.F, p.S - 1);
		// 	eval(p.F, p.S + 1);
		// 	eval(p.F, p.S - 2);
		// 	eval(p.F, p.S + 2);
		// }

		
		// cerr << "time: " << num << endl;
	}

    return 0;
}