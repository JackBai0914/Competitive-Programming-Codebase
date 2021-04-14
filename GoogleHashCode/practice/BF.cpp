/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-02-24 19:10:43
* @description: 
*  
* 
* @notes: 
* g++ -fsanitize=address -ftrapv -O2
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
const int mod = 1000000007; 
const ll oo = 1e18;
const ld eps = 1e-8;
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl
double limit = 100.0;

int m, n, n2, n3, n4, n_ing = 0;
map <string, int> ing;

struct P {
	vector <int> ing;
	int bel, id;
	void output () {
		cerr << "output pizza " << id << ", ing: ";
		for (int i = 0; i < ing.size(); i ++)
			cerr << ing[i] << " ";
		cerr << ".\n";
	}
}; vector <P> pizzas;

ll pans = 0;
struct T {
	int size, id, ni, fake;
	T () {}
	T (int s, int i) {size = s; id = i; ni = 0; fake = 0;}
	int value () {return ni * ni;}
	map <int, int> ing;
	vector <int> piz;
	void output () {
		cerr << "output team " << id << " : s = " << size << ", piz: ";
		for (int i = 0; i < piz.size(); i ++)
			cerr << piz[i] << " ";
		cerr << ", ing = " << ni << ".\n";
	}
	void add_piz(int id) {
		pans -= value() * (!fake);
		piz.push_back(id);
		for (int i = 0; i < pizzas[id].ing.size(); i ++)
			ni += (ing[pizzas[id].ing[i]] ++) == 0;
		pans += value() * (!fake);
	}
	void rem_piz(int id) {
		pans -= value() * (!fake);
		for (int i = 0; i < pizzas[id].ing.size(); i ++)
			ni -= (-- ing[pizzas[id].ing[i]]) == 0;
		for (int pi = 0; pi < piz.size(); pi ++)
			if (piz[pi] == id) {
				for (int i = pi; i < piz.size() - 1; i ++)
					piz[i] = piz[i + 1];
				piz.pop_back();
				break;
			}
		pans += value() * (!fake);
	}
	
}; vector <T> teams;

namespace Final {
	ll fans = 0;
	ll bd = 0;
	vector <T> fteams;
	void record() {
		if (pans <= fans)
			return ;
		if (pans > bd) {
			cerr << "UPD: " << pans << endl;
			bd = pans / 100 * 100 + 100;
		}
		fans = pans;
		fteams.resize(0);
		for (int i = 0; i < teams.size(); i ++)
			fteams.push_back(teams[i]);
	}
}

namespace Tools {
	void pre_shuffle () {
		random_shuffle(teams.begin(), teams.end());
	}
	void clear () {
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < teams[i].piz.size(); j ++)
				teams[i].rem_piz(teams[i].piz[j]);
			teams[i].piz.resize(0);
		}
	}
	void formal_output() {
		using namespace Final;
		int have = 0;
		for (int i = 0; i < n; i ++)
			if (fteams[i].ni)
				have ++;
		cout << have << endl;
		for (int i = 0; i < n; i ++)
			if (fteams[i].ni) {
				cout << fteams[i].size << ' ';
				for (int j = 0; j < fteams[i].piz.size(); j ++)
					cout << fteams[i].piz[j] << ' ';
				cout << endl;
			}
		cerr << "answer gained: " << fans << endl;
	}
	void input () {
		cin >> m >> n2 >> n3 >> n4;	n = n2 + n3 + n4;
		for (int c, i = 0; i < m; i ++ ) {
			P p;
			p.bel = -1;
			cin >> c;
			for (int j = 0; j < c; j ++) {
				string s;
				cin >> s;
				if (!ing[s])
					ing[s] = ++ n_ing;
				p.ing.push_back(ing[s]);
			}
			p.id = i;
			pizzas.push_back(p);
		}
		for (int i = 0; i < n4; i ++)	teams.push_back(T(4, n2 + n3 + i));
		for (int i = 0; i < n3; i ++)	teams.push_back(T(3, n2 + i));
		for (int i = 0; i < n2; i ++)	teams.push_back(T(2, i));
		// cerr << "finished input: " << TIME << endl;
		int pt[5] = {0, 0, n4 + n3, n4, 0};
		int cnt =0 ;
		cin >> cnt;
		for (int i = 0; i < cnt; i ++) {
			int num, x;
			cin >> num;
			for (int j = 0; j < num; j ++) {
				cin >> x;
				teams[pt[num]].add_piz(x);
			}
			pt[num] ++;
		}
	}
	void BF() {
		pre_shuffle();
		clear();

		vector <int> rt;
		for (int i = 0; i < m; i ++)
			rt.push_back(i);

		random_shuffle(rt.begin(), rt.end());
		int pter = 0;
		for (int i = 0; i < n; i ++) 
			if (m - pter >= teams[i].size){
				for (int j = pter; j < pter + teams[i].size; j ++)
					teams[i].add_piz(rt[j]);
				pter += teams[i].size;
			}
		Final::record();
	}
	void swap_two (int ta, int tb, int px, int py) {
		teams[ta].rem_piz(px);
		teams[tb].rem_piz(py);
		teams[ta].add_piz(py);
		teams[tb].add_piz(px);
	}
	int pred_swap_two (int ta, int tb, int px, int py) {
		T a = teams[ta], b = teams[tb];
		a.fake = b.fake = true;
		int dt = -a.value() - b.value();
		a.rem_piz(px);
		b.rem_piz(py);
		a.add_piz(py);
		b.add_piz(px);
		dt += a.value() + b.value();
		return dt;
	}
	void adjusting () {
		int ta, tb, ia, ib, px, py, dt;
		int cnt = 0;
		do {
			do {
				ta = rand() % n;
				tb = rand() % n;
			} while (ta == tb || teams[ta].piz.size() == 0 || teams[tb].piz.size() == 0);
			ia = rand() % teams[ta].size;
			ib = rand() % teams[tb].size;
			px = teams[ta].piz[ia];
			py = teams[tb].piz[ib];
			dt = pred_swap_two(ta, tb, px, py);
		} while (dt <= 0 && ((++cnt) % 100 || TIME < limit));
		if (dt <= 0)
			return ;
		ll cans = pans;
		swap_two(ta, tb, px, py);

		Final::record();
	}
	double Random () {return (double)rand()/RAND_MAX;}
	void SA () {
		const ld initT = 1e1, endT = 1e-20, dT = 0.99998;
		int cnt = 0;
		for (ld T = initT; T >= endT; T *= dT) {
			if ((++ cnt) % 100000 == 0)
				cerr << "T : " << T << endl;
			int ta, tb, ia, ib, px, py, dE;
			do {
				ta = rand() % n;
				tb = rand() % n;
			} while (ta == tb || teams[ta].piz.size() == 0 || teams[tb].piz.size() == 0);
			ia = rand() % teams[ta].size;
			ib = rand() % teams[tb].size;
			px = teams[ta].piz[ia];
			py = teams[tb].piz[ib];
			dE = pred_swap_two(ta, tb, px, py);
			if(dE > 0 || exp(dE/T) > Random()) {
				swap_two(ta, tb, px, py);
				Final::record();
			}
		}
	}
	void wrapUp() {
		// for (int i = 0; i < m; i ++)
		// 	pizzas[i].output();
		// for (int i = 0; i < n; i ++)
		// 	teams[i].output();
		formal_output();
	}
}using namespace Tools;

int main() {
	srand(time(0));
    ios::sync_with_stdio(false);
    input();
    Final::record();
    int cnt = 0;
    // BF();
    // SA(); 
    while (TIME < limit) {
    	adjusting();
    	cnt ++;
    }
    // cerr << "cnt : " << cnt << endl;
    wrapUp();
    return 0;
}