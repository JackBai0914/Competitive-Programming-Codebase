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

int n, t[10000010];

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> t[i];
	sort (t + 1, t + n + 1);
	ll s = 0;
	for (int i = 1; i < n; i ++)
		s += t[i];
	if (s >= t[n]) {
		cout << s + t[n] << endl;
	}
	else {
		cout << t[n] * 2 << endl;
	}

	return 0;
}
