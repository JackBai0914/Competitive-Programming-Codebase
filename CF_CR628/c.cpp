#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
int dg[1000010];
pair <int, int> e[1000010];
int ans[1000010];

int star = -1;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; i ++) {
		cin >> e[i].F >> e[i].S;
		if (e[i].F > e[i].S)
			swap (e[i].F, e[i].S);
		dg[e[i].F] ++;
		dg[e[i].S] ++;
	}

	for (int i = 1; i <= n; i ++)
		if (dg[i] >= 3)
			star = i;

	int st = 0;
	for (int i = 1; i < n; i ++)
		if (e[i].F == star || e[i].S == star)
			ans[i] = st ++;
	for (int i = 1; i < n; i ++)
		if (e[i].F != star && e[i].S != star)
			ans[i] = st ++;

	for (int i = 1; i < n; i ++)
		cout << ans[i] << endl;

	return 0;
}