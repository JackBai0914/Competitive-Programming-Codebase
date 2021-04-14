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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
ll ans = 0;

void dfs (int n) {
	if (!n)
		return ;
	ans += n / 5;
	dfs (n / 5);
}

int main() {
	std::ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	dfs (n);
	cout << ans << endl;
	return 0;
}
