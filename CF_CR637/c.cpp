#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int n, m, g, r;
int d[10010];

int vis[100010];
queue <pair <int, int> > q;
void work (int x) {

}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i ++)
		cin >> d[i];
	sort (d + 1, d + m + 1);
	cin >> g >> r;




	return 0;
}