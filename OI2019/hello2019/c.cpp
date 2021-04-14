#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int n;
string s[100010];
int v[100010];

int flag1[500020], flag2[500020];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> s[i];
		int mn = 0;
		for (int j = 0; j < s[i].size(); j ++) {
			v[i] += (s[i][j] == '(' ? 1 : -1);
			mn = min(mn, v[i]);
		}
		if ((v[i] <= 0 && mn < v[i]) || (v[i] >= 0 && mn < 0))
			continue ;
		if (v[i] >= 0)	flag1[v[i]] ++;
		else			flag2[-v[i]] ++;
	}
	int ans = flag1[0] / 2;
	for (int i = 1; i <= 500000; i ++)
		ans += min(flag1[i], flag2[i]);
	cout <<ans << endl;
	return 0;
}
