/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-26 19:12:23
* @description: 
*  
* 
* @notes: 
* g++ -fsanitize=address -ftrapv 
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

int n;
int e[1000010], ind[1000010];
vector <int> sons[1000010], par[1000010];


int ord[1000010], ost = 0;
queue <int> q;
void init() {
	for (int i = 1; i <= n; i ++)
		if (ind[i] == 0)
			q.push(i);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		ord[++ ost] = x;
		for (int i = 0; i < par[x].size(); i ++)
			if ((--ind[par[x][i]]) == 0)
				q.push(par[x][i]);
	}
}

int lim[1000010];
vector <int> tic[1000010];
bool check (int mx) {
	for (int i = 1; i <= n; i ++)
		tic[i].resize(0);
	for (int i = 1; i <= n; i ++) {
		lim[i] = min(n, mx - e[i] + 1);
		if (lim[i] < 1)
			return false;
	}
	for (int i = n; i >= 1; i --) {
		int x = ord[i];
		tic[lim[x]].push_back(x);
		for (int j = 0; j < sons[x].size(); j ++) {
			int s = sons[x][j];
			lim[s] = min (lim[s], lim[x]);
		}
	}
	// cout << "check: " << mx << endl;
	// for (int i = 1; i <= n; i ++)
	// 	cout << lim[i] << " ";
	// cout << endl;
	int emp = 0;
	for (int t = 1; t <= n; t ++) {
		emp ++;
		if (emp < tic[t].size())
			return false;
		emp -= tic[t].size();
	}
	return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
    	cin >> e[i] >> ind[i];
    	for (int v, j = 0; j < ind[i]; j ++) {
    		cin >> v;
    		sons[i].push_back(v);
    		par[v].push_back(i);
    	}
    }
    init();

    int l = n, r = n + 1000000;
    while (l != r) {
    	int mid = (l + r) >> 1;
    	if (check (mid))
    		r = mid;
    	else
    		l = mid + 1;
    }
    cout << l << endl;
    return 0;
}