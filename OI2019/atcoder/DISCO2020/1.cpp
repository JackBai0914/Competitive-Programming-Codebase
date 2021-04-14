#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define MP make_pair
#define F first
#define S second
using namespace std;

int ans = 0;

int main () {
	int a, b, c;
	cin >> a >> b;
	if (a == 3)	ans += 100000;
	if (a == 2)	ans += 200000;
	if (a == 1)	ans += 300000;

	if (b == 3)	ans += 100000;
	if (b == 2)	ans += 200000;
	if (b == 1)	ans += 300000;

	if (a == 1 && b == 1)	ans += 400000;
	cout << ans << endl;
	return 0;
}