/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-11-17 14:27:38
* @description: 
* /Users/jackbai/Desktop/OI/CF684/1.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv 1.cpp
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
const int MOD = 1000000007; 
const ll INF = 1e18;
const ld eps = 1e-8;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl
struct MV {
	int x, y, i, j;
	MV(){}
	MV(int xx, int yy, int ii, int jj) {x = xx, y = yy, i = ii, j = jj;}
} mv;
int n, m, ans = 0;
int mp[1010][1010];
vector <MV> rec[10010];
int vis[10010];
vector <MV> fans;

void output (int st, int ed, int x, int y) {
	for (int i1 = st; i1 <= st + 1; i1 ++)
		for (int j1 = ed; j1 <= ed + 1; j1 ++)
			if (i1 != x || j1 != y)
				cout << i1 + 1 << ' ' << j1 + 1 << ' ';
	cout << '\n';
}

void solve (int x, int y, int msk) {
	// cerr << "find solution for " << msk << " : " << rec[msk].size() << endl;
	ans += rec[msk].size();
	for (int i = 0; i < rec[msk].size(); i++) {
		MV mv = rec[msk][i];
		fans.push_back(MV(x + mv.x, y + mv.y, x + mv.i, y + mv.j));
	}
}


void order (int msk) {
	cout << msk << endl;
	for (int i = 0; i <= 2; i ++) {
		for (int j = 0; j <= 2; j ++) {
			cout << msk % 2 << " ";
			msk /= 2;
		}
		cout << endl;
	}
}



int main() {
	queue <int> q;
	q.push(0);
	vis[0] = 1;
	int num = 0;
	while (!q.empty()) {
		num ++;
		int v[3][3], vv[3][3];
		int msk = q.front(), mmsk = q.front();
		// order(msk);
		// cout << "ans: " << rec[msk].size() << endl << endl;
		q.pop();
		for (int i = 0; i <= 2; i ++)
			for (int j = 0; j <= 2; j ++)
				v[i][j] = msk % 2, msk /= 2;
		for (int dx = 0; dx <= 1; dx ++)
		for (int dy = 0; dy <= 1; dy ++) {
		for (int i = 0; i <= 1; i ++)
			for (int j = 0; j <= 1; j ++) {
				for (int ii = 0; ii <= 2; ii ++)
					for (int jj = 0; jj <= 2; jj ++)
						vv[ii][jj] = v[ii][jj];

				for (int i1 = 0; i1 <= 1; i1 ++)
					for (int j1 = 0; j1 <= 1; j1 ++)
						if (i1 != i || j1 != j)
							vv[i1 + dx][j1 + dy] ^= 1;
				int msk2 = 0;
				for (int ii = 0; ii <= 2; ii ++)
					for (int jj = 0; jj <= 2; jj ++)
						msk2 += (1 << (ii * 3 + jj)) * vv[ii][jj];
				if (!vis[msk2]) {
					vis[msk2] = 1;
					rec[msk2] = rec[mmsk];
					rec[msk2].push_back(MV(dx, dy, dx + i, dy + j));
					q.push(msk2);
				}
			}
		}

	}
	// cerr << "num : " << num << endl;
	int t;
	cin >> t;
	while (t --) {
		ans = 0;
		fans.resize(0);
		cin >> n >> m;
		F0R(i, n)
			F0R(j, m) {
				char c;
				cin >> c;
				mp[i][j] = c - '0';
			}
		for (int i = 0; i + 1 < n; i += 2)
			for (int j = 0; j + 1 < m; j += 2) {
				int msk = 0, ei = i + 1, ej = j + 1;
				if (ei == n - 2)	ei ++;
				if (ej == m - 2)	ej ++;
				for (int ii = i; ii <= ei; ii ++)
					for (int jj = j; jj <= ej; jj ++)
						msk += (1 << ((ii - i) * 3 + jj - j)) * mp[ii][jj];
				solve(i, j, msk);
			}
		cout << ans << endl;
		for (int i = 0; i < fans.size(); i ++)
			output(fans[i].x, fans[i].y, fans[i].i, fans[i].j);
	}

    return 0;
}