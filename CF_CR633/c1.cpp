#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
typedef long long ll;

ll n, m;
ll a, b, c;


int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t -- ){
		cin >> n;
		
		m = (n - 1) / 3 + 1;
		ll len = 1, bef = 0;
		while (m > len + bef) {
			bef += len;
			len *= 4;
		}
		ll ord = m - bef - 1;
		a = len + ord;

		int r[4] = {0, 2, 3, 1};
		ll weight = 1, sum = 0;
		while (ord) {
			sum += weight * r[ord % 4];
			ord /= 4;
			weight *= 4;
		}
		b = len * 2 + sum;
		c = a ^ b;
		if (n % 3 == 1)	cout << a << '\n';
		if (n % 3 == 2)	cout << b << '\n';
		if (n % 3 == 0)	cout << c << '\n';
	}

	return 0;
}