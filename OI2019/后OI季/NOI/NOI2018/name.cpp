#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;

string s, t;

namespace SA {
	int c[1000010], sa[1000010], rk[1000010], bar[1000010], yy[1000010];
	int h[1000010], height[1000010];
	void sorte (int *x, int *y, int n, int m) {
		for (int i = 0; i < m; i ++)	bar[i] = 0;
		for (int i = 0; i < n; i ++)	bar[x[i]] ++;
		for (int i = 1; i < m; i ++)	bar[i] += bar[i - 1];
		for (int i = n - 1; i >= 0; i --)	sa[-- bar[x[y[i]]]] = y[i];
	}

	void calc_h (int n) {
		int ch = 0;
		for (int i = 0; i < n - 1; i ++) {
			if (ch)										ch --;
			while (c[i + ch] == c[sa[rk[i] - 1] + ch])	ch ++;
			h[i] = height[rk[i]] = ch;
		}
	}

	void work(string s, int n, int m) {
		int *x = rk, *y = yy;
		for (int i = 0; i < s.size(); i ++)	c[i] = s[i] - 'a' + 1;
		for (int i = 0; i < n; i ++)	x[i] = c[i], y[i] = i;
		sorte(x, y, n, m);
		for (int j = 1, p = 1; p < n; j <<= 1) {
			p = 0;
			for (int i = n - j; i < n; i ++)
				y[p ++] = i;
			for (int i = 0; i < n; i ++)
				if (sa[i] >= j)
					y[p ++] = sa[i] - j;
			sorte(x, y, n, m);
			swap (x, y);
			p = 0;
			x[sa[0]] = p ++;
			for (int i = 1; i < n; i ++)
				if (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + j] == y[sa[i - 1] + j])
					x[sa[i]] = p - 1;
				else
					x[sa[i]] = p ++;
		}
		for (int i = 0; i < n; i ++)	rk[i] = x[i];
		calc_h(n);
	}

	long long diff(int n) {
		long long ans = 0;
		// for (int i = 0; i < n; i ++)
			// cout << i << " : " << sa[i] << " " << rk[i] << " " << h[i] << " " << height[i] << endl;
		for (int i = 0; i < n - 1; i ++) {
			ans += n - 1 - i - h[i];
		}
		return ans;
	}
}


int main() {
	int c;
	cin >> c;
	string s;
	cin >> s;
	SA::work(s, s.size() + 1, 1e6);
	cout << SA::diff(s.size() + 1) << endl;
	return 0;
}