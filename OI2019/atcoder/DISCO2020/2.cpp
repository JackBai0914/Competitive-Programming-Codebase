#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define MP make_pair
#define F first
#define S second
using namespace std;
typedef long long ll;
ll n;
ll a[1000010], s[1000010];

ll fans = 2e10;

int main () {
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i], s[i] = s[i - 1] + a[i];
	for (int i = 1; i < n; i ++) {
		ll l = s[i], r = s[n] - l;
		fans = min (fans, abs(l - r));
	}
	cout << fans << endl;
	return 0;
}