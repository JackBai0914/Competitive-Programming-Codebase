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
vector <pii> inc;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		int a, b;
		cin >> a >> b;
		inc.push_back(MP(a, 1));
		inc.push_back(MP(b, -1));
	}
	sort(inc.begin(), inc.end());
	int cans = 0, fans = 0;
	for (int i = 0; i < inc.size(); i ++) {
		cans += inc[i].S;
		fans = max (fans, cans);
	}
	cout << fans << endl;
	return 0;
}
