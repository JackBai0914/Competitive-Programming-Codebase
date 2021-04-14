#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int a[100010];

int v[100010], num[100010];

int cur = 0;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	num[0] = n;
	for (int i = 1; i <= m; i ++) {
		bool ans = 0;
		cin >> a[i];
		num[v[a[i]]] --;
		if (v[a[i]] == cur && num[v[a[i]]] == 0)
			ans = 1, cur ++;
		v[a[i]] ++;
		num[v[a[i]]] ++;
		cout << ans;
	}
	cout << endl;

	return 0;
}