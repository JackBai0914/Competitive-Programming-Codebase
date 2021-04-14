#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
using namespace std;
typedef long long ll;

int n, m;
struct e {int to, next;} edge[5000050];
int point[3000030], te = 0;
void add (int u, int v) {
	te ++;
	edge[te].to = v;
	edge[te].next = point[u];
	point[u] = te;
}

int flag[3000030];
vector <int> rec;
int cnt = 0;

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T --) {
		te = 1;
		cin >> n >> m;
		for (int i = 1; i <= 3 * n; i ++)
			point[i] = flag[i] = 0;
		for (int i = 1; i <= m; i ++) {
			int a, b;
			cin >> a >> b;
			add (a, b);
			add (b, a);
		}
		rec.resize(0);
		cnt = 0;
		for (int i = 1; i <= 3 * n; i ++) {
			if (flag[i])
				continue ;
			for (int e = point[i]; e; e = edge[e].next) {
				int to = edge[e].to;
				if (!flag[to]) {
					flag[to] = flag[i] = 1;
					rec.push_back(e / 2);
					cnt ++;
					break;
				}
			}
		}
		// cerr << " : " << cnt << endl;
		if (cnt >= n) {
			cout << "Matching" << '\n';
			for (int i = 0; i < n; i ++)
				cout << rec[i] << " ";
			cout << '\n';
		}
		else {
			int ans = 0;
			cout << "IndSet" << '\n';
			for (int i = 1; i <= 3 * n && ans < n; i ++)
				if (!flag[i]) {
					cout << i << ' ';
					ans ++;
				}
			cout << '\n';
		}
	}

	return 0;
}
/*
5
2 15
1 2
1 3
1 4
1 5
1 6
2 3
2 4
2 5
2 6
3 4
3 5
3 6
4 5
4 6
5 6
1 2
1 3
1 2
1 2
1 3
1 2
2 5
1 2
3 1
1 4
5 1
1 6
2 15
1 2
1 3
1 4
1 5
1 6
2 3
2 4
2 5
2 6
3 4
3 5
3 6
4 5
4 6
5 6
*/