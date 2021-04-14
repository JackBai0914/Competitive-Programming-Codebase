#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <unordered_map>
#include <queue>
#include <map>
#define F first
#define S second
#define MP make_pair
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
typedef pair <int, int> pii;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)

map <pii, int> mp;

int main() {
	const int n = 1e3;
	const int m = 6e3;
	cout << "[";
	F0R(i, m) {
		if (i)
			cout << ",";
		int st, ed;
		do {
			st = rand() % (int)n;
			ed = rand() % (int)n;
		} while (st == ed || mp[MP(st, ed)] == 1);
		mp[MP(st, ed)] = mp[MP(ed, st)] = 1;
		cout << '(' << st << ',' << ed << ')';
		cout << ",";
		cout << '(' << ed << ',' << st << ')';
	}
	cout << "]";
    return 0;
}