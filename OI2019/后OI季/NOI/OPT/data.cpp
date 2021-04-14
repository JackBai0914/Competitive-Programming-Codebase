#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;

int n, m;
long long sum = 0;

int main () {

	ios::sync_with_stdio(false);
	
	int n = 3000;
	int m = 3000;

	cout << n << " " << m << endl;
	for (int i =1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			int v = rand();
			cout << v << '\n';
		}

	return 0;
}