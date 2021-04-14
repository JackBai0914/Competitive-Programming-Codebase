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

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
	}
	if (n == 2 || n == 3) {
		cout << "NO SOLUTION" << endl;
	}
	if (n == 4) {
		cout << "2 4 1 3" << endl;
	}
	if (n > 4) {
		for (int i = 1; i <= n; i += 2)
			cout << i << ' ';
		for (int i = 2; i <= n; i += 2)
			cout << i << ' ';
		cout << endl;
	}
	return 0;
}