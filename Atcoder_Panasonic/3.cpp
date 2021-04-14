#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;

ll sqr (ll x) {return x * x;}

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	if (c - a - b <= 0)
		cout << "No" << endl;
	else if (4 * a * b < sqr (c - a - b))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}