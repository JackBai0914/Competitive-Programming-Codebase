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
	ll n;
	cin >> n;
	cout << n << " ";
	while (n > 1) {
		(n % 2 ? ((n *= 3) += 1) : n /= 2);
		cout << n << " ";
	}
	cout << endl;


	return 0;
}