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
pii inc[1000010];

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		int a, b;
		cin >> a >> b;
		inc[i] = MP(b, a);
	}
	sort(inc + 1, inc + n + 1);
	int end = 0, fans = 0;
	for (int i = 1; i <= n; i ++) {
		if (inc[i].S < end)
			continue ;
		end = inc[i].F;
		fans ++;
	}
	cout << fans << endl;
	
	return 0;
}
