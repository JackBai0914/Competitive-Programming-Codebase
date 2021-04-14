#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#define F first
#define S second
#define MP make_pair
using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		cin >> n >> m;
		if (n == 1) {
			cout << 0 << endl;
		}
		else if (n == 2) {
			cout << m << endl;
		}
		else {
			cout << 2 * m << endl;
		}
	}

	return 0;
}