/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-21 14:46:58
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
const ld eps = 1e-8;
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int n, m, q;
vector <pii> adj[660];
ll wei[400040];
ll mp[660][660];

pii tri[400040];
ll len[400040];

bool ans[400040];
int cnt = 0;

ll est[660];

const ll oo = 1e14;
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    	for (int j = 1; j <= n; j ++)
    		mp[i][j] = oo;
    for (int i = 1; i <= n; i ++)
    	mp[i][i] = 0;
    for (int u, v, w, i = 1; i <= m; i ++) {
    	cin >> u >> v >> w;
    	mp[u][v] = mp[v][u] = w;
    	adj[u].push_back(MP(v, i));
    	adj[v].push_back(MP(u, i));
    	wei[i] = w;
    }
    cin >> q;
    for (int i = 1; i <= q; i ++)
    	cin >> tri[i].F >> tri[i].S >> len[i];

    for (int k = 1; k <= n; k ++)
    	for (int i = 1; i <= n; i ++)
    		for (int j = 1; j <= n; j ++)
    			if (mp[i][k] + mp[k][j] < mp[i][j])
    				mp[i][j] = mp[i][k] + mp[k][j];
    for (int i = 1; i <= n; i ++) {
    	for (int j = 1; j <= n; j ++)
    		est[j] = -1;
    	for (int j = 1; j <= q; j ++) {
    		est[tri[j].S] = max (est[tri[j].S], len[j] - mp[tri[j].F][i]);
    		est[tri[j].F] = max (est[tri[j].F], len[j] - mp[tri[j].S][i]);
    	}
    	for (int eid = 0; eid < adj[i].size(); eid ++) {
    		int to = adj[i][eid].F;
    		int e = adj[i][eid].S;
    		for (int j = 1; j <= n; j ++)
    			if (est[j] >= wei[e] + mp[to][j]) {
    				//find a satisfying
    				cnt += (ans[e] == 0);
    				ans[e] = 1;
    				break;
    			}
    	}
    }
    cout << cnt << endl;
    return 0;
}