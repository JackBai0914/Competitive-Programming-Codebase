#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <map>
using namespace std;

map <string, int> o, c;
string inso[1010], insc[1010];
int ins[1010], tp[1010];

const int oo = 1e5;
int n, m, k;
int S, T;
int point[100010], cur[100010], te = 1;
struct e {int to, next, flow;}edge[1000010];
void add(int u, int v, int w)
{
	// cerr << "add " << u << " " << v << " " << w << endl;
	te ++;
	edge[te].to = v;
	edge[te].next = point[u];
	point[u] = te;
	edge[te].flow = w;
}

int dist[100010];
bool bfs()
{
	memset(dist, 0, sizeof dist);
	queue <int> q;
	q.push(S);
	dist[S] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int e = point[now]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (dist[to] == 0 && edge[e].flow)
				dist[to] = dist[now] + 1, q.push(to);
		}
	}
	return dist[T];
}
int flow;
int dfs(int n, int mn)
{
	if (n == T || !mn)
		return mn;
	int pans = 0;
	for (int &e = cur[n]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (dist[to] == dist[n] + 1 && edge[e].flow) {
			flow = dfs(to, min(mn, edge[e].flow));
			if (flow) {
				edge[e].flow -= flow;
				edge[e ^ 1].flow += flow;
				pans += flow;
				mn -= flow;
			}
		}
	}
	return pans;
}
int fans = 0;
void Dinic()
{
	while (bfs()) {
		for (int i = 0; i <= T; i ++)
			cur[i] = point[i];
		fans += dfs(S, oo);
	} 
}

int rec[1010];
int fn[1010], fm[1010];

bool hp[100010];
void search (int x) {
	hp[x] = 1;
	if (x > n + m) {
		// cerr << "find " << x - n - m << endl;
		int ju = x - n - m;
		if (tp[ju] == 0)
			fm[ins[ju] - n] = true;
	}
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (hp[to] || edge[e].flow == 0)
			continue ;
		search (to);
	}
}

vector <string> sans;

int main()
{
	ios::sync_with_stdio(false);
	string Ins;
	cin >> n;	for (int i = 1; i <= n; i ++)	cin >> Ins, inso[i] = Ins, o[Ins] = i;
	cin >> m;	for (int i = 1; i <= m; i ++)	cin >> Ins, insc[i] = Ins, c[Ins] = i;
	cin >> k;
	S = 0, T = n + m + k + 1;
	for (int i = 1; i <= k; i ++) {
		string a, b;
		int ida = -1, idb = -1;
		cin >> a >> b;
		// cerr << "test p : " << o[a] << " " << c[b] << endl;
		if (o[a] != 0 && c[b] != 0) {
			ida = o[a], idb = c[b];
			// cerr << "here: " << ida << " " << idb << endl;
			tp[i] = 0;
			ins[i] = n + idb;
			
			add (n + m + i, S, 0);
			rec[i] = te + 1;
			add (S, n + m + i, 1);
			add (ida, n + m + i, oo);
			add (n + m + i, ida, oo);
			add (idb + n, n + m + i, oo);
			add (n + m + i, idb + n, oo);
			continue ;
		}
		ida = c[a], idb = o[b];
		// cerr << "test: " << a << " " << c[a] << " " << o[a] << endl;
		// cerr << "test: " << b << " " << c[b] << " " << o[b] << endl;
		// cerr << "here2: " << ida << " " << idb << endl;
		ins[i] = idb;
		tp[i] = 1;
		rec[i] = te + 1;
		add (n + m + i, T, 1);
		add (T, n + m + i, 0);
		add (idb, n + m + i, oo);
		add (n + m + i, idb, oo);
		add (ida + n, n + m + i, oo);
		add (n + m + i, ida + n, oo);
	}
	Dinic();
	// cerr << "fans " << fans << endl;
	// for (int i = 2; i <= te; i ++) {
	// 	cerr << "edge: " << i << " : " << edge[i].to << " " << edge[i].flow << endl;
	// }
	search (S);
	for (int i = n + m + 1; i <= n + m + k; i ++)
		if (hp[i] == 0 && tp[i] == 1)
			fn[ins[i]] = true;
	// cout << fans << endl;
	for (int i = 1; i <= n; i ++)	if (fn[i] == 1)	sans.push_back(inso[i]);
	for (int i = 1; i <= m; i ++)	if (fm[i] == 1)	sans.push_back(insc[i]);
	cout << sans.size() << endl;
	for (int i = 0; i < sans.size(); i ++)
		cout << sans[i] << endl;
	return 0;
}