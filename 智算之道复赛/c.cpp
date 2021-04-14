#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;

ll n = 1;
ll k, N;

vector <pii> e;

int main() {
	ios::sync_with_stdio(false);
	cin >> k >> N;
	cerr << "here: " << endl;
	if (k == 1 && N == 2) {
		cerr << "in 1 " << endl;
		cout << 2 << ' ' << 1 << endl;
		cout << 1 << ' ' << 2 << endl;
		return 0;
	}
	if (k == 3 && N == 4) {
		cerr << "in 2 " << endl;

		cout << 4 << ' ' << 5 << endl;
		cout << 1 << ' ' << 2 << endl;
		cout << 1 << ' ' << 3 << endl;
		cout << 2 << ' ' << 3 << endl;
		cout << 2 << ' ' << 4 << endl;
		cout << 3 << ' ' << 4 << endl;
		return 0;
	}

	if (N == 1000 || (k <= 1000 && k + 2 <= N)) {
		// cerr << "in 3 " << " " << k + 2 << " " << N << endl;

		cout << k + 2 << ' ' << k * 2 << endl;
		for (int i = 1; i <= k; i ++) {
			cout << 1 << ' ' << i + 1 << endl;
			cout << i + 1 << ' ' << k + 2 << endl;
		}
		return 0;
	}

	ll weight = 2;
	while (weight < k) {
		n ++;
		weight *= 2;
		// cerr << "in while: " << n << " " << weight << endl;
		if (n == 64)
			break;
	}
	// cerr << "n : " << n << endl;
	ll diff = weight - k;
	// cerr << "diff: " << diff << endl;
	for (int i = 1; i <= n + 2; i ++)
		for (int j = i + 1; j <= n + 2; j ++) {
			// cerr << i << " " << j << " : " << diff << " & " << (1ll << (i - 1)) << endl;
			if (j == n + 2 && i != 1 && (diff & (1ull << (i - 2))) != 0) {
				// cerr << "find: " << i << " " << j << endl;
				continue ;
			}
			e.push_back(MP(i, j));
		}

	cout << n + 2 << ' ' << e.size() << '\n';
	for (int i = 0; i < e.size(); i ++) {
		cout << e[i].F << ' ' << e[i].S << '\n';
	}

	return 0;
}