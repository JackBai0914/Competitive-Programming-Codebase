#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
using namespace std;

string s[100010];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <=n ; i ++)
		cin >> s[i];
	sort(s + 1, s + n + 1);
	cout << s[1] << endl;

	return 0;
}