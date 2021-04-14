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

int n, k;
pii inc[1000010];

multiset <int> ed;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		int a, b;
		cin >> a >> b;
		inc[i] = MP(b, a);
	}
	sort(inc + 1, inc + n + 1);
	int fans = 0;

	for (int i = 1; i <= k; i ++)
		ed.insert(0);
	ed.insert(-233);

	for (int i = 1; i <= n; i ++) {
		set <int>::iterator it = --ed.upper_bound(inc[i].S);
		if (*it == -233)
			continue ;
		// cerr << "come : " << inc[i].S << " " << inc[i].F << " find " << *it << endl;
		fans ++;
		ed.insert(inc[i].F);
		ed.erase(it);
	}
	cout << fans << endl;
	
	return 0;
}
