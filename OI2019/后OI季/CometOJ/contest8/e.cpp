#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#define N 6000010
using namespace std;
typedef long long ll;

bool vis[N];
ll pre[N], sum[N];
void get(int maxn)
{
	pre[1] = sum[1] = 1;
    for (int i = 2; i <= maxn; i ++) {
    	pre[i] = i;
    	for (int j = 2; j * j <= i; j ++)
    		pre[i] -= pre[i / j / j];
    	sum[i] = sum[i - 1] + pre[i];
    }
}
ll t,n;
ll f[4000040];

int cnt = 0;

ll calc_f (int c) {
	ll x = n / c / c;
	if (x <= 200000)
		return pre[x];
	if (f[c] != -1)
		return f[c];
	
	f[c] = x;
	cerr << x << endl;
	for (int i = 2; i <= x / i; i ++) {
		int c2 = c * i;
		cnt ++;
		
		f[c] -= calc_f(c2);
	}
	return f[c];
}



int main()
{
    cin >> t;
    get(200000);
    while (t --) {
    	memset(f, -1, sizeof f);
    	ll fans = 0;
    	cin >> n;
    	for (int i = 1; i <= n / i; i ++) {
    		fans += i * calc_f(i);
    		// cerr << i << " : " << calc_f(i) << endl;
    	}
    	cout << fans << endl;
    	cerr << "cnt = " << cnt << endl;
    }
    return 0;
}