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
vector <int> v;

int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int t;
	cin >> t;
	while (t --) {
		cin >> n;
		int f = 2, st = 0;
		while (true) {
			int r = rand() % n + 1, st = r;
			v.resize(0);
			v.push_back(r);
			r = r * st % (n + 1);
			while (r != st) {
				v.push_back(r);
				r = r * st % (n + 1);
			}
			if (v.size() == n) {
				for (int i = 0; i < n; i ++)
					cout << i + 1 << ' ' << v[i] << endl;
				break;
			}
		}

	}
	return 0;
}