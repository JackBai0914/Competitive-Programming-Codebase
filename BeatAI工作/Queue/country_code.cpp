#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#define F first
#define S second
#define MP make_pair
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int ans = 0;
	for (char c: s)
		ans += (int)c;
	cout << ans << endl;

	return 0;
}