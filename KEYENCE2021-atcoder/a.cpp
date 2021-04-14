/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-01-16 11:59:43
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

ll n, a[1000010], b[1000010];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i ++)	cin >> a[i];
    for (int i = 1; i <= n; i ++)	cin >> b[i];

    ll mxa = 0, mxb = 0;
	ll preans = 0;
    for (int i = 1; i <= n; i ++) {
    	mxa = max(mxa, a[i]);
    	mxb = max(mxb, b[i]);
    	ll ans = max (preans, mxa * b[i]);
    	cout << ans << '\n';
    	preans = ans;
    }
    return 0;
}