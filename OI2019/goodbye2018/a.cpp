#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int a, b, c;

int main() {
	ios::sync_with_stdio(false);
	cin >> a >> b >> c;
	a -= 0;
	b -= 1;
	c -= 2;
	cout << min(min(a, b), c) * 3 + 3 << endl;

	return 0;
}
