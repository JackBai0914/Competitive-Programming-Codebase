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


ll w, n;
ll v[1000010];
ll s1[1000010], s2[1000010];



int main() {
	int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt ++) {
        ll ans = 1e16;
        cin >> w >> n;
        F0R(i, w + 1)
            s1[0] = s2[0] = 0;
        F0R(i, w)
            cin >> v[i];
        sort(v, v + w);
        F0R(i, w) {
            s1[i] = (i ? s1[i - 1] + v[i] : v[i]);
        }
        R0F(i, w) {
            s2[i] = s2[i + 1] + (n - v[i]);
        }
        int pter = 0;
        F0R(i, w) {
            //fix v[i] as the target
            ll tg = v[i];
            if (tg <= n/2) {
                while (pter + 1 < w && v[pter + 1] <= tg + n / 2)
                    pter ++;
                ll pans1 = (s2[0] - s2[i]) - i * (n - tg);
                ll pans2 = (s1[pter] - s1[i]) - (pter - i) * tg;
                ll pans3 = s2[pter+1] + (w-1-pter) * tg;
                ans = min (ans, pans1 + pans2 + pans3);
                // cerr << "ans at " << tg << " : " << pans1 << " " << pans2 << " " << pans3 << endl;
            }
        }

        int pter1 = w - 1;
        for (int i = w - 1; i >= 0; i --) {
            //fix v[i] as the target
            ll tg = v[i];
            if (tg > n/2) {
                while (pter1 - 1 >= 0 && v[pter1 - 1] >= tg - n / 2)
                    pter1 --;
                ll pans1 = (s1[w-1] - s1[i]) - (w-1 - i) * tg;
                ll pans2 = (s2[pter1] - s2[i]) - (i - pter1) * (n - tg);
                ll pans3 = (pter1 ? s1[pter1-1] : 0) + pter1 * (n - tg);
                ans = min (ans, pans1 + pans2 + pans3);
                // cerr << "ans at " << tg << " : " << pans1 << " " << pans2 << " " << pans3 << endl;

            }
        }
        cout << "Case #" << tt << ": " << ans << endl;
    }

    return 0;
}