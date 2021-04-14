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
	if (n * (n + 1) / 2 % 2 == 1) {
		cout << "NO" << endl;
		return 0;
	}
	else {
		cout << "YES" << endl;
		if (n % 2 == 0) {
			cout << n / 2 << endl;
			for (int i = 1; i <= n / 2 / 2; i ++)
				cout << i << ' ' << n + 1 - i << ' ';
			cout << endl;
			cout << n / 2 << endl;
			for (int i = n / 2 / 2 + 1; i <= n / 2; i ++)
				cout << i << ' ' << n + 1 - i << ' ';
			cout << endl;
		}
		else {
			cout << n / 2 + 1 << endl;
			for (int i = 1; i <= (n / 2 + 1) / 2 - 1; i ++)
				cout << i << ' ' << n + 1 - i << ' ';
			cout << (n / 2 + 1) / 2 << ' ' << n / 2 + 1 << endl;
			cout << n / 2 << endl;
			for (int i = (n / 2 + 1) / 2 + 1; i <= n / 2; i ++)
				cout << i << ' ' << n + 1 - i << ' ';
			cout << n + 1 - (n / 2 + 1) / 2 << endl;
		}
	}

	return 0;
}