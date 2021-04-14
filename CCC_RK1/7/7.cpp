/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-30 13:46:59
* @description: 
* /Users/jackbai/Desktop/CCC/1/1.cpp 
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
typedef pair <ll, ll> pii;
const int MOD = 1000000007; 
const ll INF = 1e18;
const ld eps = 1e-8;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

ll mxp, mxb, mxt;
ll n, h, m;
ll a[10010];

ll num[10010][10010], sum[10010];
ll use[10010][10010];

int hm[10010];
int inss[10010][10010][5], ins[10010][5];

ld rdd (ld x) {return ceil(x - eps);}


vector <pii> res;
vector <pii> v;

int main() {
	srand(time(0));
	cerr << "rand: " << rand() << endl;
	cin >> mxp >> mxb >> mxt;
	cin >> n;

	for (int i = 0; i < n; i ++)
		cin >> a[i];

	cin >> h;
	cout << h << endl;
	for (int hh = 0; hh < h; hh ++) {
		cin >> m;
		for (int ii = 0; ii < m; ii ++)  {
			for (int j = 0; j < 4; j ++)
				cin >> inss[hh][ii][j];
			inss[hh][ii][4] = hh;
		}
	}

	int rtt[100010];
	for (int i = 0; i < h; i ++)
		rtt[i] = i;
	random_shuffle(rtt, rtt + h);

	for (int hh = 0; hh < h; hh ++) {
		cout << rtt[hh] + 1 << endl;
		cout << m << endl;
		for (int ii = 0; ii < m; ii ++)
			for (int j = 0; j <= 4; j ++)
				ins[ii][j] = inss[rtt[hh]][ii][j];
		
		int rt[100010];
		for (int i = 0; i < m; i ++)
			rt[i] = i;
		random_shuffle(rt, rt + m);
		
		for (int i = 0; i < m; i ++)
			for (int j = 0; j < 4; j ++)
				swap (ins[i][j], ins[rt[i]][j]);

		for (int ii = 0; ii < m; ii ++) {
			
			v.resize(0);
			res.resize(0);

			ll id, pow, st, ed, hs;
			id = ins[ii][0], pow = ins[ii][1], st = ins[ii][2], ed = ins[ii][3], hs = ins[ii][4];
			for (int j = st; j <= ed; j ++) {
				if (use[hs][j] == mxt)
					continue ;
				if (num[hs][j] == mxp)
					continue ;
				ld pr = a[j] * (1 + (ld)sum[j] / mxp);
				v.push_back(MP(rdd(pr), j));
			}
			sort(v.begin(), v.end());

			for (int i = 0; i < v.size() && pow != 0; i ++) {
				int ti = v[i].S;
				if (use[hs][ti] == mxt)
					continue ;
				use[hs][ti] ++;
				int cando = min(pow, mxp - num[hs][ti]);
				num[hs][ti] += cando;
				sum[ti] += cando;
				if (cando)
					res.push_back(MP(ti, cando));
				pow -= cando;
			}
			if (pow != 0) {
				cerr << "fucked up" << " " << ii << endl;
				exit(0);
			}
			sort(res.begin(), res.end());
			cout << id << " ";
			for (int i = 0; i < res.size(); i ++)
				cout << res[i].F << " " << res[i].S << " ";
			cout << endl;
		}
	}
	cerr << "done " << endl;

    return 0;
}