#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;

ll xs, s;

int q[1000010];
int qst = 0;


int main() {
	ios::sync_with_stdio(false);
	cin >> xs >> s;
	if (xs > s || (s - xs) % 2) {
		cout << -1 << endl;
		return 0;
	}
	if (xs == s && xs == 0) {
		cout << 0 << endl;
		return 0;
	}
	if (xs == s) {
		cout << 1 << endl << s << endl;
		return 0;
	}

	ll a = xs, b = (s - xs) / 2;



	if ((a|b) == a + b) {
		cout << 2 << endl << a+b << " " << b << endl;
	}
	else {
		cout << 3 << endl << a << " " << b << " " << b << endl;
	}

	return 0;
}