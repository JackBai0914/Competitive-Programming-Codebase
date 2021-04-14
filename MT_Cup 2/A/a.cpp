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
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

string s;
int sx[10010], sl[10010];

int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int t;
	cin >> t;
	while (t --) {
		cin >> s;
		sx[0] = (s[0] == 'x');
		sl[0] = (s[0] == 'l');
		for (int i = 1; i < s.size(); i ++) {
			sx[i] = sx[i - 1] + (s[i] == 'x');
			sl[i] = sl[i - 1] + (s[i] == 'l');
		}

		if (s.size() <= 4 || sx[s.size() - 1] < 3 || sl[s.size() - 1] < 2) {
			cout << 0 << endl;
			continue ;
		}
		int fans = 1e9;
		for (int i = s.size() - 1; i >= 0; i --)
			for (int j = i - 1; j >= 0; j --) {
				int pans = (s[i] != 'l') + (s[j] != 'l');
				int rem = sl[s.size() - 1] - sl[i] + sl[i - 1] - sl[j];
				int fix;
				if (j <= 2)	fix = 0;
				else		fix = max (0, sx[j - 1] - 2);
				fans = min (fans, pans + rem + fix);
			}
		fans = min (fans, max(0, sl[s.size() - 1] - 1));
		fans = min (fans, max(0, sx[s.size() - 1] - 2));
		fans = max (0, fans);
		cout << fans << endl;
	}
	return 0;
}