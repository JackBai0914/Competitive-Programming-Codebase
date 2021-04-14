#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int n;

int rt[20];


vector <int> v[20];
vector <int> rec[20];
int st = 0, pmn = 10000, good = 0;
int flag[20];

void dfs(int a) {
	
	int x = rt[a];
	if (a == n + 1) {
		if (st < pmn) {
			pmn = st;
			for (int i = 1; i <= st; i ++)
				rec[i] = v[i];
		}
		if (st == pmn) {
			int po = 1;
			for (int i = 1; i <= st; i ++)
				for (int j = 1; j < i; j ++) {
					if (flag[i] == 0 || flag[j] == 0 || flag[i] == flag[j])
					{}
					else
						po = 0;
				}
			if (po)
				good = 1;
		}
		return ;
	}
	if (st > pmn)
		return ;
	for (int i = 1; i <= st; i ++) {
		if (x < v[i][v[i].size() - 1] && flag[i] <= 0) {
			int ori = flag[i];
			flag[i] = -1;
			v[i].push_back(x);
			dfs(a + 1);
			v[i].pop_back();
			flag[i] = ori;
		}
		if (x > v[i][v[i].size() - 1] && flag[i] >= 0) {
			int ori = flag[i];
			flag[i] = 1;
			v[i].push_back(x);
			dfs(a + 1);
			v[i].pop_back();
			flag[i] = ori;
		}
	}
	st ++;
	v[st].push_back(x);
	dfs(a + 1);
	v[st].pop_back();
	st --;
}

int fmx = 0;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		rt[i] = i;
	}

	do {
		
		st = 0;
		memset(flag, 0, sizeof flag);
		pmn = 10000;
		good = 0;
		for (int i = 1; i <= 20; i ++)
			v[i].resize(0);
		dfs(1);
		fmx = max(fmx, pmn);
		if (pmn == 4) {
			for (int i = 1; i <= n; i ++)
				cout << rt[i] << " "; cout << " : ";
			for (int i = 1; i <= pmn; i ++) {
				for (int j = 0; j < rec[i].size(); j ++)
					cout << rec[i][j] << " ";
				cout << "- ";
			}
			cout << "-> " << pmn << " " << good << endl;
		}
	} while (next_permutation(rt + 1, rt + n + 1));
	cout << fmx << endl;
	return 0;
}
