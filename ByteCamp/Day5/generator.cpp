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
	for (int i = 0; i < (1<<14); i ++) {
		for (int j = 0, k = i; j < 50; j ++, k >>= 1)
			cout << rand()%2;
		cout << endl;
	}
	return 0;
}