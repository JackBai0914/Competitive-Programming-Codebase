#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int n, sn;
vector <int> par[100010];
int ban[100010], num[100010];
int st[100010];

vector <int> c;
vector <int> mp[100010];

vector <int> ans;
bool flag[100010];
vector <int> waste;

vector <int> cand;

void dfs (int x) {
	// cerr << "in : " << x << " " << ans.size() << endl;
	// cerr << "mark : " << x << " : " << n - sn << endl << "ans: ";
	// for (int i = 0; i < ans.size(); i ++)
		// cerr << ans[i] << " ";
	// cerr << endl << "waste: ";
	// for (int i = 0; i < waste.size(); i ++)
		// cerr << waste[i] << " ";
	// cerr << endl;
	if (x == n + 1) {
		// cerr << "done " << endl;
		for (int i = 0; i < n; i ++)
			cout << ans[i] << " ";
		cout << endl;
		exit(0);
	}
	if (x == 1) {
		for (int i = 1; i <= n; i ++) {
			ans.push_back(i);
			if (i != 1)	waste.push_back (1);
			flag[i] = 1;
			dfs (x + 1);
			flag[i] = 0;
			if (i != 1)	waste.pop_back ();
			ans.pop_back();
		}
		return ;
	}
	int last = ans[ans.size() - 1];
	if (x == n - sn) {
		cand.resize(0);
		for (int i = 1; i <= n; i ++)
			if (!flag[i])
				cand.push_back(i);
	}
	if (x >= n - sn) {
		for (int i = 0; i < cand.size(); i ++)
			if (cand[i] != -1)
				if (ban[last] != cand[i]) {
					ans.push_back(cand[i]);
					int tmp = cand[i];
					cand[i] = -1;
					dfs (x + 1);
					cand[i] = tmp;
					ans.pop_back();
				}
		return ;
	}
	int cnt = 0;
	int tg = 0;
	for (int i = 0; i < c.size(); i ++) {
		if (flag[c[i]])
			continue ;
		if (num[c[i]] == n - 2) {
			if (mp[last][i] != 0) {
				return ;
			}
			cnt ++;
			tg = c[i];
		}
	}
	if (cnt > 1)
		return ;
	if (cnt == 1) {
		ans.push_back(tg);
		waste.push_back(x);
		flag[tg] = 1;
		dfs (x + 1);
		ans.pop_back();
		waste.pop_back();
		flag[tg] = 0;
		return ;
	}
	
	sort (waste.begin(), waste.end());
	for (int i = 0; i < waste.size(); i ++) {
		int cur = waste[i];
		if (flag[cur])
			continue ;
		if (ban[last] == cur)
			continue ;
		//select c
		flag[cur] = 1;
		waste[i] = x;
		for (int i = 0; i < c.size(); i ++)
			if (mp[last][i] == 0) {
				mp[last][i] = 1;
				num[c[i]] ++;
			}
		ans.push_back(cur);
		dfs (x + 1);
		ans.pop_back();
		for (int i = 0; i < c.size(); i ++)
			if (mp[last][i] == 1) {
				mp[last][i] = 0;
				num[c[i]] --;
			}
		waste[i] = cur;
		flag[cur] = 0;
	}
	for (int t = x; t <= n; t ++) {
		if (ban[last] == t)
			continue ;
		if (flag[t])
			continue ;
		flag[t] = 1;
		if (t != x)
			waste.push_back (x);
		for (int i = 0; i < c.size(); i ++)
			if (mp[last][i] == 0) {
				mp[last][i] = 1;
				num[c[i]] ++;
			}
		ans.push_back(t);
		dfs (x + 1);
		ans.pop_back();
		for (int i = 0; i < c.size(); i ++)
			if (mp[last][i] == 1) {
				mp[last][i] = 0;
				num[c[i]] --;
			}
		if (t != x)
			waste.pop_back();
		flag[t] = 0;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	sn = pow(n, 0.6667);
	for (int i = 1; i <= n; i ++) {
		cin >> ban[i];
		num[ban[i]] ++;
		par[ban[i]].push_back(i);
	}

	for (int i = 1; i <= n; i ++) {
		if (num[i] >= sn) {
			c.push_back(i);
			for (int j = 1; j <= n; j ++)
				mp[j].push_back(0);
			for (int j = 0; j < par[i].size(); j ++)
				mp[par[i][j]][mp[1].size() - 1] = -1;
		}
		if (num[i] == n - 1) {
			cout << -1 << endl;
			return 0;
		}
	}

	dfs (1);


	return 0;
}