#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

int n, c;
int a[20020];
int fans = 0;

namespace SA {
	const ld delta = 1 - 1e-3;
	const ld T_end = 1e-3;
	const ld T_begin = 1e5;
	vector <int> chosen;
	vector <int> unchosed;
	int pans;
	void main(int t) {
		chosen.resize(0);
		unchosed.resize(0);
		pans = 0;
		if (t == 1)	sort (a + 1, a + n + 1);
		else if (t == 2)	{
			sort (a + 1, a + n + 1);
			for (int i = 1; i * 2 <= n; i ++)
				swap (a[i], a[n - i + 1]);
		}
		else
			random_shuffle (a + 1, a + n + 1);
		for (int i = 1; i <= n; i ++)
			if (pans + a[i] <= c)
				pans += a[i];
		fans = max (fans, pans);
	}
}

const int C = 2e7 / 2e4;

int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	srand (20010914);
	int T;
	// cerr << "C: " << C << endl;
	cin >> T;
	while (T --) {
		cin >> n >> c;
		for (int i = 1; i <= n; i ++)
			cin >> a[i];
		fans = 0;
		for (int i = 1; i <= C; i ++)
			SA::main(i);
		cout << fans << endl;
	}

	cerr << TIME << endl;
	return 0;
}