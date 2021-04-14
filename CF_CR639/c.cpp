#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

int n, m;
int point[200020], dg[200020], te = 0;
struct e {int to, next;} edge[2000020];
void add (int x, int y) {dg[y] ++; edge[++ te].to = y; edge[te].next = point[x]; point[x] = te;}
bool stat[200020];

int ord[200020], cir = false;
queue <int> q;
void calc () {
	for (int i = 1; i <= n; i ++)
		if (dg[i] == 0)
			q.push (i);
	int ost = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		ord[++ ost] = x;
		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			if ((-- dg[to]) == 0)
				q.push(to);
		}
	}
	if (ost != n)
		cir = true;
}

int poi[2000020];
bool ordered () {
	for (int i = 1; i <= n;i ++)
		poi[i] = (stat[i] == 0);
	for (int i = n; i >= 1; i --) {
		int v = ord[i];
		for (int e = point[v]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (poi[v] && poi[to])
				return false;
		}
		for (int e = point[v]; e; e = edge[e].next) {
			int to = edge[e].to;
			poi[v] |= poi[to];
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	cin >> n >> m;
	for (int a, b, i = 1; i <= m; i ++) {
		cin >> a >> b;
		add (b, a);
	}

	for (int i = 1; i <= n; i ++)
		stat[i] = 1;

	calc();
	if (cir == true) {
		cout << -1 << endl;
		return 0;
	}

	// cerr << "ord: ";
	// for (int i = 1; i <= n; i ++)
	// 	cerr << ord[i] << " ";
	// cerr << endl;

	int st = 1, ed = n + 1;
	while (st != ed) {
		int mid = (st + ed + 1) >> 1;
		for (int i = 1; i <= mid - 1; i ++)	stat[i] = 0;
		for (int i = mid; i <= n; i ++)		stat[i] = 1;
		// cerr << ": " << st << " " << mid << " " << ed << endl;
		if (ordered())	st = mid;
		else			ed = mid - 1;
	}
	cout << st - 1 << endl;
	for (int i = 1; i <= n; i ++)
		cout << (i < st ? 'A' : 'E');
	cout << endl;
	return 0;
}