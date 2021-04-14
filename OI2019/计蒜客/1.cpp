#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;

string x = "A*B";
string y = "B*C";
string z = "A*C";

int main() {
	ios::sync_with_stdio(false);
	ll b;
	cin >> b;
	if (b == 0)	cout << x << " " << y << endl;
	if (b > 0)	cout << y << endl;
	if (b < 0)	cout << x << endl;
	return 0;
}