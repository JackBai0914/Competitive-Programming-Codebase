#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;

int h, w, n;

int main() {
	ios::sync_with_stdio(false);
	cin >> h >> w >> n;
	int x = max (h, w);
	if (n % x == 0)
		cout << n/x << endl;
	else
		cout << n/x + 1 << endl;
	return 0;
}