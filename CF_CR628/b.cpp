#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;

int n;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt ++) {
		int ans = 0;
		cin >> n;
		map <int, bool> mp;
		for (int i = 1; i <= n; i ++) {
			int a;
			cin >> a;
			if (!mp[a])
				ans ++;
			mp[a] = true;
		}
		cout << ans << endl;
	}
	return 0;
}