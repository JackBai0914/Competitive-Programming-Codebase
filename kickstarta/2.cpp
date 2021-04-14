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

int r, c;
ll mp[1010][1010];
bool vis[1010][1010];

priority_queue <pair<ll, int> > q;

bool legal (int x, int y) {
    return (0 <= x && x < r) && (0 <= y && y < c) && vis[x][y] == false;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt ++) {
    	cin >> r >> c;
    	ll ans = 0;
    	for (int i = 0; i < r; i ++)
    		for (int j = 0; j < c; j ++) {
    			cin >> mp[i][j];
                vis[i][j] = 0;
                q.push(MP(mp[i][j], c * i + j));
            }
        while (!q.empty()) {
            int x = q.top().S / c;
            int y = q.top().S % c;
            // cerr << x << " " << y << " " << val << endl;
            q.pop();
            if (vis[x][y])
                continue ;
            vis[x][y] = 1;
            if (legal(x - 1, y) && mp[x - 1][y] < mp[x][y] - 1) {
                ans += mp[x][y] - 1 - mp[x - 1][y];
                mp[x - 1][y] = mp[x][y] - 1;
                q.push(MP(mp[x - 1][y], c * (x - 1) + y));
            }
            if (legal(x + 1, y) && mp[x + 1][y] < mp[x][y] - 1) {
                ans += mp[x][y] - 1 - mp[x + 1][y];
                mp[x + 1][y] = mp[x][y] - 1;
                q.push(MP(mp[x + 1][y], c * (x + 1) + y));
            }
            if (legal(x, y - 1) && mp[x][y - 1] < mp[x][y] - 1) {
                ans += mp[x][y] - 1 - mp[x][y - 1];
                mp[x][y - 1] = mp[x][y] - 1;
                q.push(MP(mp[x][y - 1], c * x + y - 1));
            }
            if (legal(x, y + 1) && mp[x][y + 1] < mp[x][y] - 1) {
                ans += mp[x][y] - 1 - mp[x][y + 1];
                mp[x][y + 1] = mp[x][y] - 1;
                q.push(MP(mp[x][y + 1], c * x + y + 1));
            }
        }
    	
    	cout << "Case #" << tt << ": " << ans << endl;
    }
    return 0;
}