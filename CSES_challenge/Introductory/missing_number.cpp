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

bool flag[1000010];

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int v, i = 1; i < n; i ++) {
		cin >> v;
		flag[v] = 1;
	}
	for (int i = 1; i <= n; i ++)
		if (!flag[i])
			cout << i << endl;



	return 0;
}