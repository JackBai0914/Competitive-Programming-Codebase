#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;

string s;

int main() {
	ios::sync_with_stdio(false);
	int cnt = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i ++)
		cnt += (s[i] == '1');
	cout << cnt << endl;

	return 0;
}