#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;

int num[10] = {1110111, 10010, 1011101, 1011011, 111010, 1101011, 1101111, 1010010, 1111111, 1111011};
int n, k;
int ins[2020];
int mx[2020][10];

int turn (int s, int t) {
	int cost = 0;
	for (int i = 1; i <= 7; i ++, s /= 10, t /= 10) {
		if (s % 10 == t % 10)
			continue ;
		if (s % 10 == 1)
			return -1;	
		cost ++;
	}
	return cost;
}


void process (int s, int index) {
	for (int i = 0; i < 10; i ++) {
		int cost = turn (s, num[i]);
		// cerr << "comp " << s << " : " << num[i] << " : " << cost << endl;
		if (cost == -1)
			continue ;
		
		// cerr << "upd : " << index << " " << cost << " " << mx[index][cost] << " -> " << i << endl;
		mx[index][cost] = max (mx[index][cost], i);
	}
}

int dp[2050][2050];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	memset (mx, -1, sizeof mx);
	for (int i = n; i >= 1; i --) {
		cin >> ins[i];
		process (ins[i], i);
	}
	// for (int j = 1; j <= n; j ++) {
	// 	for (int i = 0; i <= 7; i ++)
	// 		cerr << mx[j][i] << " ";
	// 	cerr << endl;
	// }

	// memset (dp, 0, sizeof dp);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j <= k && j <= i * 7; j ++)
			if (dp[i - 1][j] == 1)
				for (int l = 0; l + j <= k && l <= 7; l ++)
					if (mx[i][l] != -1)
						dp[i][j + l] = 1;
	if (dp[n][k] == 0) {
		cout << -1 << endl;
		return 0;
	}

	int used = 0;
	for (int i = n; i >= 1; i --) {
		// cerr << i << " : " << used << endl;
		int mxv = -1, id = -1;
		for (int j = 0; j <= 7 && j + used <= k; j ++)
			if (mx[i][j] != -1 && dp[i - 1][k - used - j] == 1)
				if (mx[i][j] > mxv) {
					mxv = mx[i][j];
					id = j;
				}
		used += id;
		cout << mxv;
	}
	cout << endl;
	return 0;
}