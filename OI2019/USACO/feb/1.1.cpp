#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
typedef long double ld;
const ld eps = 1e-9;
int output(ld x) {return (int)((x + eps) * 1000000);}
int n;
ld p[1000010], fans = 0;

int main() {
	freopen("cowdate.in", "r", stdin);
	freopen("force.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> p[i], p[i] *= 0.000001;
	int j = 0;
	ld ans0 = 1, ans1 = 0;
	for (int i = 1; i <= n; i ++) {
		ld n0, n1;
		// cout << ": " << i << " " << j << " " << ans1 << endl;
		fans = max(fans, ans1);
		for (++ j; j <= n; j ++) {
			n1 = ans1 * (1.0 - p[j]) + ans0 * p[j];
			n0 = ans0 * (1.0 - p[j]);
			fans = max(fans, n1);
			// cout << ": " << i << " " << j << " " << n1 << endl;
			if (n1 < ans1) {
				j --;
				break;
			}
			ans1 = n1;
			ans0 = n0;
		}
		// cout << ans0 << " " << ans1 << endl;
		ans0 /= (1.0 - p[i]);
		ans1 = (ans1 - ans0 * p[i]) / (1.0 - p[i]);
		// cout << ans0 << " " << ans1 << endl;
	}
	cout << output(fans) << endl;
	return 0;
}


