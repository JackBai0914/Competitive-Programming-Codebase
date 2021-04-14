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
#include <set>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll a[1000010];
ll fans = 0; 

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		ll d;
		cin >> a[i] >> d;
		fans += d;
	}
	sort (a + 1, a + n + 1);

	ll t = 0;
	for (int i = 1; i <= n; i ++) {
		t += a[i];
		fans -= t;
	}
	cout << fans << endl;
	return 0;
}
