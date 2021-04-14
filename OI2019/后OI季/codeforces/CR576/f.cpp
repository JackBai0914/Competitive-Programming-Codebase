#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <vector>
#include <set>
#define F first
#define S second
#define MP make_pair
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;

int gcd (int a, int b) {if (!a||!b)return a+b; return gcd (b, a % b);}

int n;
pair <int, int> a[1000010];
int bel[1000010];

bool fail() {
	int g = 0;
	for (int i = 1; i <= n; i ++)
		g = gcd (g, a[i].F);
	return (g != 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int v, i = 1; i <= n; i ++)
		cin >> v, a[i] = MP(v, i);
	if (fail()) {
		cout << "NO" << endl;
		return 0;
	}

	int CNT = 0;
	while (true) {
		if (((++CNT)&127)==0 && TIME > 0.45){
			cout << "NO" << endl;
			// cerr << "loop TIME: " << CNT << endl;
			return 0;
		}
		random_shuffle(a + 1, a + n + 1);
		int g1 = 0, g2 = 0;
		for (int i = 1; i <= n; i ++) {
			int pre = gcd (g1, a[i].F);
			if (pre != g1)
				g1 = pre, bel[a[i].S] = 1;
			else
				g2 = gcd (g2, a[i].F), bel[a[i].S] = 2;
		}
		if (g1 == 1 && g2 == 1) {
			cout << "YES" << endl;
			for (int i = 1; i <= n; i ++)
				cout << bel[i] << ' ';
			cout << endl;
			return 0;
		}
	}
	return 0;
}