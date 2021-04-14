#include <bits/stdc++.h>
#define il inline
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define mid ((l+r)>>1)
#define MAXN 1000050
#define MAXM 
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
int n;
ld a[MAXN], v[MAXN];
bool vis[MAXN];
set<int> se;
struct node {
	int x, y;
	ld t;
	bool operator < (const node &rhs) const {
		return t < rhs.t;
	}
} cur[MAXN];
set<node> now;
int left(int x) {
	return *--se.lower_bound(x);
}
int right(int x) {
	return *se.upper_bound(x);
}
ld calc(int x, int y) { // x < y
	if(v[x] <= v[y] + eps) return 2e20;
	return 1.0 * (a[y] - a[x]) / (v[x] - v[y]);
}
void ins(int x) {
	if(x == 0 || x == n + 1) return ;
	now.erase(cur[x]);
	int le = left(x), ri = right(x);
	ld t1 = calc(le, x), t2 = calc(x, ri);
	if(t1 < t2) cur[x] = node {le, x, t1};
	else cur[x] = node {x, ri, t2};
	now.insert(cur[x]);
}
void ers(int x) {
	vis[x] = 1;
	se.erase(x);
	now.erase(cur[x]);
}
int main() {
	read(n);
	rep(i, 1, n) read(a[i], v[i]);
	rep(i, 1, n) se.insert(i);
	se.insert(0), se.insert(n+1);
	a[0] = -1e10, v[0] = -1e10;
	a[n+1] = 1e10, v[n+1] = 1e10;
	rep(i, 1, n) ins(i);
	while(!now.empty()) {
		node c = *now.begin();
		now.erase(now.begin());
		// cerr << c.x << ' ' << c.y << ' ' << c.t << endl;
		if(c.t > 2e18) break;
		// if(vis[c.x] || vis[c.y]) {
		// 	assert(0);
		// 	if(!vis[c.y]) ins(c.y);
		// 	if(!vis[c.x]) ins(c.x);
		// 	continue;
		// }
		ers(c.x), ers(c.y);
		ins(left(c.x)), ins(right(c.y));
	}
	se.erase(0), se.erase(n + 1);
	cout << se.size() << endl;
	for(int x: se) cout << x << ' ';
	cout << endl;
	return 0;
}