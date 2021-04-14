#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 2001;

int n, m, lbt;
int dp[maxn][maxn][2][2];
int rev[maxn];

int cal_rev(int a);

int main() {
	scanf("%d%d%d", &n, &m, &lbt);
	if (n < m) swap(n, m);
	rev[1] = 1;
	for (int i = 2; i <= n; i++) {
		rev[i] = (long long)(lbt - lbt / i) * rev[lbt % i] % lbt;
	}
	for (int s = 0; s <= n + m; s++) {
		for (int i = 1; i <= s; i++) {
			int j = s - i;
			if (j > n) continue;
			if (i > j) break;
			dp[i][j][1][0] = (1 + (long long)rev[j] * dp[j][i - 1][1][0] + (long long)(1 + lbt - rev[j]) * dp[j][i - 1][0][0]) % lbt;
			if (j == 1) dp[i][j][1][1] = 1;
			else dp[i][j][1][1] = (1 + (long long)rev[j] * dp[j - 1][i - 1][0][0] + (long long)rev[j] * dp[j][i - 1][1][0] + (long long)(1 + lbt - rev[j] + lbt - rev[j]) * dp[j][i - 1][0][0]) % lbt;
			swap(i, j);
			dp[i][j][1][0] = (1 + (long long)rev[j] * dp[j][i - 1][1][0] + (long long)(1 + lbt - rev[j]) * dp[j][i - 1][0][0]) % lbt;
			if (j == 1) dp[i][j][1][1] = 1;
			else dp[i][j][1][1] = (1 + (long long)rev[j] * dp[j - 1][i - 1][0][0] + (long long)rev[j] * dp[j][i - 1][1][0] + (long long)(1 + lbt - rev[j] + lbt - rev[j]) * dp[j][i - 1][0][0]) % lbt;
			swap(i, j);
			if (i == 1) {
				dp[j][i][0][1] = 1;
				if (j == 1) dp[i][j][0][1] = 1;
				else dp[i][j][0][1] = (1 + (long long)rev[j] * dp[j - 1][i][0][1] + (long long)rev[j] * dp[j][i][1][1] + (long long)(1 + lbt - rev[j] + lbt - rev[j]) * dp[j][i][0][1]) % lbt;
			}
			else {
				int a1 = (1 + (long long)rev[j] * dp[j - 1][i][0][1] + (long long)rev[j] * dp[j][i][1][1]) % lbt;
				int a2 = (1 + lbt - rev[j] + lbt - rev[j]) % lbt;
				int b1 = (1 + (long long)rev[i] * dp[i - 1][j][0][1] + (long long)rev[i] * dp[i][j][1][1]) % lbt;
				int b2 = (1 + lbt - rev[i] + lbt - rev[i]) % lbt;
				dp[i][j][0][1] = (a1 + (long long)a2 * b1 % lbt) * cal_rev((1 + (long long)(lbt - a2) * b2) % lbt) % lbt;
				dp[j][i][0][1] = (b1 + (long long)b2 * a1 % lbt) * cal_rev((1 + (long long)(lbt - b2) * a2) % lbt) % lbt;
			}
			dp[i][j][0][0] = (1 + (long long)rev[j] * dp[j][i][1][1] + (long long)(1 + lbt - rev[j]) * dp[j][i][0][1]) % lbt;
			dp[j][i][0][0] = (1 + (long long)rev[i] * dp[i][j][1][1] + (long long)(1 + lbt - rev[i]) * dp[i][j][0][1]) % lbt;
		}
	}
	int ans = dp[n][m][0][0];
	printf("%d", ans);
	return 0;
}

void gcd(int a, int b, int &d, int &x, int &y) {
	if (!b) {
		d = a;
		x = 1;
		y = 0;
		return;
	}
	gcd(b, a % b, d, x, y);
	int t = x;
	x = y;
	y = t - a / b * y;
}

int cal_rev(int a) {
	int d, x, y;
	gcd(a, lbt, d, x, y);
	if (x < 0) x += lbt;
	return x;
}