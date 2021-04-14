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
ll a[100010];
map <int, pii> mp;
map <int, bool> mp2;
queue <pair <long long, pii> > q;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> x;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) 
			if (a[i] + a[j] < x && mp2[x - a[i] - a[j]]) {
				pii ans = mp[x - a[i] - a[j]];
				cout << ans.F << " " << ans.S << " " << i << " " << j << endl;
				return 0;
			}
		for (int j = 1; j < i; j ++) 
			if (a[i] + a[j] < x) {
				mp[a[i] + a[j]] = MP(i, j);
				mp2[a[i] + a[j]] = 1;
			}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
