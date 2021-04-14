#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

map <int, int> mp;

int main() {
	std::ios::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i ++) {
		int v, tg;
		cin >> v;
		tg = x - v;
		if (mp[tg]) {
			cout << mp[tg] << " " << i << endl;
			return 0;
		}
		mp[v] = i;
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
