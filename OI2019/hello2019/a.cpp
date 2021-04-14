#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
using namespace std;

string s;
string t[5];

int main() {
	ios::sync_with_stdio(false);
	bool ans = 0;
	cin >> s;
	for (int i = 0; i < 5; i ++) {
		cin >> t[i];
		if (t[i][0] == s[0] || t[i][1] == s[1])
			ans = 1;
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
