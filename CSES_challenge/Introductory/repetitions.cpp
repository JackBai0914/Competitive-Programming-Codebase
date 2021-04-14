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
	char last = ' ';
	int fans = 0, cans = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i ++) {
		char c = s[i];
		if (c == last)
			cans ++;
		else
			cans = 0;
		last = c;
		fans = max (fans, cans + 1);
	}
	cout << fans << endl;
	return 0;
}