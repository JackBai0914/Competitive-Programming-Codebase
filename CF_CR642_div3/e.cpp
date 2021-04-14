#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#define F first
#define S second
#define MP make_pair
using namespace std;

int n, k;
bool a[1000010];
char ins;

vector <int> cand;
int s[1000010], all;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		int sum = 0;
		cin >> n >> k;
		for (int i = 1; i <= n; i ++) {
			cin >> ins;
			a[i] = (ins == '1');
			sum += a[i];
		}
		int fans = 1e9;
		for (int i = 1; i <= k; i ++){
			int pans = 1e9;
			int 
			cand.resize(0);
			for (int j = i; j <= n; j += k)
				cand.push_back(a[j]);
			s[0] = cand[0], all = cand[0];
			for (int i = 1; i < cand.size(); i ++) {
				s[i] = s[i - 1] + cand[i];
				all += cand[i];
			}
			int cost = 1e9;
			for (int i = cand.size() - 1; i >= 0; i --) {
				cost = min (cost + 1 - cand[i], 1 - cand[i] + all - s[i]);
				// cerr << i << " :: " << cost << endl;
				pans = min (pans, cost + (i == 0 ? 0 : s[i - 1]));
			}
			pans = min (pans, all);
			// cerr << i << " : " << pans << endl;
			fans = min (fans, pans + sum - all);
		}
		cout << fans << endl;
	}

	return 0;
}