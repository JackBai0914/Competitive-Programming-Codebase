#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;

int n;
unsigned int a, b;

int ans[80000001];

int p[5000000], pst = 0;

void init() {
	ans[1] = 1;
	for (int i = 2; i <= n; i ++) {
		if (!ans[i])
			p[++ pst] = i;
		for (int j = 1; j <= pst && i * p[j] <= n; j ++) {
			ans[i * p[j]] = true;
			if (i % p[j] == 0)
				break;
		}
		ans[i] = 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> a >> b;
	init();
	// cout << pst << endl;
	// for (int i = 1; i <= pst; i ++)
	// 	cout << p[i] << " ";
	// cout << endl;
	for (int i = 1; i <= pst; i ++) {
		ll c = p[i];
		for (; c <= n; c *= p[i])
			ans[c] *= p[i];
	}
	for (int i = 1; i <= n; i ++)
		if (ans[i] != 1)
			a = a * ans[i] + b;
	cout << a << endl;
	return 0;
}