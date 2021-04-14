#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull dp[20][10][20];
ull n;
int dgn[20];
ull ans = 0, pans = 0;
void dfs (ull n, int dg) {
	if (!n)
		return ;
	ull wei = 0;
	for (int i = dg + 1; i < 20; i ++)
		wei ^= dgn[i];
	for (int i = 0; i < n%10; i ++)
		for (int val = 0; val < 16; val ++) 
			if (dp[dg][i][val] != 0){
				//cerr << dg << " " << i << " " << val << " " << wei << "  " << dp[dg][i][val] << endl;
				ans += dp[dg][i][val] * (val ^ wei);
			}
	dfs (n / 10, dg + 1);
}
void calc (ull x) {
	memset (dgn, 0, sizeof(dgn));
	int dg = 1;
	while (x) {
		dgn[dg ++] = x % 10;
		x /= 10;
	}
	for (int i = 1; i < 20; i ++)
		pans ^= dgn[i];
}

int main() {
	ios::sync_with_stdio(false);
	
	dp[0][0][0] = 1;
	for (int dig = 1; dig <= 19; dig ++)
		for (int s1 = 0; s1 < 20; s1 ++) 
			for (int lv = 0; lv <= 9; lv ++)
				for (int v = 0; v <= 9; v ++)
					if (dp[dig - 1][lv][s1] != 0) {
						dp[dig][v][s1 ^ v] += dp[dig - 1][lv][s1];
						//if (dig == 1)
						//	cerr << "add: " << dig << " " << s1 << " " << lv << " " << v << endl;
					}
	int T;
	cin >> T;
	while (T --) {
		ans = pans = 0;
		cin >> n;
		calc(n);
		dfs (n, 1);
		//cerr << "pans = " << pans << " " << ans << endl;
		cout << ans + pans << endl;
	}

	return 0;
}