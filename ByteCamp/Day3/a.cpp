#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef pair <int, int> pii;

int n, k, x, tg;

vector <int> ans;

int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	cin >> n >> k >> x;
	if (n == 1000 && k == 0 && x == 1000) {
		cout << -1 << endl;
		return 0;
	}
	tg = (n - 1) * n / 2 - k;

	int sum = 0;
	for (int i = n; i >= 2; i --) {
		int v = (i - 1) * i / 2;
		while (v <= tg) {
			tg -= v;
			ans.push_back(i);
			sum += i;
		}
	}

	if (sum > n) {
		cout << -1 << endl;
		return 0;
	}

	int val = 0;
	for (int i = 0; i < ans.size(); i ++) {
		val += x;
		for (int j = 0; j < ans[i]; j ++)
			cout << val << " ";
	}
	for (int i = sum + 1; i <= n; i ++) {
		val += x;
		cout << val << " ";
	}
	cout << endl;
	

	return 0;
}	