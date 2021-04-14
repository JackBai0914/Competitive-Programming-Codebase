#include <iostream>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#define MP make_pair
#define F first
#define S second
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
const int maxn = 2000020;
const int maxm = 20000020;
const double time_limit = 36000;
typedef pair <int, int> pii;
typedef long double ld;
ld sqr (ld x) {return x * x;}

int n = 0, m = 0, te = 1;
int point[maxn], dg[maxn];
pii erec[maxm];
struct e {int fr, to, next;} edge[maxm];
void add (int a, int b) {edge[++te].fr = a; edge[te].to = b;edge[te].next = point[a]; point[a] = te;}

int msk[maxn];

int c_in[maxn], c_out[maxn], c_cnt[maxn];\
ld M, R;
void calc_Q (int c_num) {
	M = 0, R = 0;
	for (int i = 1; i <= c_num; i ++)
		c_in[i] = c_out[i] = c_cnt[i] = 0;
	for (int i = 1; i <= n; i ++)
		c_cnt[msk[i]] ++;
	// cerr << "fine? " << endl;

	for (int i = 1; i <= m; i ++) {
		int fr = erec[i].F;
		int to = erec[i].S;
		if (msk[fr] == msk[to])
			c_in[msk[fr]] ++;
		else {
			c_out[msk[fr]] ++;
			c_out[msk[to]] ++;
		}
	}
	// cerr << "fine? " << endl;
	for (int i = 1; i <= c_num; i ++) {
		// cerr << ": " << c_in[i] << " " << c_out[i] << " " << c_cnt[i] << endl;
		// cerr << "st " << endl;
		M += (ld)c_in[i] / m - sqr((ld)(2 * c_in[i] + c_out[i]) / m / 2);
		// cerr << "mid " << endl;
		R += (c_cnt[i] == 1 ? 1 : c_in[i] / ((ld)c_cnt[i] * (c_cnt[i] - 1) / 2));
		// cerr << "ed " << endl;

	}
	R = 0.5 * (R / c_num - c_num / n);
}

vector <int> com[maxn];

int main() {
	srand(time(0));
	ios::sync_with_stdio(false);
	int fr, to;


	freopen("a1.in", "r", stdin);
	for (int i = 1; i <= 950327; i ++) {
		cin >> fr >> to;
		fr ++, to ++;
		n = max (n, max(fr, to));
		erec[++m] = MP(fr, to);
		add (fr, to);
		add (to, fr);
	}
	fclose(stdin);
	cerr << n << " " << m << endl;
	freopen("graph_node2comm_level5", "r", stdin);
	int mx_c = 0;
	while (cin >> fr >> to) {
		// cerr << fr << " " << to << endl;
		// if (fr == 233)
		// 	cerr << "find it! " << to << endl;
		fr ++;
		to ++;
		msk[fr] = to;
		mx_c = max(mx_c, to);
		com[to].push_back(fr);
	}
	fclose(stdin);
	
	calc_Q (mx_c);
	cout << M << " " << R << " " << M + R << endl;


	int weight = (M+R)*1000000;
	stringstream ss;
	ss << weight << ".out";

	freopen(ss.str().c_str(), "w", stdout);
	for (int i = 1; i <= mx_c; i ++) {
		for (int j = 0; j < com[i].size(); j ++)
			cout << com[i][j] - 1 << " ";
		cout << endl;
	}

	return 0;
}