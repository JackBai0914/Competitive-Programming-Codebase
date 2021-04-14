#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
ll n;
int x, s[1000010];
int ed[1000010], st[1000010];
int sum[1000010];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> x;
		bool down = true;
		for (int j = 1; j <= x; j ++) {
			cin >> s[j];
			if (j != 1 && s[j] > s[j - 1])
				down = false;
		}
		if (down) {
			ed[s[x]] ++;
			st[s[1]] ++;
		}
	}
	ll ans = 0;
	for (int i = 0; i <= 1000000; i ++)
		sum[i] = sum[i - 1] + st[i];
	for (int i = 0; i <= 1000000; i ++)
		ans += ed[i] * sum[i];
	cout << n * n - ans << endl;
	return 0;
}