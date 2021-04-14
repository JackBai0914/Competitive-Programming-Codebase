/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-21 03:58:38
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
int a[1010][1010], b[1010][1010];
int r[1010], c[1001];
int rt[2020];

priority_queue <pair<ll, int> > q;
int get_r(int x) {return (x == rt[x] ? x : rt[x] = get_r(rt[x]));}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt ++) {
    	cin >> n;
    	ll ans = 0, sum = 0;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++)
                cin >> a[i][j];
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++) {
                cin >> b[i][j];
                sum += b[i][j];
            }
        for (int i = 0; i < n; i ++)
            cin >> r[i];
        for (int i = 0; i < n; i ++)
            cin >> c[i];
        for (int i = 0; i < 2 * n; i ++)
            rt[i] = i;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++)
                if (a[i][j] == -1)
                    q.push(MP(b[i][j], i * n + j));
        while (!q.empty()) {
            int x = q.top().S / n;
            int y = q.top().S % n;
            int v = q.top().F;
            q.pop();
            if (get_r(x) == get_r(n + y))
                continue ;
            ans += v;
            rt[get_r(x)] = get_r(n + y);
        }
    	cout << "Case #" << tt << ": " << sum - ans << endl;
    }
    return 0;
}