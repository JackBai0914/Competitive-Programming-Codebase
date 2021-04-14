#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

int a = 0, b = 0;

int ask (int c, int d) {
	cout << "? " << c << " " << d << endl;
	int ans;
	cin >> ans;
	return (ans >= 0 ? 1 : -1);
}

void dfs(int lyer, int big) {
	if (lyer == -1)
		return ;
	int x = 0, y = 0, z = 0, v = (1 << lyer); //1->'>', -1->'<'

	if (big != 0)	x = big;
	else			x = ask(a, b);
	y = ask(a + v, b + v);

	if (x != y) {
		if (x == 1)	{a += v; dfs(lyer - 1, 0);}
		else		{b += v; dfs(lyer - 1, 0);}
	}
	else {
		z = ask(a, b + v);
		if (z == 1)	a += v, b += v;
		dfs(lyer - 1, x);
	}
}

int main() {
	dfs(29, 0);
	cout << "! " << a << " " << b << endl;
	return 0;
}