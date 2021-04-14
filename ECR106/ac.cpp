/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-18 15:04:48
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

int c, d, x;
int gcd (int a, int b) { return (b == 0 ? a : gcd(b, a % b));}

int prime[10010], flag[10010], pst = 0;
void init () {
    // <= 10000
    for (int i = 2; i <= 10000; i ++) {
        if (flag[i] == 0)
            prime[++ pst] = i;
        for (int j = 1; j <= pst && prime[j] * i <= 10000; j ++) {
            flag[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int count (int x0) {
    if ((x0 + d) % c)
        return 0;
    int prod = (x0 + d) / c, pans = 1;
    for (int i = 1; prime[i] * prime[i] <= prod; i ++)
        if (prod % prime[i] == 0) {
            while (prod % prime[i] == 0)
                prod /= prime[i];
            pans *= 2;
        }
    if (prod != 1)
        pans *= 2;
    // cerr << x0 << " : " << pans << endl;
    return pans;
}

int main() {
    ios::sync_with_stdio(false);
    init();
    int t;
    cin >> t;
    while (t--) {
        ll ans = 0;
        cin >> c >> d >> x;
        for (int i = 1; i * i <= x; i ++)
            if (x % i == 0) {
                ans += count (x / i);
                if (i * i != x)
                    ans += count (i);
            }
        cout << ans << '\n';
    }
    cerr << TIME << endl;
    return 0;
}