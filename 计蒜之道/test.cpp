#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound

#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int MOD = 1e9 + 7; // 998244353
const ll INF = 1e18;
const ld PI = acos((ld)-1);

typedef unsigned int uint;
const int MAXN = 1e6 + 10;
int n, m, q;
pii stone[MAXN], cur[MAXN];
int l[MAXN], r[MAXN], x[MAXN];
uint f[MAXN][64], fret[MAXN], fans = 0;
bool ordf (pii a, pii b) {return a.f < b.f;}
bool ords (pii a, pii b) {return a.s < b.s;}

namespace LinearBase {
	const int maxLen = 7;
	const int maxItem = 128;
	int num = 0, sp_val = 0, sp_xor = 0;
	int b[maxLen], val[maxLen];
	int base_val[maxItem];
	void init () {
		memset (b, 0, sizeof b);
		memset (val, 0, sizeof val);
		memset (base_val, 0, sizeof base_val);
		num = 0, sp_val = 0, sp_xor = 0;
	}
	void add (int x, int x_val) {
		int ori_x = x;
		for (int i = maxLen - 1; i >= 0 && x; i --)
			if (x >> i & 1) {
				if (!b[i]) {
					num ++;
					b[i] = x, val[i] = x_val;
					return ;
				}
				else
					x ^= b[i];
			}
		sp_xor ^= ori_x;
		sp_val += x_val;
	}

	void extract (int x) {
		for (int i = maxLen - 1; i >= 0; i --)
			if (x >> i & 1) {
				if (b[i])
					base_val[x] += val[i];
				else {
					base_val[x] = -1;
					return ;
				}
			}
	}
	void calc_val() {
		for (int i = 0; i < m; i ++)
			extract(i);
	}
} using namespace LinearBase;


int main() {
	ios::sync_with_stdio(false);
	// freopen("inp.in", "r", stdin);
	// freopen("outp.out", "w", stdout);
	cin >> n >> m >> q;
	for (int i = 0; i < n; i ++)
		cin >> stone[i].f >> stone[i].s;
	for (int i = 1; i <= q; i ++) {
		cin >> l[i] >> r[i] >> x[i];
		LinearBase::init();
		for (int j = l[i]; j <= r[i]; j ++)
			cur[j - l[i]] = stone[j];
		sort (cur, cur + r[i] - l[i] + 1, ords);
		for (int j = 0; j <= r[i] - l[i]; j ++)
			LinearBase::add(cur[j].f, cur[j].s);
		LinearBase::calc_val();
		for (int j = 0; j < m; j ++) {
			f[i][j] = sp_val + base_val[j ^ sp_xor];
			fret[i] += f[i][j] * (x[i] ^ j);
		}
		fans += (i ^ fret[i]);
	}
	cout << fans << endl;
	return 0;
}