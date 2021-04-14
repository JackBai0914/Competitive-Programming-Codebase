#include <bits/stdc++.h>
using namespace std;
char endow[50000][2];
int n, d, m;
struct rec {int i, j; char hi, hj;} r[100010];
int point[200020], te = 1, dfn[200020], low[200020], ti = 0;
struct e {int to, next;} edge[800040];
void add (int u, int v)
{
	te ++;
	edge[te].to = v;
	edge[te].next = point[u];
	point[u] = te;
}

stack <int> s;


int tim[200020], tst = 0;
bool if_x[200020];
void dfs(int x)
{
	dfn[x] = low[x] = ++ti;
	if_in[x] = 1;
	s.push(x);
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (!dfn[to])	dfs(to), low[x] = min(low[x], low[to]);
		else if (if_in[to])	low[x] = min(low[x], dfn[to]);
	}
	if (dfn[x] == low[x]) {
		tst ++;
		while (s.top() != x) {
			if_in[s.top()] = 0;
			tim[s.top()] = tst;
			s.pop();
		}
		if_in[x] = 0;
		tim[x] = tst;
		s.pop();
	}
}

int recx[110], xst = 0;

int main()
{
//	freopen("ex_game2.in", "r", stdin);
//	freopen("ex_game2.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin >> n >> d;
	for (int i = 1; i <= n; i ++) {
		char ins;
		cin >> ins;
		if (ins == 'a') endow[i][0] = 'B', endow[i][1] = 'C';
		else if (ins == 'b') endow[i][0] = 'A', endow[i][1] = 'C';
		else if (ins == 'c') endow[i][0] = 'A', endow[i][1] = 'B';
		else	recx[++xst] = i, endow[i][0] = 'A';
	}
	cin >> m;
	for (int a, b, c, d, i = 1; i <= m; i ++)
		cin >> r[i].i >> r[i].hi >> r[i].j >> r[i].hj;
	for (int en = 0; en < (1 << xst); en ++) {
//		cout << "en :     " << en << endl;
		memset(point, 0, sizeof point);
		memset(dfn, 0, sizeof dfn);
		memset(low, 0, sizeof low);
		memset(tim, 0, sizeof tim);
		te = ti = tst = 0;
		for (int enn = en, i = 1; i <= xst; i ++) {
			if (enn % 2)	endow[recx[i]][1] = 'B';
			else			endow[recx[i]][1] = 'C';
			enn /= 2;
		}
		for (int posx, posy, i = 1; i <= m; i ++) {
			posx = posy = -1;
			if (r[i].hi == endow[r[i].i][0])		posx = 0;
			else if (r[i].hi == endow[r[i].i][1])	posx = 1;
			if (r[i].hj == endow[r[i].j][0])		posy = 0;
			else if (r[i].hj == endow[r[i].j][1])	posy = 1;
			if (posx == -1)	continue;
			if (posy == -1)	add (r[i].i * 2 + posx, r[i].i * 2 + posx ^ 1);
			else			add (r[i].i * 2 + posx, r[i].j * 2 + posy), add (r[i].j * 2 + posy ^ 1, r[i].i * 2 + posx ^ 1);
		}
		for (int i = 2; i <= 2 * n + 1; i ++)
			if (!dfn[i])
				dfs(i);
		bool ok = 1;
		for (int i = 1; i <= n; i ++)
			if (tim[i * 2] == tim[i * 2 + 1]) {
				ok = 0;
				break;
			}
		if (!ok)	continue;
	
		for (int i = 1; i <= n; i ++) {
			if (tim[2 * i] > tim[2 * i + 1])	cout << endow[i][1];
			else								cout << endow[i][0];
		}
		cout << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}

