#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
#define F first
#define S secpond
using namespace std;


int Rand() {return (long double)rand() / RAND_MAX * 1e9;}

int main() {
	ios::sync_with_stdio(false);
	srand(time(0));
	int n = 100000;
	int q = 100000;
	cout << n << endl;
	for (int i = 1; i <= n; i ++)
		cout << Rand() << " " << Rand() << '\n';
	cout << q << endl;
	for (int i = 1; i <= q; i ++) {
		int l = rand() % n + 1;
		int r = rand() % n + 1;
		if (l > r)	swap(l, r);
		cout << l << " " << r << '\n';
	}
	return 0;
}