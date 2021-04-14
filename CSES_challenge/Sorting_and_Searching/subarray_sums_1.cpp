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

ll n, a[1000010], s[1000010], x;

map <ll, int> mp;

ll fans = 0;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> x;
	int pter = 1;
	ll sum = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		sum += a[i];
		while (sum > x)
			sum -= a[pter ++];
		// cerr << i << " : " << pter << " " << sum << endl;
		if (sum == x)
			fans ++;
	}
	cout << fans << endl;
	return 0;
}
