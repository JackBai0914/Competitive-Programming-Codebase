#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

map <int, int> adj;
map <int, int> adj2;

int mx_adj2 = 0;
int fans = 0;

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		int v;
		cin >> v;
		if (!adj[v])
			adj[v] = i;
		else
			adj2[v] = adj[v], adj[v] = i;
		mx_adj2 = max (mx_adj2, adj2[v]);
		fans = max (fans, i - mx_adj2);
	}
	cout << fans << endl;
	return 0;
}
