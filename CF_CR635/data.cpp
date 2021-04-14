#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int n = 200000;
const int m = 35;

ll get_s () {
	freopen("seed", "r", stdin);
	ll sd;	cin >> sd;
	fclose (stdin);
	freopen("seed", "w", stdout);
	sd = sd * 100007 % mod;
	cout << sd << endl;
	fclose (stdout);
	cerr << "s: " << sd << " ";
	return sd;
}

int main() {
	ios::sync_with_stdio(false);
	srand(get_s());
	freopen("e.in", "w", stdout);
	cout << n << " " << m << endl;
	int num = 0;
	for (int i = 1; i <= n; i ++) {
		// cout << (rand() % 1000 ? 32247662483 : 0) << ' ';
		cout << rand() % (1ll << 23) << " ";
	}
	cout << endl;
	return 0;
}