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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main() {
	std::ios::sync_with_stdio(false);
	ll x = 1, n;
	cin >> n;
	int mod = 1e9 + 7;
	for (int i = 1; i <= n; i ++)
		(x *= 2) %= mod;
	cout << x << endl;
	return 0;
}
