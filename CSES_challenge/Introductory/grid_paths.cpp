#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#define F first
#define S second
#define MP make_pair

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int size = 7;

vector <vector <char> > paths;

string inp;

bool vis[8][8];
vector <char> c;

int wo[8][8];

inline bool legal (int x, int y) {
	return 1 <= x && x <= size && 1 <= y && y <= size && !vis[x][y];
}
int wayout (int x, int y) {
	return legal(x + 1, y) + legal(x - 1, y)
		 + legal(x, y + 1) + legal(x, y - 1);
}

pii TG = MP(size, 1);

void dfs (pii p, int cnt) {
	// cerr << p.F << " " << p.S << " " << cnt << endl;
	if (cnt == size * size) {
		if (p == TG) {
			paths.push_back(c);
			// cerr << "added " << paths.size() << endl;
		}
		return ;
	}
	if (p == TG) {
		// cerr << "early arrive " << endl;
		return ;
	}
	if (wo[TG.F][TG.S] == 0)
		return ;

	int must = 0;
	pii tg;

	vis[p.F][p.S] = 1;
	if (legal(p.F + 1, p.S)) {
		wo[p.F + 1][p.S] --;
		if (wo[p.F + 1][p.S] == 1 && MP(p.F + 1, p.S) != TG)
			must ++, tg = MP(p.F + 1, p.S);
	} 
	if (legal(p.F - 1, p.S)) {
		wo[p.F - 1][p.S] --;
		if (wo[p.F - 1][p.S] == 1 && MP(p.F - 1, p.S) != TG)
			must ++, tg = MP(p.F - 1, p.S);
	} 
	if (legal(p.F, p.S + 1)) {
		wo[p.F][p.S + 1] --;
		if (wo[p.F][p.S + 1] == 1 && MP(p.F, p.S + 1) != TG)
			must ++, tg = MP(p.F, p.S + 1);
	} 
	if (legal(p.F, p.S - 1)) {
		wo[p.F][p.S - 1] --;
		if (wo[p.F][p.S - 1] == 1 && MP(p.F, p.S - 1) != TG)
			must ++, tg = MP(p.F, p.S - 1);
	} 

	// cerr << "must : " << must << " " << tg.F << " " << tg.S << endl;
	// for (int i = 1; i <= size; i ++) {
	// 	for (int j = 1; j <= size; j ++)
	// 		cerr << wo[i][j];
	// 	cerr << "  ";
	// 	for (int j = 1; j <= size; j ++)
	// 		cerr << vis[i][j];
	// 	cerr << endl;
	// }

	if (must > 1) {
		vis[p.F][p.S] = 0;
		if (legal(p.F + 1, p.S)) {
			wo[p.F + 1][p.S] ++;
		} 
		if (legal(p.F - 1, p.S)) {
			wo[p.F - 1][p.S] ++;
		} 
		if (legal(p.F, p.S + 1)) {
			wo[p.F][p.S + 1] ++;
		} 
		if (legal(p.F, p.S - 1)) {
			wo[p.F][p.S - 1] ++;
		} 
			return ;
	}

	if (legal(p.F + 1, p.S) && (!must || tg == MP(p.F + 1, p.S)) && (inp[cnt] == 'D' || inp[cnt] == '?')) {c.push_back('D');dfs (MP(p.F + 1, p.S), cnt + 1);c.pop_back();}
	if (legal(p.F - 1, p.S) && (!must || tg == MP(p.F - 1, p.S)) && (inp[cnt] == 'U' || inp[cnt] == '?')) {c.push_back('U');dfs (MP(p.F - 1, p.S), cnt + 1);c.pop_back();}
	if (legal(p.F, p.S + 1) && (!must || tg == MP(p.F, p.S + 1)) && (inp[cnt] == 'R' || inp[cnt] == '?')) {c.push_back('R');dfs (MP(p.F, p.S + 1), cnt + 1);c.pop_back();}
	if (legal(p.F, p.S - 1) && (!must || tg == MP(p.F, p.S - 1)) && (inp[cnt] == 'L' || inp[cnt] == '?')) {c.push_back('L');dfs (MP(p.F, p.S - 1), cnt + 1);c.pop_back();}
	
	vis[p.F][p.S] = 0;
	if (legal(p.F + 1, p.S)) {
		wo[p.F + 1][p.S] ++;
	} 
	if (legal(p.F - 1, p.S)) {
		wo[p.F - 1][p.S] ++;
	} 
	if (legal(p.F, p.S + 1)) {
		wo[p.F][p.S + 1] ++;
	} 
	if (legal(p.F, p.S - 1)) {
		wo[p.F][p.S - 1] ++;
	} 
		return ;
}

int main() {
	std::ios::sync_with_stdio(false);
	memset(wo, 0, sizeof wo);
	for (int i = 1; i <= size; i ++)
		for (int j = 1; j <= size; j ++) {
			wo[i][j] += legal(i + 1, j);
			wo[i][j] += legal(i - 1, j);
			wo[i][j] += legal(i, j + 1);
			wo[i][j] += legal(i, j - 1);
		}
	cin >> inp;
	inp = " " + inp;
	
	// cerr << "started " << endl;
	dfs (MP(1, 1), 1);
	// cerr << "ended " << endl;


	cout << paths.size() << endl;
	return 0;
}
