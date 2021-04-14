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

int n;
int a[1000010];

pii s[1000010];
int ed = 0;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	s[++ ed] = MP(0, 0);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];

		int tg = (lower_bound(s + 1, s + ed + 1, MP(a[i], 0))) - s;
		cout << s[tg - 1].S << ' ';


		while (ed != 0 && s[ed].F >= a[i])
			ed --;
		s[++ ed] = MP(a[i], i);
	}
	cout << endl;
	return 0;
}
