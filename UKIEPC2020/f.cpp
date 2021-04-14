#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const ld eps = 1e-8;
const int maxn = 1005;
const int oo = 1e9;
vector<int> to[maxn], c[maxn];
int v[maxn];
bool mark[maxn];
int dis[maxn];
bool check[maxn][maxn];
int id[maxn];
bool cmp(int x, int y)
{
	return dis[x] < dis[y];
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m, p, g;
	cin >> n >> m >> p >> g;
	for(int i = 1; i <= p; i ++)
		cin >> v[i];
	for(int i = 1; i <= m; i ++)
	{
		int a, b, cc;
		cin >> a >> b >> cc;
		to[a].push_back(b);
		c[a].push_back(cc);
		to[b].push_back(a);
		c[b].push_back(cc);
	}
	for(int i = 1; i <= n; i ++)
	{
		mark[i] = 0;
		dis[i] = oo;
	}
	dis[1] = 0;
	for(int t = 1; t <= n; t ++)
	{
		int mn = oo, mnp = 0;
		for(int i = 1; i <= n; i ++)
			if(!mark[i] && dis[i] < mn)
			{
				mn = dis[i];
				mnp = i;
			}
		mark[mnp] = 1;
		for(int i = 0; i < to[mnp].size(); i ++)
		{
			int ttt = to[mnp][i];
			if(!mark[ttt])
				dis[ttt] = min(dis[ttt], dis[mnp] + c[mnp][i]);
		}
	}
	for(int i = 1; i <= n; i ++)
		id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			check[i][j] = 0;
	for(int i = 1; i <= n; i ++)
	{
		int a = id[i];
		check[a][a] = 1;
		for(int j = 1; j < i; j ++)
		{
			int b = id[j];
			for(int k = 0; k < to[a].size(); k ++)
			{
				int ttt = to[a][k];
				if(dis[a] == dis[ttt] + c[a][k] && check[ttt][b])
				{
					check[a][b] = 1;
					break;
				}
			}
		}
	}
	long long ans = 0;
	for(int i = 1; i <= p; i ++)
		ans += dis[v[i]];
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			if(check[i][j] && check[j][1] && dis[i] - dis[j] > g)
			{
				long long now = 0, diff = dis[i] - dis[j] - g;
				for(int k = 1; k <= p; k ++)
					now += check[v[k]][i] ? dis[v[k]] - diff : dis[v[k]];
				ans = min(ans, now);
			}
	cout << ans << endl;

	return 0;
}