#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
pair <int, int> tic[100010];
bool used[100010];
int st = 1, ed = 0;

ll ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			tic[++ ed] = make_pair(b, c);
			ans += b;
		}
		else {
			while (st <= ed && tic[st].S + 45 < c)
				st ++;
			int id = -1;
			for (int j = st; j <= ed; j ++)
				if (tic[j].F >= b && !used[j]) {
					id = j;
					break;
				}
			if (~id)
				used[id] = 1;
			else
				ans += b;
		}
		// cerr << ans << endl;
	}
	cout << ans << endl;

	return 0;
}