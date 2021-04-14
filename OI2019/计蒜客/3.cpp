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

int n, k;
int dg[200020];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int a, b, i = 1; i < n; i ++)
		cin >> a >> b, dg[a] ++, dg[b] ++;
	int sum = 0;
	for (int i = 1; i <= n; i ++)
		sum += (dg[i] == 1);
	if (k == 0) {
		cout << sum << endl;
		return 0;
	}
	else {
		if (sum == 2) {
			cout << sum << endl;
			return 0;
		}
		else {
			cout << sum - 1 << endl;
			return 0;
		}
	}
	return 0;
}