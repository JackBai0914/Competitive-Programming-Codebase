/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-11 23:26:32
* @description: 
* /Users/jackbai/Desktop/OI/October_Challenge_Codechef/VILLNET.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv VILLNET.cpp
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

const int mx = 5;

pii turn (pii o) {int r = o.S/abs(o.S);	return MP (r*o.F, r*o.S);}
pii L (pii o) {return MP(o.F - o.S * 2, o.S);}
pii R (pii o) {return MP(o.F + o.S * 2, o.S);}
pii D (pii o) {return turn(MP(o.F, o.S - o.F * 2));}
pii U (pii o) {return turn(MP(o.F, o.S + o.F * 2));}



int main() {
	for (int x = -mx; x <= mx; x ++)
		for (int y = 0; y <= mx; y ++) {
			cerr << "edges of " << x << " " << y << ":";
			pii o = MP(x, y);
			cerr << "( " << L(o).F << ", " << L(o).S << "), ";
			cerr << "( " << R(o).F << ", " << R(o).S << "), ";
			cerr << "( " << D(o).F << ", " << D(o).S << "), ";
			cerr << "( " << U(o).F << ", " << U(o).S << ")";
			cerr << endl;
		}

    return 0;
}