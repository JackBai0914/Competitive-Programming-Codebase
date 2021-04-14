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
int mn[100010];

int flag1[200020], flag2[200020];

map <int, int> M;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j ++) {
			v[i] += (s[i][j] == '(' ? 1 : -1);
			mn[i] = min(mn[i], v[i]);
		}
		if (mn[i] == 0)
			M[v[i]] ++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> s[i];
		if (v[i] < 0 && mn[i] == v[i] && M[-v[i]] > 0)
	}
	return 0;
}
