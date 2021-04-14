#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;

int rt[1000010];
int get_r (int x) {return (x == rt[x] ? x : rt[x] = get_r(rt[x]));}

int n, m;
int d[1000010], st[2000020], ed[2000020];
int col[1000010];
int val[2000020];

int point[1000010], te = 1;
struct e {int to, next, val;} edge[10000010];

void add (int x, int y, int z) {
	te ++;
	edge[te].to = y;
	edge[te].next = point[x];
	edge[te].val = z;
	point[x] = te;
}



int solved[1000010];

void e_search (int x) {
	// cerr << "e : " << x << " " << col[x] << endl;
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (d[to] != d[x])
			continue ;
		if (col[to])
			continue ;
		if (col[x] == 1)	col[to] = 2;
		if (col[x] == 2)	col[to] = 1;
		val[e / 2] = d[x];
		// cerr << "e3: " << e / 2 << " " << d[x] << endl;
		e_search(to);
	}
}

void l_search (int x) {
	// cerr << "l : " << x << endl;
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (col[to]) {
			continue ;
		}
		if (d[to] <= d[x])
			continue ;
		//d[to] > d[x] && col[to] == 0;
		col[to] = col[x];
		val[e / 2] = d[to] - d[x];
		// cerr << "eval: " << e / 2 << " " << d[to] - d[x] << endl;
		l_search(to);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> d[i];
	for (int i = 1; i <= m; i ++) {
		cin >> st[i] >> ed[i];
		add (st[i], ed[i], 0);
		add (ed[i], st[i], 0);
	}
	for (int i = 1; i <= n; i ++) {
		if (solved[i])
			continue ;
		int mn = 2e9;
		for (int e = point[i]; e; e = edge[e].next) {
			int to = edge[e].to;
			mn = min (d[to], mn);
		}
		if (mn > d[i]) {
			//surrounded by >
			cout << -1 << endl;
			exit(0);
		}
		if (mn == d[i]) {
			// cerr << "find: " << i << " " << d[i] << endl;
			if (!col[i]) {
				col[i] = 1;
				e_search(i);
			}
			l_search(i);
		}
	}

	for (int i = 1; i <= n; i ++) {
		if (col[i] == 1)		cout << 'B';
		else if (col[i] == 2)	cout << 'W';
		else					cout << ".";
	}
	cout << endl;
	for (int i = 1; i <= m; i ++) {
		if (!val[i])
			val[i] = 1000000000;
		cout << val[i] << '\n';
	}
	return 0;
}