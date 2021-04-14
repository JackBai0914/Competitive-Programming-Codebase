#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
typedef long double ld;
int n, k;

typedef vector <int> circle;

void switch_mx (circle &a) {
	vector <int> b = a;
	for (int i = 1; i < a.size(); i ++) {
		int cmp = 0;
		for (int j = 0; j < a.size() && cmp == 0; j ++) {
			if (a[(i + j) % a.size()] > b[j])	cmp = 1;
			if (a[(i + j) % a.size()] < b[j])	cmp = -1;
		}
		if (cmp == 1) {
			for (int j = 0; j < a.size(); j ++)
				b[j] = a[(i + j) % a.size()];
		}
	}
	a = b;
}

ld ans = 0;

vector <circle> bar[55];
vector <ld>		prob[55];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	circir init;
	for (int i = 1; i <= n; i ++)
		init.push_back(i);
	bar[n].push_back(init);
	prob[n].push_back(1.0);

	for (int num = n; num >= 1; num --) {
		int pt = 0;
		while (pt < bar[num].size()) {
			circle c = bar[num][pt ++];
			
		}
	}

	return 0;
}