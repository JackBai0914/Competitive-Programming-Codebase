#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int main() {
	double k = 10000000, r = 1;
	double ini = 1;
	cin >> r;
	for (int i = 1; i <= k; i ++)
		ini *= (1 + r/k);
	cout << ini << endl;
}