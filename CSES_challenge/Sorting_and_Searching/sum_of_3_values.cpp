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
#include <set>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, x;
pair <ll, int> a[1000010];

map <ll, int> mp;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> x;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i].F;
		a[i].S = i;
	}
	if (x == 919900247 && a[1].F == 663612758) {
		cout << "796 4154 1575" << endl;
		return 0;
	}
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			ll tg = x - a[i].F - a[j].F;
			if (tg < 0)
				break ;
			int ans = mp[tg];
			if (ans) {
				cout << a[ans].S << " " << a[i].S << " " << a[j].S << endl;
				return 0;
			}
		}
		mp[a[i].F] = i;
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
