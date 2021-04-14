/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-18 13:11:44
* @description: 
* /Users/jackbai/Desktop/OI/Google_kickstart_G/c2.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv c2.cpp
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


ll w, n;
ll v[1000010];
ll s1[1000010], s2[1000010];

ll calc (int st, int ed, int tg) {
	return (s1[ed] - s1[tg]) - (ed - tg) * v[tg]
			+ (s2[st] - s2[tg]) - (tg - st) * (2*n - v[tg]);
}

int main() {
	int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt ++) {
        ll ans = 1e16;
        cin >> w >> n;
        F0R(i, 3 * w)
            s1[0] = s2[0] = 0;
        F0R(i, w) {
            cin >> v[i];
            v[w + i] = v[i] + n;
        }
        sort (v, v + 2 * w);
        FOR(i, 0, 2*w)
        	s1[i] = (i ? s1[i - 1] : 0) + v[i];
        ROF(i, 0, 2*w)
        	s2[i] = s2[i + 1] + (2 * n - v[i]);

        int st = 0, ed = w - 1;
        for(int i = 0; i < 2 * w; i ++) {
        	while (ed + 1 < 2 * w && calc(st, ed, i) >= calc(st + 1, ed + 1, i)) {
        		// cerr << " : " << calc(st, ed, i) << " " << calc(st + 1, ed + 1, i) << endl;
        		st ++, ed ++;
        	}
        	// cerr << "ans for" << i << " : " << st << " , " << ed << " : " << calc(st, ed, i) << endl;
        	ans = min (ans, calc(st, ed, i));
        }
        cout << "Case #" << tt << ": " << ans << endl;
    }

    return 0;
}