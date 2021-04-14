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


int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ll dx = x2 - x1 + 1, dy = y2 - y1 + 1;
		if (dx < dy)	swap (dx, dy);
		ll p1 = (dy - 2) * (dy - 1);
		ll p2 = (dy - 1) * (dx - dy + 1);
		cout << p1 + p2 + 1 << endl;
	}

	
	return 0;
}