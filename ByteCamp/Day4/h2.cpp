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

int n, l;
int a[110];
ll fans = 1e12;
int frec[110];

int prec[110];

bool ok () {
	ll sum = 0;
	for (int i = 1; i <= n; i ++)
		sum += (1ll << (l - prec[i]));
	return (sum <= (1ll << l));
}
void dfs (int x, int all) {
	if (all > (1ll << l))
		return ;
	if (x == n + 1) {
		if (ok ()) {
			ll pans = 0;
			for (int i = 1; i <= n; i ++)
				pans += a[i] * prec[i];
			if (pans < fans) {
				fans = pans;
				// cerr << "pans "  << pans << endl;
 				for (int i = 1; i <= n; i ++)
					frec[i] = prec[i];
			}
		}
		return ;
	}
	for (int i = 1; i <= l; i ++) {
		prec[x] = i;
		dfs (x + 1, all + (1ll << (l - prec[x])));
	}
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	while (cin >> n >> l) {
		// cerr << "proceed " << endl;
		fans = 1e12;
		if (n == 0 && l == 0)
			return 0;
		for (int i = 1; i <= n; i ++)
			cin >> a[i];
		dfs (1, 0);
		cout << fans << endl;
		for (int i = 1; i <= n; i ++)
			cout << frec[i] << " ";
		cout << endl;
	}
	
	return 0;
}