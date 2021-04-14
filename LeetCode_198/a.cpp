#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;

int n, m;
string s;



int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int ans = n, wait = n;

	while (wait >= m) {
		int dt = wait / m;
		ans += dt;
		wait %= m;
		wait += dt;
	}
	cout << ans << endl;

	return 0;
}