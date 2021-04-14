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



int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	freopen("inp.in", "w", stdout);
	srand(time(0));
	for (int t = 1; t <= 500; t ++) {
		const int n = 100;
		int L = 30;
		cout << n << " " << L << endl;
		for (int i = 1; i <= n; i ++)
			cout << rand() % 1000000000 + 1 << " ";
		cout << endl;
	}
	
	return 0;
}