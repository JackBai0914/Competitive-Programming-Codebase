#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int n, m, q;
string s[1010], t[1010];


int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i ++)	cin >> s[i];
	for (int i = 0; i < m; i ++)	cin >> t[i];
	cin >> q;
	for (int i = 1; i <= q; i ++) {
		int x;
		string ans = "";
		cin >> x;
		x --;
		ans += s[x % n];
		ans += t[x % m];
		cout << ans << endl;
	}
	return 0;
}