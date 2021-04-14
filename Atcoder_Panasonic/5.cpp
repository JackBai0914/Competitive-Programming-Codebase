#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
int fans = 1e9;
const int C = 2000;
const int D = C * 2;

bool equal (char x, char y)
{return x == '?' || y == '?' || x == y;}

string a, b, c;
bool mat[3][10010];

int main() {
	ios::sync_with_stdio(false);
	cin >> a >> b >> c;
	
	//fix a, move b
	for (int i = -2 * C; i <= 2 * C; i ++) {
		mat[0][i + D] = true;
		for (int j = 0; j < b.size(); j ++)
			mat[0][i + D] &= (i + j < 0 || i + j >= a.size() || equal (a[i + j], b[j]));
	}

	//fix a, move c
	for (int i = -2 * C; i <= 2 * C; i ++) {
		mat[1][i + D] = true;
		for (int j = 0; j < c.size(); j ++)
			mat[1][i + D] &= (i + j < 0 || i + j >= a.size() || equal (a[i + j], c[j]));
	}

	//fix b, move c
	for (int i = -2 * C; i <= 2 * C; i ++) {
		mat[2][i + D] = true;
		for (int j = 0; j < c.size(); j ++)
			mat[2][i + D] &= (i + j < 0 || i + j >= b.size() || equal (b[i + j], c[j]));
	}

	for (int i = -2 * C; i <= 2 * C; i ++)
		for (int j = -2 * C; j <= 2 * C; j ++)
			if (abs (i - j) <= 2 * C) 
				if (mat[0][i + D] && mat[1][j + D] && mat[2][j - i + D]) {
					int st = min (0, min (i, j));
					int ed = max ((int)a.size(), max (i + (int)b.size(), j + (int)c.size()));
					fans = min (fans, ed - st);
					// if (ed - st == 3) {
						// cerr << ": " << i << " " << b.size() << " " << i + (int)b.size() << " " << j + c.size() << endl;
						// cerr << i << " " << j << " " << st << " " << ed << endl;
					// }
				}

	cout << fans << endl;
	return 0;
}