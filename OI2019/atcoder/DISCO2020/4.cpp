#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define MP make_pair
#define F first
#define S second
using namespace std;
typedef long long ll;
ll m;
ll c[2000020], d[2000020];

ll fans = 0;

void dfs (ll num, ll sum) {
	if (num <= 1)
		return ;
	fans += num - 1;
	ll num1 = 0, sum1 = 0;
	while (sum) {
		num1 ++;
		sum1 += sum % 10;
		sum /= 10;
	}
	dfs (num1, sum1);
}


int main () {
	ios::sync_with_stdio(false);
	cin >> m;
	ll sum = 0, num = 0;
	for (int i = 1; i <= m; i ++) {
		cin >> d[i] >> c[i];
		sum += d[i] * c[i];
		num += c[i];
	}
	cout << num - 1 + (sum - 1) / 9 << endl; 
	return 0;
}