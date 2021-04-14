#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;

int n, m;
int a;

inline char gc() {
	static char buf[524288], *p1 = buf, *p2 = buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,524288,stdin), p1==p2)? EOF : *p1 ++;
}
void read (int &v) {
	char c = gc();
	v = 0;
	while (c < '0' || '9' < c)	c = gc();
	while ('0' <= c && c <= '9') {
		v = v * 10 + c - '0';
		c = gc();
	}
	return ;
}

int main () {
	long long s = 0;
	read(n);
	read(m);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			read (a);
			s += a;
		}
	cout << s << endl;
	cerr << "TIME: " << TIME << endl;
	return 0;
}