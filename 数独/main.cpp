#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef pair <int, int> pii;
typedef pair <pii, pii> Ord;
typedef pair <pii, int> Ban;

Ord ord[22] = {
MP(MP(1,8),MP(1,7)), MP(MP(1,7),MP(1,6)),
MP(MP(3,7),MP(2,7)), 
MP(MP(5,8),MP(6,8)), MP(MP(6,8),MP(7,8)), MP(MP(7,8),MP(8,8)),
MP(MP(8,7),MP(8,6)), MP(MP(8,6),MP(7,6)), MP(MP(7,6),MP(6,6)), MP(MP(6,6),MP(5,6)), 
MP(MP(7,3),MP(6,3)), MP(MP(6,3),MP(5,3)), MP(MP(5,3),MP(4,3)), 
MP(MP(4,5),MP(5,4)), MP(MP(5,4),MP(6,5)), MP(MP(6,5),MP(7,5)), 
MP(MP(6,0),MP(5,0)), MP(MP(5,0),MP(4,0)), MP(MP(4,0),MP(3,0)), MP(MP(3,0),MP(3,1)), MP(MP(3,1),MP(4,2)), MP(MP(4,2),MP(5,1))
};
// Ban ban[22] = {
// MP(MP(6,0),4),
// MP(MP(6,0),5),
// MP(MP(6,0),6),
// MP(MP(6,0),7),
// MP(MP(6,0),8),
// MP(MP(6,0),9),
// MP(MP(5,0),1),
// MP(MP(5,0),5), 
// MP(MP(5,0),6), 
// MP(MP(5,0),7), 
// MP(MP(5,0),8), 
// MP(MP(5,0),9), 
// MP(MP(4,0),6), 
// MP(MP(4,0),7), 
// MP(MP(4,0),8), 
// MP(MP(4,0),9), 
// // MP(MP(,),), 
// // MP(MP(,),), 
// }

int calc_b(int r, int c) {return r/3*3+c/3;}
struct Game {
	int num, mp[9][9]; //1-9: filled, 0:empty

	int cand[9][9][10], adj[9][9][10]; //potential candidate
	vector <pii> b[9], r[9], c[9];
	Game () {
		num = 0;
		memset (mp, 0, sizeof mp);
		for (int i = 0; i < 9; i ++)
			for (int j = 0; j < 9; j ++) {
				for (int v = 0; v <= 9; v ++) {
					adj[i][j][v] = 0;
					cand[i][j][v] = true;
				}
				r[i].push_back(MP(i, j));
				c[j].push_back(MP(i, j));
				b[calc_b(i, j)].push_back(MP(i, j));
			}
	}
	void outp() {
		// cout << "///begin" << endl;
		cout << "the condition of the board: " << endl;
		for (int i = 0; i < 9; i ++) {
			for (int j = 0; j < 9; j ++)
				cout << mp[i][j];
			cout << endl;
		}
		cout << "the candidates of the board: " << endl;
		for (int i = 0; i < 9; i ++) {
			for (int j = 0; j < 9; j ++) {
				int cand_num = 0;
				for (int k = 1; k <= 9; k ++)
					cand_num += cand[i][j][k];
				cout << cand_num;
			}
			cout << endl;
		}
		// cout << "///end" << endl;
	}

	void calc_cand (pii p) {
		int B = calc_b(p.F, p.S);
		for (int v = 1; v <= 9; v ++) {
			cand[p.F][p.S][v] = true;
			adj[p.F][p.S][v] = 0;
		}
		for (int i = 0; i < b[B].size(); i ++)			if (b[B][i] != p)	cand[p.F][p.S][mp[b[B][i].F][b[B][i].S]] = false, adj[p.F][p.S][mp[b[B][i].F][b[B][i].S]]++;
		for (int i = 0; i < r[p.F].size(); i ++)		if (r[p.F][i] != p)	cand[p.F][p.S][mp[r[p.F][i].F][r[p.F][i].S]] = false, adj[p.F][p.S][mp[r[p.F][i].F][r[p.F][i].S]]++;
		for (int i = 0; i < c[p.S].size(); i ++)		if (c[p.S][i] != p)	cand[p.F][p.S][mp[c[p.S][i].F][c[p.S][i].S]] = false, adj[p.F][p.S][mp[c[p.S][i].F][c[p.S][i].S]]++;
	}

	void insert (pii p, int v) {
		(v? num++:num--);
		int B = calc_b(p.F, p.S);
		for (int i = 0; i < b[B].size(); i ++)		if (b[B][i] != p)	cand[b[B][i].F][b[B][i].S][mp[p.F][p.S]] = ((-- adj[b[B][i].F][b[B][i].S][mp[p.F][p.S]]) == 0);
		for (int i = 0; i < r[p.F].size(); i ++)	if (r[p.F][i] != p)	cand[r[p.F][i].F][r[p.F][i].S][mp[p.F][p.S]] = ((-- adj[r[p.F][i].F][r[p.F][i].S][mp[p.F][p.S]]) == 0);
		for (int i = 0; i < c[p.S].size(); i ++)	if (c[p.S][i] != p)	cand[c[p.S][i].F][c[p.S][i].S][mp[p.F][p.S]] = ((-- adj[c[p.S][i].F][c[p.S][i].S][mp[p.F][p.S]]) == 0);
		mp[p.F][p.S] = v;
		for (int i = 0; i < b[B].size(); i ++)		if (b[B][i] != p)	cand[b[B][i].F][b[B][i].S][mp[p.F][p.S]] = false, adj[b[B][i].F][b[B][i].S][mp[p.F][p.S]] ++;
		for (int i = 0; i < r[p.F].size(); i ++)	if (r[p.F][i] != p)	cand[r[p.F][i].F][r[p.F][i].S][mp[p.F][p.S]] = false, adj[r[p.F][i].F][r[p.F][i].S][mp[p.F][p.S]] ++;
		for (int i = 0; i < c[p.S].size(); i ++)	if (c[p.S][i] != p)	cand[c[p.S][i].F][c[p.S][i].S][mp[p.F][p.S]] = false, adj[c[p.S][i].F][c[p.S][i].S][mp[p.F][p.S]] ++;
		if (v == 0)
			calc_cand(p);
	}
	// void eliminate_cand () {
	// 	for (int v = 1; v <= 9; v ++) {
	// 		for (int i = 0; i < 9; i ++) { //blocks
	// 			int cnt = 0;	pii p;
	// 			for (int j = 0; j < b[i].size(); j ++) {
	// 				pii cur = b[i][j];
	// 				if (cand[cur.F][cur.S][v] == true)
	// 					cnt ++, p = cur;
	// 			}
	// 			if (cnt == 1)
	// 				for (int vv = 0; vv <= 9; vv ++)
	// 					if (vv != v)
	// 						cand[p.F][p.S][vv] = false;
	// 		}
	// 		for (int i = 0; i < 9; i ++) { //columns
	// 			int cnt = 0;	pii p;
	// 			for (int j = 0; j < c[i].size(); j ++) {
	// 				pii cur = c[i][j];
	// 				if (cand[cur.F][cur.S][v] == true)
	// 					cnt ++, p = cur;
	// 			}
	// 			if (cnt == 1)
	// 				for (int vv = 0; vv <= 9; vv ++)
	// 					if (vv != v)
	// 						cand[p.F][p.S][vv] = false;
	// 		}
	// 		for (int i = 0; i < 9; i ++) { //rows
	// 			int cnt = 0;	pii p;
	// 			for (int j = 0; j < r[i].size(); j ++) {
	// 				pii cur = r[i][j];
	// 				if (cand[cur.F][cur.S][v] == true)
	// 					cnt ++, p = cur;
	// 			}
	// 			if (cnt == 1)
	// 				for (int vv = 0; vv <= 9; vv ++)
	// 					if (vv != v)
	// 						cand[p.F][p.S][vv] = false;
	// 		}
	// 	}
	// }
	bool if_end() {
		for (int i = 0; i < 9; i ++)
			for (int j = 0; j < 9; j ++) {
				if (mp[i][j])
					continue ;
				int cand_num = 0;
				for (int v = 1; v <= 9; v ++)
					cand_num += cand[i][j][v];
				if (!cand_num)
					return true;
			}
		// for (int i = 0; i < 22; i ++) {
		// 	pii s = ord[i].F, t = ord[i].S;
		// 	if (mp[s.F][s.S] && mp[t.F][t.S])
		// 		if (mp[s.F][s.S] >= mp[t.F][t.S]) {
		// 			// cout << "got this wrong (" << s.F << "," << s.S << ")->(" << t.F << "," << t.S << ")" << endl;
		// 			return true;
		// 		}
		// }
		return false;
	}
	pii find_enum () {
		// eliminate_cand();
		int mn = 10;	pii p;
		for (int i = 0; i < 9; i ++)
			for (int j = 0; j < 9; j ++) {
				if (mp[i][j])
					continue ;
				int cand_num = 0;
				for (int v = 1; v <= 9; v ++)
					cand_num += cand[i][j][v];
				if (cand_num < mn) {
					mn = cand_num;
					p = MP(i, j);
				}
			}
		// cout << "you can enum this " << p.F << " " << p.S << " WITH " << mn << "possibilities " << endl;
		return p;
	}

	void inp(vector<string> s) {
		for (int i = 0; i < 9; i ++)
			for (int j = 0; j < 9; j ++) {
				char c = s[i][j];
				if (c != '0')
					insert (MP(i, j), c - '0');
			}
	}
	
};

Game g;

int dcnt = 0;
void dfs () {
	int cdcnt = ++ dcnt;
	// cout << "#" << cdcnt <<  " begins" << endl;
	// g.outp();
	if (g.if_end()) {
		// cout << "this board is illigal " << endl;
		return ;
	}
	if (g.num == 81) {
		g.outp();
		exit(0);
	}
	pii ne = g.find_enum();
	vector <int> cd;
	for (int v = 1; v <= 9; v ++)
		if (g.cand[ne.F][ne.S][v])
			cd.push_back (v);
	for (int i = 0; i < cd.size(); i ++) {
		int v = cd[i];
		// cout << "#" << cdcnt << " enum " << v << endl;
		g.insert (ne, v);
		dfs ();
		g.insert (ne, 0);
	}
	// cout << "#" << cdcnt <<  " ends" << endl;
}


int main() {
	// for (int i = 0; i < 9; i ++) {
	// 	cout << "the grids for block " << i << " : ";
	// 	for (int j = 0; j < g.b[i].size(); j ++)
	// 		cout << "(" << g.b[i][j].F << "," << g.b[i][j].S << ") ";
	// 	cout << endl;
	// }
	// for (int i = 0; i < 9; i ++) {
	// 	cout << "the grids for row " << i << " : ";
	// 	for (int j = 0; j < g.r[i].size(); j ++)
	// 		cout << "(" << g.r[i][j].F << "," << g.r[i][j].S << ") ";
	// 	cout << endl;
	// }
	// for (int i = 0; i < 9; i ++) {
	// 	cout << "the grids for column " << i << " : ";
	// 	for (int j = 0; j < g.c[i].size(); j ++)
	// 		cout << "(" << g.c[i][j].F << "," << g.c[i][j].S << ") ";
	// 	cout << endl;
	// }
	vector <string> s;
	string ins;
	while (cin >> ins)
		s.push_back(ins);
	g.inp(s);
	dfs ();
	cerr << "end dfs " << endl;
	return 0;
}