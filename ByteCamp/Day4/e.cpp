
#pragma GCC optimize(2)
#pragma G++ optimize(2)
#pragma GCC optimize(3)
#pragma G++ optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
#define il inline
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define mid ((l+r)>>1)
#define MAXN 3050
#define MAXM 605
#define mod 998244353
#define inf (1<<30)
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
int n, m;
int id[MAXN];
bool lose[MAXN];
ll a[MAXN][MAXM];
void out() {
	rep(i, 1, n) {
		cout << id[i] << ": ";
		rep(j, 1, m + m) cout << a[i][j] << ' ';
		puts("");
	}
}
ll fpow(ll x, ll y) {
	ll ret = 1;
	while(y) {
		if(y & 1) ret = ret * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return ret;
}
ll inv(ll x) {
	return fpow(x, mod - 2);
}
il ll M(ll x) {
	return x >= mod ? x - mod : x;
}
inline void gauss() {
	int cur = 1;
    rep(i, 1, m) {
        int p = cur;
        rep(k, cur+1, n) if(fabs(a[k][i]) > fabs(a[p][i])) p = k;
        if(cur ^ p) swap(id[cur], id[p]), swap(a[cur], a[p]);
		if(a[cur][i] == 0) continue;
		a[cur][cur + m] = 1;
        rep(k, cur + 1, n) {
            ll d = a[k][i] * inv(a[cur][i]) % mod;
            rep(j, i, i + m) a[k][j] = M(a[k][j] - d * a[cur][j] % mod + mod);
        }
		cur++;
		// out();
    }
	// cerr << "cur = " << cur << endl;
	// out();
	rep(i, cur, n) lose[id[i]] = 1;
	rep(i, 1, cur - 1) 
		rep(j, cur, n) 
			if(a[j][m + i] != 0) lose[id[i]] = 1;
}
vector<int> ans;
int main() {
	read(n, m);
	rep(i, 1, n) id[i] = i;
	double x;
	rep(i, 1, n) 
		rep(j, 1, m) 
			scanf("%lf", &x), a[i][j] = x * 100, a[i][j] = (a[i][j] + mod) % mod;
	gauss();
	rep(i, 1, n) if(!lose[i]) ans.pb(i);
	cout << ans.size() << endl;
	for(int v: ans) cout << v << endl;
	return 0;
}