#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

int n, m, s, t, fans;
int p[220];
vector <int> fr[220], to[220];
void add (int a, int b) {
	fr[b].push_back(a);
	to[a].push_back(b);
}

int a[220];


namespace Tt {
	int sq[220];
	bool mp[220][220], chose[220];
	void init () {
		memset(mp, 0, sizeof mp);
		for (int i = 1; i <= n; i ++)
			mp[i][i] = 1;
		memset(chose, 0, sizeof chose);
	}
	void add (int x) {
		chose[x] = 1;
		for (int i = 0; i < to[x].size(); i ++) {
			int s = to[x][i];
			if (!chose[s])
				continue ;
			for (int j = 1; j <= n; j ++)
				mp[x][j] |= mp[s][j];
		}
		for (int i = 0; i < fr[x].size(); i ++) {
			int p = fr[x][i];
			if (!chose[p])
				continue ;
			for (int j = 1; j <= n; j ++)
				mp[p][j] |= mp[x][j];
		}
	}
	int check_array () {
		init();
		for (int i = 1; i <= n; i ++) {
			// cerr << "add " << sq[i] << endl;
			add (sq[i]);
			if (mp[s][t] == 1 && mp[t][s] == 1)
				return i;
			// for (int j = 1; j <= n; j ++) {
			// 	for (int k = 1; k <= n; k ++)
			// 		cerr << mp[j][k] << " ";
			// 	cerr << endl;
			// }
		}
		// cerr << "end " << endl;
		return n + 1;
	}
	void process () {
		for (int i = 1; i <= n; i ++) {
			if (sq[i] == s)	swap (sq[i], sq[1]);
			if (sq[i] == t) swap (sq[i], sq[2]);
		}
		int pans = check_array ();
		for (int t = 1; t <= 100; t ++) {
			// cerr << "t : " << t << endl;
			int a = rand() % n + 1;
			int b = rand() % n + 1;
			if (a == b)
				continue ;
			if (a <= 2 || b <= 2)
				continue;
			// for (int i = 1; i <= n; i ++)
			// 	cerr << sq[i] << " ";
			// cerr << endl;
			swap (sq[a], sq[b]);

			int tans = check_array();
			if (tans < pans) {
				pans = tans;
				t = 0;
				continue ;
			}
			swap (sq[a], sq[b]);
		}
		fans = min (fans, pans);
	}

}




const int C = 2e7 / 2e4;

int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	srand (20010914);
	int T;
	cin >> T;
	while (T --) {
		cin >> n >> m >> s >> t;
		ld Given = 1.0/200*n;
		ld St = TIME;
		fans = n + 1;
		for (int i = 1; i <= n; i ++) {
			cin >> p[i];
			fr[i].resize(0);
			to[i].resize(0);
		}
		for (int a, b, i = 1; i <= m; i ++) {
			cin >> a >> b;
			add (a, b);
		}
		for (int i = 1; i <= n; i ++)
			Tt::sq[i] = i;	
		while (TIME - St < Given * 0.7) {
			random_shuffle(Tt::sq + 1, Tt::sq + n + 1);
			Tt::process ();
		}
		cout << fans << endl;
	}
	
	return 0;
}