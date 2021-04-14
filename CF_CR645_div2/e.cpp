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
typedef long double ld;
typedef pair <int, int> pii;

ll n, x, y;
ll v[1000010], s[1000010], key;

ll ss[1000010], mn = 1e16;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	x = (n+1)/2, y=n-x;
	for (int i = 1; i <= x; i ++)
		cin >> v[i], s[i] = s[i - 1] + v[i];
	cin >> key;

	if (key < 0) {
		for (int i = 1; i <= x; i ++) {
			mn = min (mn, (s[x] - s[i - 1] - 1) / (-key) + x - (i - 1));
			// cerr << i << " : " << (s[x] - s[i - 1] - 1) / (-key) << " + " <<  x - (i - 1) << endl;
			// cerr << "cmp: " << y + x - (i - 1) << " " << mn << endl;
			if (y + x - (i - 1) <= mn) {
				cout << y + x - (i - 1) << endl;
				return 0;
			}
		}
		cout << -1 << endl;
		return 0;
	}

	else {
		if (s[x] + key * y > 0) {
			cout << n << endl;
			return 0;
		}
		else {
			cout << -1 << endl;
			return 0;
		}
	}
	return 0;
}