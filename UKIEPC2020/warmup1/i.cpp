/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-10 16:36:49
* @description: 
* /Users/jackbai/Desktop/UKIEPC2016/i.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv i.cpp
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

string bar[110][1010];
int bst[110], mx[110], fd[110];
string x;


int main() {
	int n, m;
	cin >> x >> n;
	string s, t;
	getline(cin, s);
	for (int i = 0; i < n; i ++) {		
		getline(cin, s);
		cerr << ""
		int last = -1;
		for (int j = 0; j < s.size(); j ++)
			if (s[j] == ' ') {
				bar[i][bst[i] ++] = s.substr(last + 1, j - last - 1);
				last = j;
			}
		bar[i][bst[i] ++] = s.substr(last + 1);
		for (int j = 0; j < bst[i]; j ++)
			if (x.size() - bar[i][j].size() >= 0 && bar[i][j] == x.substr(x.size() - bar[i][j].size()))
				fd[i] = true;
	}
	cin >> m;
	getline(cin, t);
	for (int i = 0; i < m; i ++) {
		getline(cin, t);
		bool ans = false;
		for (int id = 0; id < n; id ++) {
			bool have = false;
			for (int j = 0; j < bst[id]; j ++)
				if (t.size() - bar[id][j].size() >= 0 && bar[id][j] == t.substr(t.size() - bar[id][j].size()))
					have = true;
			if (have && fd[id]) 
				ans = true;
		}
		cout << (ans ? "YES" : "NO") << endl;
	}

    return 0;
}