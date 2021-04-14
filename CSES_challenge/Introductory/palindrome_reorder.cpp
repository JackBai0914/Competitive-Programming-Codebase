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

int cnt[30];

int main() {
	std::ios::sync_with_stdio(false);
	string s, pre = "", suf = "", mid = "";
	cin >> s;

	for (int i = 0; i < s.size(); i ++)
		cnt[s[i] - 'A'] ++;

	for (int i = 0; i < 26; i ++) {
		if (cnt[i] % 2) {
			if (mid != "") {
				cout << "NO SOLUTION" << endl;
				return 0;
			}
			mid += (char)('A' + i);
			cnt[i] --;
		}
		for (int j = 1; j <= cnt[i]; j += 2)
			pre += (char)('A' + i), suf += (char)('A' + i);
	}
	// if (suf != "")
		for (int i = 0; i < (int)suf.size() - i - 1; i ++) {
			swap (suf[i], suf[suf.size() - i - 1]);
		}

	cout << pre + mid + suf << endl;
	return 0;
}
