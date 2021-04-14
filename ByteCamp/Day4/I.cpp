#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

ll x;
int n;
int a[100010];

vector <int> fac;
vector <int> num;
ll fans = 0;

const int C= 10000000;
int bar[10000010];
vector <int> bg;
ll process (int v) {
	ll pans = 0;
	bg.resize(0);
	for (int i = 1; i <= n; i ++) {
		if (a[i] % v <= C) {
			pans += bar[a[i] % v];
			bar[a[i] % v] ++;
		}
		else
			bg.push_back(a[i] % v);
	}

	sort (bg.begin(), bg.end());
	for (int i = 0; i < bg.size(); i ++) {
		ll num = 1;
		while (i + 1 < bg.size() && bg[i + 1] == bg[i])
			num ++, i ++;
		pans += (ll)num * (num - 1) / 2;
	}

	for (int i = 1; i <= n; i ++) {
		if (a[i] % v <= C) {
			bar[a[i] % v] --;
		}
	}
	return pans;
}

void dfs (int x, int mu, ll v) {
	if (x == fac.size()) {
		fans += mu * process (v); 
		return ;
	}
	dfs (x + 1, mu, v);
	if (num[x] >= 1)
		dfs (x + 1, mu * (-1), v * fac[x]);
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	while (true) {
		fans = 0;
		cin >> n >> x;
		if (!n && !x)
			return 0;
		for (int i = 1; i <= n; i ++)
			cin >> a[i];
		
		fac.resize(0);
		num.resize(0);
		int nn = x;
		for (int i = 2; i * i <= nn; i ++)
			if (nn % i == 0) {
				fac.push_back (i);
				num.push_back (0);
				while (nn % i == 0) {
					num[num.size() - 1] ++;
					nn /= i;
				}
			}
		if (nn != 1) {
			fac.push_back (nn);
			num.push_back (1);
		}
		dfs (0, 1, 1);
		cout << fans << endl;
	}
	return 0;
}