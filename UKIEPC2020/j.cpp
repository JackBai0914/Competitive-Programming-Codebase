#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int MOD = 1000000007; 
const ll INF = 1e18;
const ld eps = 1e-8;

ll a, b, c;

int main() {
	ios::sync_with_stdio(false);
	cin >> a >> b >> c;
	if (a != 4) {
		cout << "impossible" << endl;
		return 0;
	}
		if (c == 0) {
			cout << b / 2 + 2 << " " << 2 << endl;
			return 0;
		}
		if (b % 2) {
			cout << "impossible" << endl;
			return 0;
		}

	int sc = sqrt(c) + 1;

	for (ll h = 3; h - 2 <= sc; h ++) {
		if (c % (h - 2) == 0 && h * 2 - 4 + c / (h - 2) * 2 == b) {
				cout << c / (h - 2) + 2 << " " << h << endl;
				return 0;
		}
	}
	cout << "impossible" << endl;

    return 0;
}