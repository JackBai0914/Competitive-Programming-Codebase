/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-18 13:11:44
* @description: 
* /Users/jackbai/Desktop/OI/Google_kickstart_G/b.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv b.cpp
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
const int MOD = 1000000007; 
const ll INF = 1e18;
const ld eps = 1e-8;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl


ll n, ans = 0;
ll v[1010][1010];
ll sum[10010];
const int g = 2000;

int main() {
	int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt ++) {
    	F0R(i, 10000)
    		sum[i] = 0;
        ll ans = 0;
        cin >> n;
        F0R(i, n)
        	F0R(j, n) {
        		cin >> v[i][j];
        		sum[i - j + g] += v[i][j];
        	}
        F0R(i, 10000)
        	ans = max (ans, sum[i]);
        cout << "Case #" << tt << ": " << ans << endl;
    }

    return 0;
}