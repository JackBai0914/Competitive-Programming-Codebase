#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

int n, k;
int e[500050], ind[500050];

int rt[500050];
int get_r (int x) {return (x == rt[x] ? x : rt[x] = get_r(rt[x]));}

queue <int> q;

map <int, int> m[500050];
int sum[500050];
int ans[500050];
int dep[500050];


int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
		rt[i] = i;
	for (int i = 1; i <= n; i ++)
		cin >> e[i], ind[e[i]] ++;	
	for (int i = 1; i <= n; i ++)
		if (ind[i] == 0)
			q.push(i);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		sum[x] ++;

		ans[x] = sum[x];

		rt[get_r(e[x])] = x;

	}
	return 0;
}