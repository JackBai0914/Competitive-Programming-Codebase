#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
typedef long long ll;
ll weight = 1;

int main() {
	ios::sync_with_stdio(false);
	long long a, b, c = 0;
	cin >> a >> b;
	while (weight <= a)
		weight *= 10;
	for (int i = 100; i < 1000; i ++) {
		ll d = weight * i + a;
		if (d % b == 0)
			c ++;
	}
	cout << c << endl;
	return 0;
}