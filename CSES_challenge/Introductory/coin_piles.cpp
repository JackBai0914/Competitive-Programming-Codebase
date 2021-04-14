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

bool work (int a, int b) {
	if ((a + b) % 3)
		return false;
	int diff = abs(a - b);
	return diff <= (a + b) / 3;
}


int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		int a, b;
		cin >> a >> b;
		cout << (work (a, b) ? "YES":"NO") << endl;;
	}	
	return 0;
}
