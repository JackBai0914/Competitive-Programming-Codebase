#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;

int n, m;
struct onion {
	int v, bel;
} o[2020];
struct drawer {
	// vector <int> id;
	int v; 
} d[2020];
int prof[2020][2020];
int op (int O, int D, int C) {
	if (C == 1) {
		if (d[D].v < o[O].v)
			return -1;
		// d[D].id.push_back(O);
		d[D].v -= o[O].v;
		o[O].bel = D;
		return prof[O][D];
	}
	else {
		// for (int i = 0; i < d[D].id.size(); i ++)
		// 	if (d[D].id[i] == O) {
		// 		for (int j = i; j < d[D].id.size() - 1; j ++)
		// 			d[D].id[j] = d[D].id[j + 1];
		// 		d[D].id.pop_back();
		// 		break;
		// 	}
		d[D].v += o[O].v;
		o[O].bel = 0;
		return -prof[O][D];
	}
}

int cans = 0;
int fans = 0, fr[2020];

int rt[2020];
void random_put() {
	cans = 0;
	for (int i = 1; i <= n; i ++)
		rt[i] = i;
	random_shuffle(rt + 1, rt + n + 1);
	for (int i = 1; i <= n; i ++) {
		int bel = rand() % (m + 1), pr = -1;
		int x = rt[i];
		for (int j = 1; j <= m; j ++)
			if (d[j].v >= o[x].v) {
				if (prof[x][j] > pr) {
					pr = prof[x][j];
					bel = j;
				}
			}
		// while (d[bel].v < o[x].v)
		// 	bel = rand() % (m + 1);
		int pans = op (x, bel, 1);
		cans += pans;
	}
}

namespace ADJ {
	typedef long double ld;
	// ld Tmx = 1e9, Tmn = 1e-4, delta = 0.9999;
	ld Rand() {return (ld)rand()/RAND_MAX;}
	void main() {
		bool change = 0;
		do {
			change = 0;
			for (int i = 1; i <= n; i ++)
				for (int j = i + 1; j <= n; j ++) {
					int gap = o[i].v - o[j].v;
					int bi = o[i].bel, bj = o[j].bel;
					if (d[bi].v >= -gap && d[bj].v >= gap) {
						if (prof[i][bi] + prof[j][bj] < prof[i][bj] + prof[j][bi]) {
							cans += op (i, bi, -1);
							cans += op (j, bj, -1);
							cans += op (i, bj, 1);
							cans += op (j, bi, 1);
							change = 1;
							// cerr << "yeah!" << endl;
						}
					}
				}
		} while (change);
	}
}


int main() {
	srand(time(0));
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)	cin >> o[i].v;
	for (int i = 1; i <= m; i ++)	cin >> d[i].v;	d[0].v = 2e9;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			cin >> prof[i][j];

	while (TIME < 100) {
		random_put();
		ADJ::main();
		if (cans > fans) {
			fans = cans;
			for (int i = 1; i <= n; i ++)
				fr[i] = o[i].bel;
		}
	}
	for (int i = 1; i <= n; i ++)
		cout << fr[i] << endl;
	cerr << "exp: " << fans << endl;
	return 0;
}