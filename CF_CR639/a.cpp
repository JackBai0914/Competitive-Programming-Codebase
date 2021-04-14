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

int n;
int a[1000010];

int flag[1000010];

int Mod (ll x, ll y) {return ((x % y) + y) % y;}

int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T;
	cin >> T;
	while (T --) {
		int ans = true;
		cin >> n;
		for (int i = 0; i < n; i ++)
			cin >> a[i];
		for (int i = 0; i < n; i ++)
			flag[i] = 0;
		for (int i = 1; i <= n; i ++) {
			int v = i + a[i % n];
			int w = Mod(v, n);
			// cerr << i << " : " << v << " " << w << endl;
			flag[w] ++;
			if (flag[w] != 1) {
				ans = false;
				break;
			}
		}
		cout << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}