/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 * 
 * @author: Xingjian Bai 
 * @date: 2020-09-30 22:26:14
 * @description: 
 * 
 * @notes: 
 * g++ -O2 -fsanitize=address -ftrapv a.cpp -o a 
 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pf push_front
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

//loops
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)

//debug
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

//constants
const int MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const ld eps = 1e-8;

int n, m, ne = 0, np = 0;
int a[1000010], b[1000010];

struct Edge
{
	int u,v,w;
}edge[10000010];
ll fa[1000010],ans = 0,eu,ev,cnt;
ll all = 0;
bool cmp(Edge a,Edge b)
{
    return a.w>b.w;
}
int find(int x)
{
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}
void kruskal()
{
    sort(edge,edge+ne,cmp);
    //将边的权值排序
    for(int i=0;i<ne;i++)
    {
        eu=find(edge[i].u), ev=find(edge[i].v);
    	// debug(eu);
    	// debug(ev);

        if(eu==ev)
            continue;
        //将此边权计入答案
        ans += edge[i].w;
        fa[ev]=eu;
        if(++cnt==np-1)
            break;
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin >> m >> n;
	ne = 0;
	np = n + m;
	for(int i=1;i<=np;i++)
    {
        fa[i]=i;
    }
	for (int i = 1; i <= m; i++)	cin >> a[i];
	for (int i = 1; i <= n; i++)	cin >> b[i];
	for (int i = 1; i <= m; i++) {
		int s, p;
		cin >> s;
		all += (ll)a[i] * s;
		for (int j = 1; j <= s; j ++) {
			cin >> p;
			all += b[p];
			edge[ne ++] = {i + n, p, a[i] + b[p]};
		}
	}
	kruskal();
	// debug(all);
	// debug(ans);
	cout << all - ans << endl;
	return 0;
}