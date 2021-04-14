#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
ll p[22];

ll s = 0, ps = 0, fans = 1e12;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> p[i], s += p[i];
	int st = (1 << n);
	for (int msk = 0; msk < st; msk ++) {
		ps = 0;
		int mskk = msk;
		for (int i = 1; i <= n; i ++) {
			ps += p[i] * (mskk % 2 == 0);
			mskk /= 2;
		}
		// cerr << ps << endl;
		fans = min (fans, abs(ps - (s - ps)));
	}
	cout << fans << endl;

	return 0;
}
