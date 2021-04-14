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

int n;
vector <pair <double, pii> > inc;
int bel[1000010];


int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		int a, b;
		cin >> a >> b;
		inc.push_back(MP(a, MP(1, i)));
		inc.push_back(MP(b + 0.5, MP(-1, i)));
	}
	sort(inc.begin(), inc.end());
	int cans = 0, fans = 0;
	for (int i = 0; i < inc.size(); i ++) {
		cans += inc[i].S.F;
		fans = max (fans, cans);
	}
	cout << fans << endl;

	queue <int> q;
	for (int i =1; i <= fans; i ++)
		q.push(i);

	for (int i = 0; i < inc.size(); i ++) {
		if (inc[i].S.F == 1) {
			bel[inc[i].S.S] = q.front();
			q.pop();
		}
		else {
			q.push(bel[inc[i].S.S]);
		}
	}
	for (int i = 1; i <= n; i ++)
		cout << bel[i] << " ";
	cout << endl;
	return 0;
}
