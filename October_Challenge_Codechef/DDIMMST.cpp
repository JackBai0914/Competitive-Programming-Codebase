/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-11 22:00:22
* @description: 
* /Users/jackbai/Desktop/OI/October_Challenge_Codechef/DDIMMST.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv DDIMMST.cpp
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

struct node {
	int val, id, d[5];
	node () {memset(d, 0, sizeof(d));}
	node (int v, int idd) {memset(d, 0, sizeof(d));val = v, id = idd;}
};
bool operator > (const node x, const node y) {	return x.val > y.val;}
bool operator < (const node x, const node y) {	return x.val < y.val;}

int n, d;
node co[200020];
bool if_in[200020];

priority_queue <node> ins[2][2][2][2][2];
priority_queue <node> fre[2][2][2][2][2]; //0: small one, -1; 1: large one, 1.
int ref (int x) {return (x ? 1 : -1);}

void add_free (node x) {
	if_in[x.id] = false;
	for (int d0 = 0; d0 <= 1; d0 ++)
	for (int d1 = 0; d1 <= 1; d1 ++)
	for (int d2 = 0; d2 <= 1; d2 ++)
	for (int d3 = 0; d3 <= 1; d3 ++)
	for (int d4 = 0; d4 <= 1; d4 ++) {
		int val = ref(d0) * x.d[0] + ref(d1) * x.d[1] + ref(d2) * x.d[2] + ref(d3) * x.d[3] + ref(d4) * x.d[4];
		node ne(val, x.id);
		fre[d0][d1][d2][d3][d4].push(ne);
	}
}

void add_in (node x) {
	if_in[x.id] = true;
	for (int d0 = 0; d0 <= 1; d0 ++)
	for (int d1 = 0; d1 <= 1; d1 ++)
	for (int d2 = 0; d2 <= 1; d2 ++)
	for (int d3 = 0; d3 <= 1; d3 ++)
	for (int d4 = 0; d4 <= 1; d4 ++) {
		int val = ref(d0) * x.d[0] + ref(d1) * x.d[1] + ref(d2) * x.d[2] + ref(d3) * x.d[3] + ref(d4) * x.d[4];
		node ne(val, x.id);
		ins[d0][d1][d2][d3][d4].push(ne);
	}
}

pii select () {
	int mx_val = -1;
	int oid;
	for (int d0 = 0; d0 <= 1; d0 ++)
	for (int d1 = 0; d1 <= 1; d1 ++)
	for (int d2 = 0; d2 <= 1; d2 ++)
	for (int d3 = 0; d3 <= 1; d3 ++)
	for (int d4 = 0; d4 <= 1; d4 ++) {
		// if (ins[d0][d1][d2][d3][d4].empty()) {
		// 	cerr << "fucked up here " << endl;
		// }
		node ni = ins[d0][d1][d2][d3][d4].top();
		node nf(-1, -1);
		do {
			// if (fre[d0^1][d1^1][d2^1][d3^1][d4^1].empty()) {
			// 	cerr << "fucked up here " << endl;
			// }
			nf = fre[d0^1][d1^1][d2^1][d3^1][d4^1].top();
			if (!if_in[nf.id])
				break;
			fre[d0^1][d1^1][d2^1][d3^1][d4^1].pop();
		} while (true);
		// cerr << "trying: " << d0 << " " << d1 << " " << d2 << " " << d3 << " " << d4 << " : " << ni.val << " " << nf.val << endl;
		int val = ni.val + nf.val;
		if (val > mx_val) {
			mx_val = val;
			oid = nf.id;
		}
	}
	return MP(mx_val, oid);
}


int main() {
	scanf("%d %d", &n, &d);
	F0R(i, n) {
		F0R(j, d)
			scanf("%d", &co[i].d[j]);
		co[i].id = i;
		add_free(co[i]);
	}
	d = 5;

	ll fans = 0;

	add_in(co[0]);
	FOR(i, 1, n) {
		pii sel = select();
		// cerr << "round #" << i << " : " << sel.F << " adding " << sel.S << endl;
		fans += sel.F;
		add_in(co[sel.S]);
	}
	printf("%lld\n", fans);
    return 0;
}