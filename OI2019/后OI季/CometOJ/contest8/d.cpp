#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#define MP make_pair
#define F first
#define S second
using namespace std;

inline char gc()
{
	static char buf[262144],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,262144,stdin),p1 == p2) ? EOF : *p1++;
}

inline void read(int &v)
{
	v = 0;
	char c = gc();
	while (c < '0' || c > '9')
		c = gc();
	while (c >= '0' && c <= '9')
	{
		v = v * 10 + c - '0';
		c = gc();
	}
}

typedef pair <int, int> pii;
pii operator + (const pii a, const pii b) {
	return MP (a.F + b.F, a.S + b.S);
}
int n, m, q;
int v[1000010], s[1000010];
vector <int> I[1000010], O[1000010];

struct Query {
	int l, r, id;
	bool operator < (const Query &u) const {
		return r < u.r;
	}
} query[1000010];
int ans[1000010];

int bel[1000010];

namespace Tree2 {
int c[4000040]; //对应原数组和树状数组
int lowbit(int x){
    return x&(-x);
}

void add(int i,int k){    //在i位置加上k
    if (!i)
		return ;
    while(i <= n){
        c[i] += k;
        i += lowbit(i);
    }
}

int getsum(int i){        //求A[1 - i]的和
	if (!i)
		return 0;
    int res = 0;
    while(i > 0){
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}
}

namespace Tree1 {
int c[4000040]; //对应原数组和树状数组
int lowbit(int x){
    return x&(-x);
}

void add(int i,int k){    //在i位置加上k
	if (!i)
		return ;
    while(i <= n){
        c[i] += k;
        i += lowbit(i);
    }
}

int getsum(int i){        //求A[1 - i]的和
	if (!i)
		return 0;
    int res = 0;
    while(i > 0){
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}
}

int main() {
	// ios::sync_with_stdio(false);
	read(n);
	read(m);
	read(q);
	// cin >> n >> m >> q;
	for (int i = 1; i <= n; i ++) {
		// cin >> v[i];
		read(v[i]);
		s[i] = s[i - 1] + v[i];
	}
	for (int a, b, i = 1; i <= m; i ++) {
		// cin >> a >> b;
		read(a);
		read(b);
		I[b].push_back(a);
		O[a].push_back(b);
	}
	for (int i = 1; i <= q; i ++) {
		// cin >> query[i].l >> query[i].r;
		read(query[i].l);
		read(query[i].r);
		query[i].id = i;
	}
	sort(query + 1, query + q + 1);

	// SegTree::pnode root = SegTree::build(1, n);
	// SegTree::pnode root2 = SegTree::build(1, n);

	int pt = 1;
	int st, ed, ans0, ans1, sum, num;
	for (int i = 1; i <= n && pt <= q; i ++) {
		// cerr << "dealing : " << i << endl;
		int fr, to;
		for (int j = 0; j < O[i].size(); j ++) {
			to = O[i][j];
			if (to <= i)
				bel[i] = max(bel[i], to);
		}
		Tree1::add (bel[i], v[i]);

		for (int j = 0; j < I[i].size(); j ++) {
			fr = I[i][j];
			if (fr <= i && bel[fr] < fr) {
				// cerr << "mark : " << fr << endl;
				Tree1::add(bel[fr], -v[fr]);
				bel[fr] = i;
				Tree2::add(fr, v[fr]);
			}
		}

		while (pt <= q && query[pt].r == i) {
			ed = query[pt].r, st = query[pt].l;
			// cerr << pt << " ? " << st << " " << ed << endl;
			ans0 = Tree1::getsum(ed) - Tree1::getsum(st - 1);
			ans1 = Tree2::getsum(ed) - Tree2::getsum(st - 1);
			sum = s[ed] - s[st - 1], num = ed - st + 1;
			// cerr << sum << " " << num << " "
				 // << ans0.S << " " << ans0.F << " " 
				 // << ans1.S << " " << ans1.F << endl;
			ans[query[pt].id] = sum - ans0 - ans1;
			pt ++;
		}
	}
	// for (int i = 1; i <= q; i ++)
		// cerr << ans[i] << " ";
	// cerr << endl;

	long long fans = 0;
	for (int i = 1; i <= q; i ++)
		fans = fans ^ ((long long)i * ans[i]);
	cout << fans << endl;
	return 0;
}