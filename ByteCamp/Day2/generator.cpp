#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef pair <int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	freopen("test.in", "w", stdout);
	srand(time(0));

	cout << 1000 << endl;
	for (int i = 1; i <= 20; i ++)
		for (int j = 1; j <= 50; j ++) {
			cout << i * 20 + rand() % 5 << " " << j * 20 + rand() % 5 << " " << rand() % 5 + 1 << endl;
		}
	
	return 0;
}