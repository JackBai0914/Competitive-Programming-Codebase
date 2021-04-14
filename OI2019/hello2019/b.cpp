#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int n;
int a[20];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	bool ans = 0;
	for (int i = 0; i < (1 << n); i ++) {
		int ii = i;
		int cnt = 0;
		for (int j = 1; j <= n; j ++, ii /= 2) {
			if (ii & 1)
				cnt += a[j];
			else
				cnt -= a[j];
		}
		if (cnt % 360 == 0)
			ans = 1;
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
