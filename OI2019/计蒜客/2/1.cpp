#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll hp, atk, n, h, a, t;

ll sg, ti;

ll harm;


int main() {
	// ios::sync_with_stdio(false);
	int T;
	cin  >> T;
	for (int i = 1; i <= T; i ++) {
		cin >> hp >> atk >> n >> h >> a >> t;
		sg = (h % atk ? h / atk + 1 : h / atk);
		ti = min(n, t / sg);
		harm = (n + n - ti + 1) * ti / 2 * sg + t % sg * (n - ti);
		harm *= a;
		cerr << "test : " << harm << endl;
		if (harm >= hp)	cout << "Yes" << '\n';
		else			cout << "No" << '\n';
	}
	return 0;
}