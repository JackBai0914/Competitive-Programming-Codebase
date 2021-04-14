#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

int n, a[1000010];

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		cin >> n;
		for (int i = 1; i <= n; i ++)
			cin >> a[i];
		sort (a + 1, a + n + 1);
		int mx = 1;
		for (int i = 1; i <= n; i ++) {
			if (a[i] <= i)
				mx = i + 1;
		}
		cout << mx << endl;
	}


	return 0;
}