#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1e9 + 7;
int n, q;
pii a[200020], b[200020];
pii s[200020];
int sst = 0;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i].F >> a[i].S;
	cin >> q;
	long long ans;
	for (int l, r, i = 1; i <= q; i ++) {
		cin >> l >> r;
		for (int j = l; j <= r; j ++)
			b[j] = a[j];
		sort(b + l, b + r + 1);
		sst = 0;
		for (int j = l; j <= r; j ++) {
			while (sst != 0 && b[j].S >= s[sst].S)
				sst --;
			s[++ sst] = b[j]; 
		}
		long long ans = 1;
		for (int j = 1; j <= sst; j ++) {
			(ans *= (s[j].F ^ s[j].S)) %= mod;
			// cout << ": " << s[j].F << " " << s[j].S << endl;
		}
		cout << ans << endl;
	}
	return 0;
}