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

ll n, a[1000010], s[1000010];

map <ll, int> mp;

ll fans = 0;

ll clear (ll x) {return ((x % n) + n) % n;}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	int pter = 1;
	ll sum = 0;
	mp[0] = 1;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		fans += mp[clear(s[i])];
		mp[clear(s[i])] ++;
	}
	cout << fans << endl;
	return 0;
}
