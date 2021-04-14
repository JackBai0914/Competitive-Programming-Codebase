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

const int si = (1<<19);
int rt[si];
string p;

ld sum[110][110];
int num[110][110];


int main() {
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	freopen("4.out", "w", stdout);
	cin >> p;
	p=p.substr(0, 11000);
	// for (int i = 0; i < p.size(); i ++)
		// swap (p[i], p[(i * 2 + 233) % p.size()]);
	string ans;
	for (int i = 0; i < p.size(); i += 13) {
		int rd = 0; 
		for (int j = 0; j < 13 && i + j < p.size(); j ++) {
			rd = (rd * 233 + (p[i+j] == '1')) % 10007;
		}
		ans += (char)(rd % 50 + 40);
	}
	cout << ans;
/*
	for (int i = 0; i < (1<<14); i ++) {
		if (i % 10000 == 0)
			cerr << ": " << i << endl;
		for (int j = 0; j < (1<<14); j ++) {
			int ni = 0, nj = 0, ii = i, jj = j, com = 0;
			for (int k = 0; k < 13; k ++) {
				ni+=ii%2, nj+=jj%2;
				com += (ii%2==jj%2);
				ii/=2, jj/=2;
			}
			num[ni][nj] ++;
			sum[ni][nj] += com;
		}
	}
	for (int i = 0; i < 14; i ++) {
		for (int j = 0; j < 14; j ++)
			cout << (int)(sum[i][j]/num[i][j]*10) << ",";
		cout << endl;
	}
*/
	return 0;
}