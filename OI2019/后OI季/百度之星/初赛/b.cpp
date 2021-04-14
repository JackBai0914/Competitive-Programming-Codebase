#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii; 

int n;
struct block {int st, ed;} b[1010];
int val[1010][2][2];

int dis (int st, int ed) {return (abs(st - ed) + 1) / 2;}

int main() {
	srand(time(0));
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T --) {
		memset(val, 0, sizeof val);
		cin >> n;
		int pans[2][2];
		int cans[2][2];
		pans[0][0] = pans[0][1] = pans[1][0] = pans[1][1] = 0;


		int stt = 0, edd = 2e9;
		for (int i = 1; i <= n; i ++) {
			cin >> b[i].st >> b[i].ed;
			int st = b[i].st;
			int ed = b[i].ed;
			

			
			if (max(stt, st) <= min(ed, edd)) {
				stt = max(stt, st);
				edd = min(ed, edd);
				continue ;
			}
			if (stt <= edd && max(stt, st) > min(ed, edd)) {
				val[i - 1][0][0] = stt;
				val[i - 1][0][1] = min(stt + 1, edd);
				val[i - 1][1][0] = edd;
				val[i - 1][1][1] = max(edd - 1, stt);
				stt = max(stt, st);
				edd = min(ed, edd);
			}
			// cerr << "here ? " << stt << " " << edd << endl;
			
			val[i][0][0] = st;
			val[i][0][1] = min(st + 1, ed);
			val[i][1][0] = ed;
			val[i][1][1] = max(ed - 1, st);

			
			for (int v1 = 0; v1 <= 1; v1 ++)
				for (int v2 = 0; v2 <= 1; v2 ++) {
					cans[v1][v2] = 2e9;
					for (int v3 = 0; v3 <= 1; v3 ++)
						for (int v4 = 0; v4 <= 1; v4 ++)
							cans[v1][v2] = min(cans[v1][v2], pans[v3][v4] + dis (val[i - 1][v3][v4], val[i][v1][v2]));
				}
			pans[0][0] = cans[0][0];
			pans[0][1] = cans[0][1];
			pans[1][0] = cans[1][0];
			pans[1][1] = cans[1][1];
		}
		cout << min (min(pans[0][0], pans[0][1]), min(pans[1][0], pans[1][1])) << endl;
	}
	return 0;
}