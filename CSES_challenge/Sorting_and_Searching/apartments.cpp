#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, k;
int a[1000010], b[1000010];

int fans = 0;

bool ok (int x, int y) {return abs(x - y) <= k;}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++)	cin >> a[i];
	for (int j = 1; j <= m; j ++)	cin >> b[j];
	sort (a + 1, a + n + 1);
	sort (b + 1, b + m + 1);
	int pter = 1;
	for (int i = 1; i <= n; i ++) {
		while (pter + 1 <= m && b[pter] < a[i] && !ok(b[pter], a[i]))
			pter ++;
		if (ok(b[pter],a[i]))
			pter ++, fans ++;
	}
	cout << fans << endl;

	return 0;
}
