#include <bits/stdc++.h>
#define il inline
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define mid ((l+r)>>1)
#define MAXN 45
#define MX 200
#define mod 
#define inf (1ll << 30)
#define eps (1e-6)
#define alpha 0.75
#define rep(i, x, y) for(register int i = x; i <= y; ++i)
#define repd(i, x, y) for(register int i = x; i >= y; --i)
#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef pair <ll, ll> pll;
template <typename T> il bool chkmin(T &x, T y) {return x > y ? x = y, 1 : 0;}
template <typename T> il bool chkmax(T &x, T y) {return x < y ? x = y, 1 : 0;}
template <typename T> il void read(T &x) {
	char ch = getchar(); int f = 1; x = 0;
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') x = x*10+ch-'0', ch = getchar();
	x *= f;
}
template <typename T, typename... Args> il void read(T &x, Args &...args) {
	read(x), read(args...);
}
int T, n, m, z, state[MAXN][MAXN][MX * 2 + 100];
// state = -1 unclear, 0 will lose, 1 will win
int deg[MAXN][MAXN][MX * 2 + 100];
vector<int> adj[MAXN], nadj[MAXN];
int dis[MAXN][MAXN], score[MAXN][MAXN];
struct node {
	int i, j, k;
} qu[MAXN * MAXN * MX * 2 + 100];
int tot;
void bfs(int s) {
	dis[s][s] = 0;
	static int q[MAXN], fr, re;
	fr = re = 0;
	q[re++] = s;
	while(fr < re) {
		int u = q[fr++];
		for(int v: adj[u])
			if(dis[s][v] == -1) dis[s][v] = dis[s][u] + 1, q[re++] = v;
		for(int v: nadj[u])
			if(dis[s][v] == -1) dis[s][v] = dis[s][u] + 1, q[re++] = v;
	}
}
void init() {
	rep(i, 1, n) bfs(i);
	rep(i, 1, n)
		rep(j, 1, n) {
			int ss = 0;
			rep(k, 1, n) 
				if(dis[i][k] < dis[j][k]) ss++;
				else if(dis[i][k] > dis[j][k]) ss--;
			if(ss > 0) score[i][j] = 1;
			else if(ss < 0) score[i][j] = -1;
		}
}
void ins(int i, int j, int k) {
	qu[++tot] = node {i, j, k};
}
int main() {
	read(T);
	rep(tk, 1, T) {
		read(n, m, z);
		rep(i, 1, n) adj[i].clear(), nadj[i].clear();
		memset(state, -1, sizeof(state));
		memset(dis, -1, sizeof(dis));
		memset(score, 0, sizeof(score));
		int u, v;
		rep(i, 1, m) read(u, v), ++u, ++v, adj[u].pb(v), nadj[v].pb(u);
		init();
		rep(i, 1, n) {
			if(adj[i].size() == 0) {
				rep(j, 1, n)
					rep(k, 0, MX * 2) state[i][j][k] = 0, ins(i, j, k);
			}
			if(adj[i].size() == 1) {
				rep(k, 0, MX * 2) 
					state[i][*adj[i].begin()][k] = 0, ins(i, *adj[i].begin(), k);
			}
		}
		rep(i, 1, n)
			rep(j, 1, n)
				rep(k, 1, n)
					deg[i][j][k] = nadj[j].size();
		rep(i, 1, n)
			rep(j, 1, n) {
				if(state[i][j][0] == -1) state[i][j][0] = 0, ins(i, j, 0);
				if(state[i][j][MX * 2] == -1) state[i][j][MX * 2] = 1, ins(i, j, MX * 2);
			}
		for(int t = 1; t <= tot; t++) {
			int i = qu[t].i, j = qu[t].j, k = qu[t].k;
			for(int v: nadj[i]) {
				// MX-(k - MX + score[v][j])
				// nstate = (j, v, k + score)
				int ni = j, nj = v, nk = MX - (k - MX + score[v][j]);
				if(0 <= nk && nk <= 2 * MX) {	
					if(state[i][j][k] == 0) {
						if(state[ni][nj][nk] == -1) state[ni][nj][nk] = 1, ins(ni, nj, nk);
					}
					else {
						--deg[ni][nj][nk];
						if(deg[ni][nj][nk] == 0 && state[ni][nj][nk] == -1)
							state[ni][nj][nk] = 0, ins(ni, nj, nk);
					}
				}
			}
		}
		int R = 0, Z = 0, N = 0;
		rep(i, 1, z)
			rep(j, z+1, n)
				if(state[i][j][MX] == 0) Z ++;
				else if(state[i][j][MX] == 1) R ++;
				else N ++;
		printf("Case #%d: %d %d %d\n", tk, R, Z, N);
	}
	return 0;
}