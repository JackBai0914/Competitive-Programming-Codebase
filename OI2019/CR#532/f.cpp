#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
const int Max = 19;
int mi[20];
int n, q;
int a[2000010];

void add (int *b, int x) {
	for (int i = Max; i >= 0; i --)
		if (((x >> i) & 1)) {
			if (b[i])
				x ^= b[i];
			else {
				b[i] = x;
				for (int k = i - 1; k >= 0; k --)
					if (((b[i] >> k) & 1))	b[i] ^= b[k];
				for (int k = i + 1; k <= Max; k ++)
					if (((b[k] >> i) & 1))	b[k] ^= b[i];
				break;
			}
		}
}

struct node {
	int st, ed;
	int b[20];
	node () {
		memset(b, 0, sizeof b);
	}
};

node rt[2000010];
void merge(int *b, int *x, int *y) {
	for (int i = 0; i <= Max; i ++)
		b[i] = x[i];
	for (int j = 0; j <= Max; j ++)
		if (y[j])
			add (b, y[j]);
}


int B[20];
void query (int ind, int st, int ed) {
	if (st <= rt[ind].st && rt[ind].ed <= ed) {
		for (int j = 0; j <= Max; j ++)
			if (rt[ind].b[j])
				add (B, rt[ind].b[j]);
		return ;
	}
	if (st <= rt[ind * 2].ed)		query(ind * 2, st, ed);
	if (rt[ind * 2 + 1].st <= ed)	query(ind * 2 + 1, st, ed);
}

int main() {
	for (int i = 0; i < 20; i ++)
		mi[i] = (1 << i);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &a[i]);
	int k = 1;
	while (k <= n)
		k = 2 * k;
	n = k;

	for (int i = n; i < 2 * n; i ++) {
		rt[i].st = rt[i].ed = i - n + 1;
		add (rt[i].b, a[i - n + 1]);
	}
	cout << "?? " << endl;
	for (int i = n - 1; i >= 1; i --) {
		rt[i].st = rt[i * 2].st;
		rt[i].ed = rt[i * 2 + 1].ed;
		merge(rt[i].b, rt[i * 2].b, rt[i * 2 + 1].b);
		cout << i << " : " << rt[i].st << " " << rt[i].ed << endl;
	}
	cin >> q;
	for (int a, b, i = 1; i <= q; i ++) {
		cin >> a >> b;
		memset(B, 0, sizeof B);
		query(1, a, b);
		int ans = 0;
		for (int i = Max; i >= 0; i --)
			ans ^= B[i];
		printf("%d\n", ans);
	}
	return 0;
}