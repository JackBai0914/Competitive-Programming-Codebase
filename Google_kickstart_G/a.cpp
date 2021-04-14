/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-18 12:53:38
* @description: 
* /Users/jackbai/Desktop/OI/Google_kickstart_G/a.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv a.cpp
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

string s;
int v[1000010];
int vv[1000010];

bool st (string s) {
    return s == "KICK";
}
bool ed (string s) {
    return s == "START";
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        ll ans = 0;
        cin >> s;
        F0R(i, s.size()  +1)
        	v[i] = vv[i] = 0;
        FOR(i, 3, s.size()) {
            if (st(s.substr(i - 3, 4)))
                v[i] = 1;

        }
        FOR(i, 1, s.size()) {
            vv[i] = vv[i - 1] + v[i];
            if (i + 5 < s.size() && ed(s.substr(i + 1, 5))) {
                ans += vv[i];
                // cerr << i << " : " << vv[i] << endl;
            }

          }
        cout << ans << endl;
    }

    return 0;
}
