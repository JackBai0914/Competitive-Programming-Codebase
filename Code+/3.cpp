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
typedef long long ll;

ll n, p, x;
ll mp[10010];



int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	while (n --) {
		cin >> p >> x;
		for (int i = 0; i < p; i ++)
			mp[i] = 0;
		for (int i = 0; i < p; i ++)
			mp[i*i%p]++;
		int ans = 0;
		for (int i = 0; i < p; i ++) {
			ans += mp[i] * mp[(x + p - i) % p];
		}
		cout << ans << endl;
	}

	
	return 0;
}