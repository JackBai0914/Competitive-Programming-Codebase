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

int n;
int a[1000010];

int c = 0;
int mn[1000010];

int find (int l, int r, int v) {
	if (l == r)
		return l;
	int mid = (l + r + 1) >> 1;
	if (v < mn[mid])	return find (l, mid - 1, v);
	else				return find (mid, r, v);
}

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] >= mn[c])
			mn[++ c] = a[i];
		else {
			int la = find(0, c, a[i]);
			mn[la + 1] = min (mn[la + 1], a[i]);
		}
	}
	cout << c << endl;

	return 0;
}
