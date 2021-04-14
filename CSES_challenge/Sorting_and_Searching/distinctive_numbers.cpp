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
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

map <int, bool> m;
int n, v;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	int fans = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> v;
		if (!m[v]) {
			m[v] = true;
			fans ++;
		}
	}
	cout << fans << endl;

	return 0;
}
