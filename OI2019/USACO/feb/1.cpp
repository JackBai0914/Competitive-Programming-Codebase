#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
long double p[2000020];
long double ans = 0;
long double prob_zero, prob_one, new_zero, new_one;

int main() {
	ios::sync_with_stdio(false);
	freopen("cowdate.in", "r", stdin);
	freopen("cowdate.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> p[i];
		p[i] *= 1e-6;
	}
	prob_zero = 1;
	prob_one = 0;
	for (int pter = 0, i = 1; i <= n; i ++, pter --) {
		prob_zero /= (1.0 - p[i - 1]);
		prob_one = (prob_one - prob_zero * p[i - 1]) / (1.0 - p[i - 1]);
		ans = max(ans, prob_one);
		for (++ pter; pter <= n; pter ++) {
			new_one = prob_zero * p[pter] + prob_one * (1 - p[pter]);
			new_zero = prob_zero * (1 - p[pter]);
			ans = max(ans, new_one);
			if (new_one < prob_one)
				break;
			prob_one = new_one;
			prob_zero = new_zero;
		}
	}
	cout << (int)(ans * 1000000 + 1e-3) << endl;
	return 0;
}


