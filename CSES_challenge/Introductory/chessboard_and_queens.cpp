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
#define F first
#define S second
#define MP make_pair

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

pii q[10];
bool mp[10][10];
bool col[10];

ll fans = 0;

bool d_att(pii a, pii b) {
	return abs(a.F - b.F) == abs(a.S - b.S);
}

void dfs (int r) {
	// cerr << "dfs: " << r << endl;
	if (r == 9) {
		fans += 1;
		return ;
	}
	for (int c = 1; c <= 8; c ++)
		if (!col[c] && !mp[r][c]) {
			pii ne = MP(r, c);
			bool ok = true;
			for (int i = 1; i < r; i ++)
				if(d_att(q[i], ne))
					ok = 0;
			if (!ok)
				continue ;
			col[c] = 1;
			q[r] = ne;
			dfs (r + 1);
			col[c] = 0;
		}
}

int main() {
	std::ios::sync_with_stdio(false);
	for (int i = 1; i <= 8; i ++)
		for (int j = 1; j <= 8; j ++) {
			char c;
			cin >> c;
			mp[i][j] = (c != '.');
		}
	dfs (1);
	cout << fans << endl;
	return 0;
}
