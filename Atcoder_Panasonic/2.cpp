#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

ll a, b;


int main() {
	cin >> a >> b;
	if (a == 1) {cout << 1 << endl; return 0;}
	if (b == 1) {cout << 1 << endl; return 0;}
	ll ans = 0;
	ans += ((a + 1) / 2) * ((b + 1) / 2);
	ans += (a / 2) * (b / 2);
	cout << ans << endl;
	return 0;
}