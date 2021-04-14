#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
int n, m, x, y;
int main() {
	srand((unsigned long long)new char);
	freopen("mooriokart.in", "w", stdout);
	n = 12 + 12;
	m = 18;
	x = rand() % 1000;
	y = rand() % 2500;
	cout << n << " " << m << " " << x << " " << y << endl;
	for (int i = 1; i <= 6; i ++)
		cout << i * 2 << " " << i * 2 - 1 << " " << rand() % 1000 << endl;
	for (int i = 13; i <= 24; i ++)
		cout << i << " " << rand() % 12 + 1 << " " << rand() % 1000 << endl;

	return 0;
}


