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

int n, m;
multiset <int> s;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	s.insert(-1);
	for (int i = 1; i <= n; i ++) {
		int v;
		cin >> v;
		s.insert(v);
	}
	for (int i = 1; i <= m; i ++) {
		int v;
		cin >> v;
		multiset <int>::iterator it = --s.upper_bound(v);
		if (*it == -1) {
			cout << -1 << endl;
		}
		else {
			cout << *it << endl;
			s.erase(it);
		}
	}
	return 0;
}
