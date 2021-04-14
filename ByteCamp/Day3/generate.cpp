#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef unsigned long long ll;
typedef pair <ll, ll> pll;

int n, q;
ll a[100010];


int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	freopen("input.in", "w", stdout);
	const int n = 100000, q = 100000;
	cout << n << endl;
	for (int i = 0; i < n; i ++) {
		cout << rand() % 100000 + 1 << " ";
	}
	cout << endl;
	cout << q << endl;
	for (int i = 1; i <= q; i ++) {
		int tp = rand() % 2;
		if (tp == 0) {
			int a = rand() % n + 1;
			int b = rand() % 100000 + 1;
			cout << 1 << " " << a << " " << b << endl;
		}
		else {
			int a = rand() % n + 1;
			int b = rand() % n + 1;
			if (a > b)	swap (a, b);
			cout << 2 << " " << a << " " << b << endl;
		}
	}
	cerr << "done " << endl;
	return 0;
}