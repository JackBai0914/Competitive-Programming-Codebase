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

ll v[100001];

int main() {
	srand(time(0));
	ios::sync_with_stdio(false);
	v[1] = v[2] = 1;
	for (int i = 3; i <= 10	; i ++) {
		for (int j = 1; j < i; j ++)
			(v[i] += (v[j]) * j) %= i;
		cerr << i << " : " << v[i] << endl;
	}
	// int T;
	// cin >> T;
	// while (T --) {
		
	// }
	return 0;
}