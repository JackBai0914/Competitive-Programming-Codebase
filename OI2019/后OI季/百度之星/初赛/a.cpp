#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
int mxf, mxg;
int f[1000010], g[1000010];

int gcd (int a, int b) {
	if (b == 0)
		return a;
	return gcd (b, a % b);
}

int main() {
	srand(time(0));
	int T;
	cin >> T;
	while(T --) {
		cin >> n;
		for (int i = 0; i < n; i ++) {
			cin >> f[i];
			if (f[i])
				mxf = i;
		}	
		for (int i = 0; i < n; i ++) {
			cin >> g[i];
			if (g[i])
				mxg = i;
		}
		if (mxf == mxg) {
			int G = gcd(f[mxf], g[mxg]);
			cout << f[mxf] / G << "/" << g[mxg] / G << endl;
		}
		if (mxf > mxg) {
			cout << "1/0" << endl;
		}
		if (mxf < mxg) {
			cout << "0/1" << endl;
		}
	}
	return 0;
}