#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

// int ne[100010], v[100010];
// priority_queue <pii> q;

int n;
int a[2000020];

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		bool ans = true;
		cin >> n;
		for (int i = 1; i <= n; i ++)
			cin >> a[i];
		int tot = n;
		int v;
		for (int i = 1; i <= n && ans; i ++) {
			v = a[i];
			if (v == tot) {
				tot --;
			}
			else {
				int w;
				for (int j = v + 1; j <= tot; j ++) {
					w = a[++ i];
					if (w != j) {
						ans = false;
						break;
					}
				}
				if (ans)
					tot = v - 1;
			}
		}
		cout << (ans ? "Yes" : "No") << endl;
	}


	return 0;
}