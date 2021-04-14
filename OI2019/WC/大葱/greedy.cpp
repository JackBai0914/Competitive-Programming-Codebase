#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <vector>
#define TIME (double)clock()/CLOCKS_PER_SEC
#define MP make_pair
#define F first
#define S second
using namespace std;
typedef long double ld;
const int mx = 2020;
int n, m;
int v[mx], c[mx], val[mx][mx];
int put[mx], load[mx];
vector <int> inside[mx];
int put2[mx], load2[mx];

const ld Tmx = 1e7, Tmn = 1e-7, dt = 0.999995;

int cans = 0, fans = 0;
int rec[mx];

pair <double, int> st[mx];

ld Rand() {return rand() / RAND_MAX;}

int main() {
	srand(time(0));
	ios::sync_with_stdio(false);
	const string name = "drawer";
	
	for (int TT = 4; TT <= 10; TT ++) {
		ld INI = TIME;
		cerr << "Do " << TT << endl;
		stringstream is, os;
		is << name << TT << ".in";
		os << name << TT << ".out";
	freopen(is.str().c_str(), "r", stdin);
	freopen(os.str().c_str(), "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)	cin >> v[i];
	for (int j = 1; j <= m; j ++)	cin >> c[j];
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			cin >> val[i][j];
	
	for (int T3 = 1; T3 <= 3; T3 ++) {

	fans = cans = 0;
	memset(put, 0, sizeof put);
	memset(load, 0, sizeof load);
	memset(rec, 0, sizeof rec);
	for (int i = 0; i < mx; i ++)	inside[i].resize(0);
	
	c[0] = 2e9;
	for (int i = 1; i <= n; i ++) {
		int fate;
		do {
			fate = rand() % (m + 1);
		} while (load[fate] + v[i] > c[fate]);
		load[fate] += v[i];
		put[i] = fate;
		inside[fate].push_back(i);
		cans += val[i][fate];
	}
	
	
	vector <int> cur;
	for (ld T = Tmx; T >= Tmn; T *= dt) {
		int TP = rand() % 3;
		int pans = 0;
		if (TP == 0) {
			int a = rand() % (m + 1), b = rand() % (m + 1);
			if (a == b || inside[a].size() == 0 || inside[b].size() == 0)	continue ;
			// cerr << "IN " << inside[a].size() << " " << inside[b].size() << " " << load[a] << " " << load[b] << " " << a << " " << b << endl;
			int aaa = rand() % inside[a].size();
			int bbb = rand() % inside[b].size();
			int aa = inside[a][aaa];
			int bb = inside[b][bbb];
			// cerr << "OUT " << endl;
			if (load[a] + v[bb] - v[aa] > c[a] || load[b] + v[aa] - v[bb] > c[b])	continue ;
			pans = val[aa][b] + val[bb][a] - val[aa][a] - val[bb][b];
			if (pans > 0 || exp(pans / T) >= Rand()) {
				cans += pans;
				
				swap(inside[a][aaa], inside[b][bbb]);
				put[aa] = b;
				put[bb] = a;
				load[a] += v[bb] - v[aa];
				load[b] += v[aa] - v[bb];

				if (cans > fans) {
					cerr << "update2 : " << cans << " " << T << endl;
					fans = cans;
					for (int i = 1; i <= n; i ++)
						rec[i] = put[i];
				}
			}

			continue ;
		}
		if (TP == 1) {
			int a = rand() % (m + 1), b = rand() % (m + 1);
			if (a == b || inside[a].size() == 0)	continue ;
			// cerr << "IN " << inside[a].size() << " " << inside[b].size() << " " << load[a] << " " << load[b] << " " << a << " " << b << endl;
			int aaa = rand() % inside[a].size();
			int aa = inside[a][aaa];
			if (load[b] + v[aa] > c[b])	continue ;
			pans = val[aa][b] - val[aa][a];
			if (pans > 0 || exp(pans / T) >= Rand()) {
				cans += pans;
				put[aa] = b;
				load[a] -= v[aa];
				load[b] += v[aa];
				for (int i = aaa; i < inside[a].size() - 1; i ++)
					inside[a][i] = inside[a][i + 1];
				inside[a].pop_back();
				inside[b].push_back(aa);
				if (cans > fans) {
					cerr << "update3 : " << cans << " " << T << endl;
					fans = cans;
					for (int i = 1; i <= n; i ++)
						rec[i] = put[i];
				}
			}

			continue ;
		}
		int a = rand() % (m + 1), b = rand() % (m + 1);
		if (a == b || load[a] + load[b] == 0)	continue ;
		// cerr << "here : " << endl;
		
		cur.resize(0);
		load2[a] = load[a];
		load2[b] = load[b];
		for (int i = inside[a].size() / 2; i < inside[a].size(); i ++)	pans -= val[inside[a][i]][a], load2[a] -= v[inside[a][i]], cur.push_back(inside[a][i]);
		for (int i = inside[b].size() / 2; i < inside[b].size(); i ++)	pans -= val[inside[b][i]][b], load2[b] -= v[inside[b][i]], cur.push_back(inside[b][i]);
		// cerr << "pre " << a << " " << b << " " << pans << endl;
		for (int i = 0; i < cur.size(); i ++)
			st[i] = MP(-(double)(val[cur[i]][a] + val[cur[i]][b]) / v[cur[i]], cur[i]);
		sort(st, st + cur.size());
		for (int i = 0; i < cur.size(); i ++)
			cur[i] = st[i].S;
		
		for (int i = 0; i < cur.size(); i ++) {
			int x = cur[i];
			if (v[x] + load2[a] <= c[a] && (val[x][a] >= val[x][b] || v[x] + load2[b] > c[b]))	put2[x] = a, load2[a] += v[x], pans += val[x][a];
			else if (v[x] + load2[b] <= c[b] && (val[x][a] < val[x][b] || v[x] + load2[a] > c[a]))	put2[x] = b, load2[b] += v[x], pans += val[x][b];
		}
		if (pans > 0 || exp(pans / T) >= Rand()) {
			cans += pans;
			inside[a].resize(inside[a].size() / 2);
			inside[b].resize(inside[b].size() / 2);
			load[a] = load2[a];
			load[b] = load2[b];
			// cerr << "aft " << pans << " " << load[a] << " " << load[b] << endl;

			for (int i = 0; i < cur.size(); i ++) {
				int x = cur[i];
				put[x] = put2[x];
				inside[put[x]].push_back(x);
			}
			if (cans > fans) {
				cerr << "update1 : " << cans << " " << T << endl;
				fans = cans;
				for (int i = 1; i <= n; i ++) {
					rec[i] = put[i];
					// cerr << rec[i] << " ";
				}
				// cerr << endl;
			}
		}
	}

	}

	for (int i = 1; i <= n; i ++)
		cout << rec[i] << endl;
	for (int i = 1; i <= n; i ++)
		cerr << rec[i] << endl;
	cerr << "ans : " << fans << endl;

	}
	return 0;
}