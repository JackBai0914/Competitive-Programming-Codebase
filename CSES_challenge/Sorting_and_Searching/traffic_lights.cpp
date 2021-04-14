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

set <int> s;

priority_queue<pii> q;
map <pii, bool> ban;

int main() {
	std::ios::sync_with_stdio(false);
	int n, x;
	cin >> x >> n;
	s.insert(0);
	s.insert(x);
	q.push(MP(x, 0));


	for (int i = 1; i <= n; i ++) {
		int m;
		cin >> m;
		int st = *(--s.upper_bound(m));
		int ed = *s.upper_bound(m);

		s.insert(m);
		q.push(MP(m - st, st));
		q.push(MP(ed - m, m));
		ban[MP(ed - st, st)] = true;

		while (ban[q.top()])
			q.pop();
		cout << q.top().F << ' ';
	}
	cout << endl;
	return 0;
}
