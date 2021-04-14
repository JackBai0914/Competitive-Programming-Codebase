#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef pair <int, int> pii;

int n;
string s[1000010];
int ans[1000010];

struct Link {
	int v;
	int ne;
}l[1000010];
int st = 0;

void add (int x, int y) {
	// cerr << "add : " << x << " " << y << endl;
	st ++;
	l[st].v = y;
	l[st].ne = l[x].ne;
	l[x].ne = st;
}



ll fans = 0;

vector <int> tool;
int pt = 0;

void iterate () {
	// cerr << "iterate " << st << endl;
	tool.resize(0);
	if (st <= 2) {
		tool.push_back(1);
		pt = 0;
		return ;
	}
	int iter = 1;
	while (l[iter].ne != -1) {
		iter = l[iter].ne;
		if (l[iter].ne != -1)
			tool.push_back(iter);
	}
	// cerr << "toolsize: " << tool.size() << endl;
	pt = 0;
}

void dfs (int L, int rub, vector <int> cand) {
	vector <int> hp;
	vector <int> v[30];
	vector <int> blank;
	int rub2 = rub;
	
	for (int j = 0; j < cand.size(); j ++) {
		// cerr << l << " : " << s[cand[j]] << " " << s[cand[j]].size() << " :: " << s[cand[j]][l] - 'a' << endl;
		if (s[cand[j]].size() <= L) {
			blank.push_back (cand[j]);
			// cerr << l << "inp bl : " << cand[j] << endl;
		}
		else
			v[s[cand[j]][L] - 'a'].push_back(cand[j]);
	}
	
	int mx = 0, id = -1;
	for (int j = 0; j < 29; j ++) {
		// cerr << "num " << j << " : " << v[j].size() << " " << mx << endl;
		if ((int)v[j].size() > mx) {
			// cerr << "in there " << endl;
			mx = (int)v[j].size();
			id = j;
		}
		// cerr << "pres: " << mx << " " << id << endl;
		// mx = max (mx, (int)v[j].size());
		// cerr << "pres2: " << mx << " " << id << endl;
	}
	// cerr << "res: " << mx << " " << id << endl;
	int ess = mx;
	for (int j = 0; j < cand.size(); j ++) {
		if (s[cand[j]].size() >= L && s[cand[j]][L] - 'a' == id)
			hp.push_back(cand[j]);
		else
			rub2 ++;
	}

	if (rub2 >= ess - 1) {
		// cerr << "cur : " << l << " : " << rub2 << " " << ess << " , " << mx << " " << id << endl;
		for (int i = 0; i < hp.size(); i ++)
			add (st, hp[i]);
		iterate();
		for (int i = 0; i < 30; i ++) {
			if (i == id)
				continue ;
			for (int j = 0; j < v[i].size(); j ++) {
				int tg = v[i][j];
				add (tool[pt], tg);
				pt ++;
				if (pt == tool.size()) {
					if (v[i].size() == ess && j != v[i].size() - 1) {
						j ++;
						tg = v[i][j];
						add (l[st].ne, tg);
					}
					iterate();
				}
			}	
		}
			for (int j = 0; j < blank.size(); j ++) {
				int tg = blank[j];
				// cerr << "bl: " << tg << endl;
				add (tool[pt], tg);
				pt ++;
				if (pt == tool.size())
					iterate();
			}	
		return ;
	}
	dfs (L + 1, rub2, hp);
	for (int i = 0; i < 30; i ++) {
		if (i == id)
			continue ;
		for (int j = 0; j < v[i].size(); j ++) {
			int tg = v[i][j];
			add (tool[pt], tg);
			pt ++;
			if (pt == tool.size()) {
				if (v[i].size() == mx && j != v[i].size() - 1) {
					j ++;
					tg = v[i][j];
					add (l[st].ne, tg);
				}
				iterate();
			}
		}	
	}
		for (int j = 0; j < blank.size(); j ++) {
			int tg = blank[j];
			// cerr << "bl2: " << tg << endl;

			add (tool[pt], tg);
			pt ++;
			if (pt == tool.size())
				iterate();
		}	

}

int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);

	l[++ st].v = 0;
	l[st].ne = -1;

	cin >> n;
	vector <int> cand;
	for (int i = 1; i <= n; i ++) {
		cin >> s[i];
		cand.push_back(i);
	}
	dfs (0, 0, cand);

	int iter = l[1].ne;
	while (iter != -1) {
		cout << s[l[iter].v] << '\n';
		// cout << l[iter].v << " : " << s[l[iter].v] << endl;
		iter = l[iter].ne;
	}

	return 0;
}