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
#include <random>
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
int n, q, k, s;
int a[200020], pre[200020], suf[200020];

void modify (int x) {
	if (x - 1 == 0)	pre[x - 1] = a[x];
	else			pre[x - 1] = min (pre[x - 2], a[x]);
	if (x == n - 1)	suf[x] = a[x - 1];
	else			suf[x] = min (suf[x + 1], a[x - 1]);
}

int query_mex(const int *a, int l, int r) {
	// cerr << "q " << l << " " << r << " : " << min ((l == 0 ? n: pre[l - 1]), (r == n - 1 ? n: suf[r + 1])) << endl;
	return min ((l == 0 ? n: pre[l - 1]), (r == n - 1 ? n: suf[r + 1]));
}

int simulate(int n, int *a, int q, int k, int s) {
	std::mt19937 gen;
	gen.seed(s);
	int last = 0;
	while (q--) {
		int op = gen() % k;
		int i = (gen() + last) % n;
		// cerr << "op: " << op << " " << i << endl;
		if (!op && i) {
			// cerr << "mod : " << i << " " << i - 1 << endl;
			modify (i);
			std::swap(a[i - 1], a[i]);
			// cerr << "mod res: " << endl;
			// for (int i = 0; i < n; i ++)	cerr << pre[i] << " "; cerr << endl;
			// for (int i = 0; i < n; i ++)	cerr << suf[i] << " "; cerr << endl;
			// cerr << endl;

		} else {
			int j = gen() % n;
			last ^= query_mex(a, std::min(i, j), std::max(i, j));
		}
	}
	return last;
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	cin >> n >> q >> k >> s;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	pre[0] = a[0], suf[n - 1] = a[n - 1];
	for (int i = 1; i < n; i ++)
		pre[i] = min (a[i], pre[i - 1]);
	for (int i = n - 2; i >= 0; i --)
		suf[i] = min (a[i], suf[i + 1]);

	// for (int i = 0; i < n; i ++)	cerr << pre[i] << " "; cerr << endl;
	// for (int i = 0; i < n; i ++)	cerr << suf[i] << " "; cerr << endl;

	cout << simulate (n, a, q, k, s) << endl;

	return 0;
}
