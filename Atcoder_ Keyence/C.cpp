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

int n, k, s;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k >> s;
	for (int i = 1; i <= k; i ++)
		cout << s << " ";
	for (int i = k + 1; i <= n; i ++) {
		if (s != 1000000000)	cout << 1000000000 << " ";
		else					cout << 999999999 << " ";
	}
	cout << endl;
	return 0;
}