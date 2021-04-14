#include <bits/stdc++.h>
#define il inline
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define mid ((l+r)>>1)
#define MAXN 100050
#define MAXM 
#define mod 
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
int n, k;
pii mat[MAXN];
struct node {
	int ty, x, y;
	bool operator < (const node &rhs) const {
		return x == rhs.x ? ty < rhs.ty : x < rhs.x;
	}
} C[MAXN << 2];
int t[MAXN];
void ins(int x, int w) {
	for(int i = x; i < MAXN; i += i & -i) chkmax(t[i], w);
}
int query(int x) {
	int ret = -1;
	for(int i = x; i; i -= i & -i) chkmax(ret, t[i]);
	return ret;
}
int a[MAXN], val[MAXN], val2[MAXN];
pii ch[MAXN];
namespace XXJ {
	int val[MAXN];
	int p[30], cons[30], id[30], num;
	void ins(int x, int _id) {
		int cst = 1 << (num + 1);
		repd(i, 20, 0) {
			if(x & (1 << i)) {
				if(!p[i]) {
					p[i] = x, cons[i] = cst, id[++num] = _id;
					return ;
				}
				else x ^= p[i], cst ^= cons[i];
			}
		}
	}
	int oans[MAXN];
	bool solve() {
		int tar = 0;
		rep(i, 1, k) val[i] = ch[i].sec ^ ch[i].fir, tar ^= ch[i].fir; 
		// choose = 1, no choose = 0
		rep(i, 1, k) ins(val[i], i);
		int state = 0;
		repd(i, 20, 0) {
			if(tar & (1 << i)) {
				if(!p[i]) return 0;
				tar ^= p[i], state ^= cons[i];
			}
		}
		repd(i, 20, 0) if(state & (1 << i)) oans[id[i]] = 1;
		return 1;
	}
}
int main() {
	read(n, k);
	rep(i, 1, n) read(mat[i].fir, mat[i].sec);
	rep(i, 1, k) read(a[i]);
	int tot = 0;
	rep(i, 1, n) C[++tot] = node {-i, mat[i].fir, mat[i].sec}, C[++tot] = node {i, mat[i].fir - 1, mat[i].sec - 1};
	rep(i, 1, k) C[++tot] = node {i + n, mat[i].sec - 1, mat[i].fir - 1};
	sort(C + 1, C + tot + 1);
	rep(i, 1, MAXN - 5) t[i] = -1;
	rep(i, 1, tot) {
		int ty = C[i].ty, y = C[i].y;
		// cerr << ty << ' ' << C[i].x << ' ' << y << endl;
		if(ty < 0) ins(y, val[-ty]);
		else {
			if(ty <= n) val[ty] = query(y) + 1;
			else val2[ty - n] = query(y) + 1;
		}
	}
	// rep(i, 1, n) cout << val[i] << ' '; puts("");
	rep(i, 1, k) ch[i] = mp(val[a[i]], val2[a[i]]);
	// rep(i, 1, k) cout << val2[a[i]] << ' '; puts("");
	if(XXJ :: solve()) {
		rep(i, 1, k) printf("%d", XXJ :: oans[i]);
	}
	else printf("impossible");
	return 0;
}