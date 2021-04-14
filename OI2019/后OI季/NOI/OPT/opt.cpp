#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;

int n, m;
long long sum = 0;

char gc() {
	static char BUF[524288], *p1 = BUF, *p2 = BUF;
	return p1==p2 && (p2=(p1=BUF)+fread(BUF,1,524288,stdin), p1==p2) ? EOF : *p1++;
}
void read_int(int &v) {
	v = 0;
	char c = gc();
	while (c < '0' || c > '9')	c = gc();
	while ('0' <= c && c <= '9') {
		v = v * 10 + c - '0';
		c = gc();
	}
}

int main () {

	ios::sync_with_stdio(false);
	
	read_int(n);
	read_int(m);
	for (int i =1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			int v;
			read_int(v);
			sum += v;
		}

	cerr << "time = " << TIME << endl;
	cerr << "ans = " << sum << endl;
	return 0;
}