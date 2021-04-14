/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 * 
 * @author: Xingjian Bai 
 * @dateTime: 2020-09-19 08:59:02
 * @description: 
 * 
 * @notes: 
 * g++ -O2 -fsanitize=address -ftrapv a.cpp -o a 
 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound


typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int MOD = 1e9 + 7; // 998244353
const ll INF = 1e18;
const ld PI = acos((ld)-1);

const int MAXN = 1e6 + 10;
int n, x, par[MAXN], wei[MAXN];
int num[MAXN], dep[MAXN], desc[MAXN], top[MAXN];
int dfn[MAXN], ti = 0;
vector <int> sons[MAXN];

void dfs (int x) {
    num[x] = 1;
    int mx = 0;
    for (int i = 0; i < sons[x].size(); i ++) {
        int s = sons[x][i];
        if (s == par[x])
            continue ;
        dep[s] = dep[x] + 1;
        par[s] = x;
        dfs (s);
        num[x] += num[s];
        if (num[s] > mx)
            mx = num[s], desc[x] = s;
    }
}
void build (int x, int tp) {
    dfn[x] = ++ ti;
    top[x] = tp;
    if (desc[x])
        build (desc[x], tp);
    for (int i = 0; i < sons[x].size(); i ++) {
        int s = sons[x][i];
        if (s == par[x] || s == desc[x])
            continue ;
        build (s, s);
    }
}
int lca (int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
            swap (x, y);
        x = par[top[x]];
    }
    return (dep[x] < dep[y] ? x : y);
}

vector <pii> bar[MAXN];
bool ord (pii x, pii y) {
    if (x.f == y.f)
        return dfn[x.s] < dfn[y.s];
    return x.f < y.f;
}

vector <int> contr[MAXN];

int f[1000010];


int ans[1010][1010];
void dfs2 (int x) {
	for (int i = 0; i < contr[x].size(); i ++)
		ans[x][contr[x][i]] = 1;
	for (int i = 0; i < sons[x].size(); i ++) {
        int s = sons[x][i];
        if (s == par[x])
            continue ;
        dfs2(s);
        for (int j = 0; j <= n; j ++)
			ans[x][j] |= ans[s][j];
	}
	int fans = 0;
	for (int i = 0; i <= n; i ++)
		fans += ans[x][i];
	f[x] = fans;
}

int main() {
	ios::sync_with_stdio(false);
	// freopen("inp.in", "r", stdin);
	// freopen("outp.out", "w", stdout);
    cin >> n >> x;
    for (int i = 2; i <= n; i ++) {
        cin >> par[i];
        sons[par[i]].push_back(i);
    }
    for (int i = 1; i <= n; i ++)
        cin >> wei[i];
    dep[1] = 1;
    dfs (1);
    build (1, 1);
    for (int i = 1; i <= n; i ++)
    	cout << i << " : " << dfn[i] << " " << dep[i] << " " << top[i] << endl;
    for (int i = 0; i <= n; i ++) {
        bar[dep[i]].push_back(mp(wei[i], i));
        bar[dep[i]].push_back(mp(wei[i]^x, i));
        // cerr << "pb " << dep[i] << " " << i << " " << (i^x) << endl;
    }
    for (int i = 0; i <= n; i ++)
        sort (bar[i].begin(), bar[i].end(), ord);
    for (int i = 0; i <= n; i ++) {
        int la = 0;
        for (int j = 0; j < bar[i].size(); j ++) {
        	// cerr << "info: " << i << " " << bar[i][j].f << " " << bar[i][j].s << endl;
            if (wei[bar[i][j].s] == bar[i][j].f)
                la = bar[i][j].s;
            else {
                int p = bar[i][j].s;
                if (la && wei[la] == bar[i][j].f) {
                    contr[lca(p, la)].push_back(i);
                    // cerr << "link " << p << " and " << la << ", adding " << i << " to " << lca(p, la) << endl;
                }
            }
        }
        int ne = 0;
        for (int j = bar[i].size() - 1; j >= 0; j --) {
            if (wei[bar[i][j].s] == bar[i][j].f)
                ne = bar[i][j].s;
            else {
                int p = bar[i][j].s;
                if (ne && wei[ne] == bar[i][j].f) {
                    contr[lca(p, ne)].push_back(i);
                    // cerr << "link " << p << " and " << ne << ", adding " << i << " to " << lca(p, la) << endl;
                }
            }
        }
    }

    dfs2(1);

    ll fans = 0;
    // for (int i = 1; i <= n; i ++)
    	// cerr << i << " : " << f[i] << endl;
    for (int i = 1; i <= n; i ++)
    	fans += (i ^ (n - f[i]));
    cout << fans % 998244353 << endl;
    
	return 0;
}