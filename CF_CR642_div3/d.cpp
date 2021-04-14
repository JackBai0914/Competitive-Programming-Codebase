#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
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
typedef pair <int, int> pii;
int n;
int a[200020];


bool Ord (pii x, pii y) {
	return x.F < y.F;
}


vector <pii> q[200020];


int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		cin >> n;
		for (int i = 1; i <= n; i ++) {
			a[i] = 0;
			q[i].resize(0);
		}
		
		int st = 0;
		int pter = 0;
		q[n].push_back (MP(1, n));
		for (int i = n; i >= 1; i --) {
			sort (q[i].begin(), q[i].end(), Ord);
			for (int j = 0; j < q[i].size(); j ++) {
				int l = q[i][j].F;
				int r = q[i][j].S;
				int mid = (l + r) >> 1;
				a[mid] = ++ st;
				if (l <= mid - 1)		q[mid-1-l+1].push_back (MP(l, mid - 1));
				if (mid + 1 <= r) 		q[r-mid-1+1].push_back (MP(mid + 1, r));
			}
		}
		for (int i = 1; i <= n; i ++)
			cout << a[i] << ' ';
		cout << endl;
	}

	return 0;
}