#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#define F first
#define S second
#define MP make_pair
using namespace std;

int n, k;
string s;

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T --) {
		cin >> n >> k >> s;
		int num[2] = {0, 0};
		bool ok = true;
		for (int i = 0; i < k; i ++) {
			char fix = 'a';
			for (int j = 0; j * k + i < n; j ++)
				if (s[j * k + i] != '?')
					fix = s[j * k + i];
			//cerr << i << " : " << fix << endl;
			for (int j = 0; j * k + i < n; j ++)
				if (s[j * k + i] != '?' && fix != 'a' && s[j * k + i] != fix)
					ok = false;
			if (fix != 'a')
				num[fix - '0'] ++;
		}
		ok &= (num[0] <= k / 2);
		ok &= (num[1] <= k / 2);
		cout << (ok ? "YES" : "NO") << '\n';
	}
	
	return 0;
}