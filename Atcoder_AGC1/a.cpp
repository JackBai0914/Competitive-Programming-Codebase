#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;

int n;
int a[100010];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	long long ans = 0;
	for (int i = 1; i <= 2 * n; i ++)
		cin >> a[i];
	sort (a + 1, a + 2 * n + 1);
	for (int i = 1; i <= 2 * n; i += 2)
		ans += a[i];
	cout << ans << endl;

	return 0;
}