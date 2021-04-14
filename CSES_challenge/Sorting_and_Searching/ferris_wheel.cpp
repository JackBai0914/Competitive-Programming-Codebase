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
int x;
int a[1000010];
bool flag[1000010];
int fans = 0;

multiset <int> s;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> x;
	for (int i = 1, v; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int pter = n;
	for (int i = 1; i <= n; i ++) {
		if (flag[i])
			continue ;
		while (pter - 1 > i && a[pter] + a[i] > x)
			pter --;
		if (pter > i && a[pter] + a[i] <= x) {
			flag[pter] = 1;
			pter --;
			fans ++;
		}
		else {
			fans ++;
		}

	}
	cout << fans << endl;
	return 0;
}
