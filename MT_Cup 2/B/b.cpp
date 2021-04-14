#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const ld PI = 3.14159265359;

string s;
int sx[10010], sl[10010];

namespace Clock {
	const int size = 21;
	const int C = size/2;
	struct mp {
		bool v[size][size];
		mp () {memset(v, 0, sizeof v);}
		void paint (int x, int y) {
			for (int i = x; i <= x ; i ++)
				for (int j = y; j <= y ; j ++)
					if (0 <= i && i < size && 0 < j && j < size)
						v[i][j] = 1;
		}
		void paint2 (ld dg, int dir) {
			// cerr << "P: " << dg << " " << dir << endl;
			if (dir == 1) {
				for (ld i = 0; i <= C; i += 0.01) {
					int j1 = floor(i * dg);
					int j2 = ceil (i * dg);
					// cerr << i << " : " << j1 << " " << j2 << endl;
					paint(C-i, C+j1);
					paint(C-i, C+j2);
				}
			}
			else {
				for (ld i = 0; i <= C; i += 0.01) {
					int j1 = floor(-i * dg);
					int j2 = ceil (-i * dg);
					paint(C+i, C+j1);
					paint(C+i, C+j2);
				}
			}
		}
		vector <string> outp() {
			vector <string> t;
			for (int i = 0; i < size; i ++) {
				string s = "";
				for (int j = 0; j < size; j ++)
					s += (v[i][j] ? '@':'.');
				t.push_back(s);
			}
			return t;
		}
		void main(int x) {
			x %= 43200;
			if (x == 10800)			paint2(100, 1);
			else if (x == 32400)	paint2(100, -1);
			else if (x == 43200)	paint2(0, 1);
			else if (x == 21600)	paint2(0, -1);
			else {
				ld ang = (ld)x/43200*2*PI;
				ld H = tan(ang);
				// cerr << (ld)x/43200 * 360 << " -- " << H << endl;	
				if (ang <= PI*0.5 || ang >= PI*1.5)	paint2(H, 1);
				else								paint2(H, -1);
			}
			int y = x % 3600;
			if (y == 900)			paint2(100, 1);
			else if (y == 2700)		paint2(100, -1);
			else if (y == 3600)		paint2(0, 1);
			else if (y == 1800)		paint2(0, -1);
			else {
				ld ang = (ld)y/3600*2*PI;
				ld H = tan(ang);
				// cerr << (ld)x/86400 * 360 << " " << H << endl;	
				if (ang <= PI*0.5 || ang >= PI*1.5)	paint2(H, 1);
				else								paint2(H, -1);
			}
		} 
	};
}using namespace Clock;

vector <string> merge1 (vector <string> a, vector <string> b) {
	vector <string> ans;
	for (int i = 0; i < b.size(); i ++) {
		if (a.size() <= i)	ans.push_back(b[i]);
		else				ans.push_back (a[i] + b[i]);
	}
	return ans;
}
vector <string> merge2 (vector <string> a, vector <string> b) {
	vector <string> ans;
	for (int i = 0; i < a.size(); i ++)
		ans.push_back (a[i]);
	for (int i = 0; i < b.size(); i ++)
		ans.push_back (b[i]);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	// freopen("large.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	// for (int i = 1; i <= 27; i ++) {
	// 	cerr << i << endl;
	// 	vector <string> pans;
	// 	for (int j = 1; j <= 227; j ++) {
	// 		int x;
	// 		cin >> x;
	// 		cout << x % 43200 / 3600 << " ";
	// 	}
	// 	cout << endl;
	// }

	// mp test;
	// int x;
	// cin >> x;
	// cerr << x/3600 << ":" << x%3600/60 << ":" << x%3600%60 << endl;
	// test.main(x);
	// vector <string> ans = test.outp();
	// for (int i = 0; i < ans.size(); i ++)
	// 	cout << ans[i] << endl;

	vector <string> ans;
	for (int i = 1; i <= 27; i ++) {
		cerr << i << endl;
		vector <string> pans;
		for (int j = 1; j <= 227; j ++) {
			int x;
			mp cur;
			cin >> x;
			// cerr << x << ":: " << x/3600 << ":" << x%3600/60 << ":" << x%3600%60 << endl;
			cur.main(x);
			pans = merge1 (pans, cur.outp());
		}
		ans = merge2(ans, pans);
	}
	for (int i = 0; i < ans.size(); i ++)
		cout << ans[i] << endl;
	return 0;
}