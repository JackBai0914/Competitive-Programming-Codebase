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

int n;
string s[110];
int t[110];
string tg;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> s[i] >> t[i];
	cin >> tg;
	bool ok = 0;
	int sum = 0;
	for (int i = 1; i <= n; i ++) {
		sum += ok * t[i];
		if (s[i] == tg)
			ok = 1;
	}
	cout << sum << endl;
	return 0;
}