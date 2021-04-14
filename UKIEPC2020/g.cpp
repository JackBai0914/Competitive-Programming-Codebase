#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
const long long oo = 1e18;
long long dp1[maxn][2], dp2[maxn][2];
long long a[maxn], b[maxn];
long long min(long long x, long long y)
{
	return x < y ? x : y;
}
long long min(long long x, long long y, long long z)
{
	return x < y && x < z ? x : (y < z ? y : z);
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		a[i] = oo;
	for(int i = 1; i <= m; i ++)
	{
		int c;
		cin >> c;
		cin >> a[c];
	}
	for(int i = 1; i <= n; i ++)
		cin >> b[i];
	dp1[1][0] = a[1];
	dp1[1][1] = 0;
	for(int i = 2; i <= n; i ++)
	{
		dp1[i][0] = min(dp1[i - 1][0] + a[i], dp1[i - 1][0] + b[i - 1], dp1[i - 1][1] + b[i - 1] + a[i]);
		dp1[i][1] = min(dp1[i - 1][0], dp1[i - 1][1] + b[i - 1]);
	}
	dp2[1][0] = dp2[1][1] = 0;
	for(int i = 2; i <= n; i ++)
	{
		dp2[i][0] = min(dp2[i - 1][0] + a[i], dp2[i - 1][0] + b[i - 1], dp2[i - 1][1] + b[i - 1] + a[i]);
		dp2[i][1] = min(dp2[i - 1][0], dp2[i - 1][1] + b[i - 1]);
	}
	cout << min(dp1[n][0], dp1[n][1] + b[n], dp2[n][0] + b[n]) << endl;

	return 0;
}