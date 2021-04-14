/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-18 14:14:12
* @description: 
*  
* 
* @notes: 
* g++ -fsanitize=address -ftrapv 
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int mod = 1000000007; 
const ll oo = 1e18;
const ld eps = 1e-8;
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int n;
ll v[100010];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
    	cin >> n;
    	ll l[2] = {n, n}, dir = 0, mn[2] = {10000000000ll, 10000000000ll};
    	ll pre = 0, fans = 1e16;
    	for (int i = 1; i <= n; i ++) {
    		cin >> v[i];
    		l[dir] --;
    		pre += v[i];
    		mn[dir] = min(mn[dir], v[i]);
    		dir ^= 1;
    		fans = min (fans, pre + mn[0] * l[0] + mn[1] * l[1]);
    	}
    	cout << fans << endl;
    }
    return 0;
}