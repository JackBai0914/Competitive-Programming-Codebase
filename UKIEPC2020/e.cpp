#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int MOD = 1000000007; 
const ll INF = 1e18;
const ld eps = 1e-8;

int h, w;
struct node {
	int val, x, y;
} nd[1000010];
int mp[550][550];
bool ord (const node &x, const node &y) {
	return x.val > y.val;
}

int lim = 0;
int ans = 0;
int vis[550][550];
bool dfs (int x, int y, int rd) {
	if (x < 0 || x >= h || y < 0 || y >= w)
		return false;
	if (mp[x][y] < lim)
		return false;
	if (vis[x][y] != -1) {
		if (vis[x][y] != rd)
			return true;
		else
			return false;
	}
	vis[x][y] = rd;
	bool ret = 0;
	ret |= dfs (x - 1, y, rd);
	ret |= dfs (x + 1, y, rd);
	ret |= dfs (x, y - 1, rd);
	ret |= dfs (x, y + 1, rd);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> h >> w;
	for (int i = 0; i < h; i ++)
		for (int j = 0; j < w; j ++) {
			cin >> nd[i * w + j].val;
			nd[i * w + j].x = i;
			nd[i * w + j].y = j;
			mp[i][j] = nd[i * w + j].val;
		}
	memset(vis, -1, sizeof(vis));
	sort(nd, nd + h * w, ord);
	int fans = 0;
	for (int t = 0; t < h * w; t ++) {
		lim = nd[t].val;
		if (lim <= 1)
			continue;
		bool find = dfs (nd[t].x, nd[t].y, t + 1);
		// cerr << "find: " << find << " " << nd[t].x << " " << nd[t].y << " " << lim << endl;
		fans += (!find);
	}
	cout << fans << endl;
    return 0;
}