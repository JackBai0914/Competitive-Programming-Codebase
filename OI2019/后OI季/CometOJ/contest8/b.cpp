#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
using namespace std;

int n;
typedef long long ll;
ll a[100010], a2[100010], sum = 0, sum2 = 0;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i], a2[i] = a[i] * a[i], sum += a[i], sum2 += a2[i];
	for (int i = 1; i <= n; i ++) {
		cout << sum2 + a2[i] * n - 2 * a[i] * sum << ' ';
	}
	cout << endl;

	return 0;
}