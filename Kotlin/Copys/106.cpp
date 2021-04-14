#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define F first
#define S second
#define MP make_pair

int n;
int main() {
	ios::sync_with_stdio(false);
	for (int i = 1; i <= 2 * 7; i ++) {
		for (int j = 1; j <= 3; j ++) {
			string s;
			cin >> s;
			int v = 0;
			for (int k = s.size() - 1; k >= 0; k --)
				v = v * 2 + s[k] - '0';
			cout << v << " ";
		}
		cout << endl;
	}
	return 0;
}