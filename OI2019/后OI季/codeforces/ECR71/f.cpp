#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#define MP make_pair
#define F first
#define S second
using namespace std;
typedef pair <int, int> pii;
const int s = 700;
const int n = 500000;
int q;
int rec[1000010][3];
int pans[s + 10][s + 10];
int a[1000010];


int main() {
	cin >> q;
	for (int i = 1; i <= q; i ++) {
		int t, x, y; 
		cin >> t >> x >> y;
		if (t == 1) {
			for (int j = 1; j <= s; j ++)
				pans[j][x % j] += y;
			a[x] += y;
		}
		else {
			if (x <= s) {
				cout << pans[x][y] << endl;
			}
			else {
				int pans = 0;
				for (int j = 0; j * x + y <= n; j ++)
					pans += a[j * x + y];
				cout << pans << endl;
			}
		}
	}

	return 0;
}