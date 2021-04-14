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

ll a, b, c, d, n;

ll fans = 0;

ll dfs (ll x, ll cost) {
	// cerr << x << " : " << cost << endl;
	if (cost >= fans)
		return cost;
	if (!x) {
		fans = min (fans, cost);
		return ;
	}
	if (x == 1) {
		fans = min (fans, cost+d);
		return ;
	}
	// if (x == 11)	cerr << "test: " << x/3+1 << " " << cost+(3-x%3)*d+a << endl;
	// if (x == 4)	cerr << "test: " << x/2 << " " << cost+(x%2)*d+a << endl;
	// if (x == 2)	cerr << "test: " << x/2 << " " << cost+(x%2)*d+a << endl;
	dfs (x/2, cost+(x%2)*d+a);
	dfs (x/5, cost+(x%5)*d+c);
	dfs (x/3, cost+(x%3)*d+b);
	
	if (x%5)	dfs (x/5+1, cost+(5-x%5)*d+c);
	if (x%3)	dfs (x/3+1, cost+(3-x%3)*d+b);
	if (x%2)	dfs (x/2+1, cost+(2-x%2)*d+a);

	
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		fans = 1e18;
		cin >> n >> a >> b >> c >> d;
		dfs (n, 0);
		cout << fans << endl;
	}

	
	return 0;
}