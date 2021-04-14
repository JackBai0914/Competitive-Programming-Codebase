#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int x[1010], y[1010];
int a[1010], b[1010];

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)	cin >> x[i] >> y[i];
	for (int i = 1; i <= n; i ++)	cin >> a[i] >> b[i];
	sort(x + 1, x + n + 1);
	sort(y + 1, y + n + 1);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	cout << x[1] + a[n] << " " << y[1] + b[n] << endl;
	return 0;
}
