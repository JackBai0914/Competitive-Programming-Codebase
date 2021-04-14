#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
typedef  double ld;
const ld PI = 3.1415926535897;
int n;
ld r;


int main() {
	//ios::sync_with_stdio(false);
	cin >> n >> r;
	ld ans = (r * sin(PI / n)) / (1 - sin(PI / n));
	printf("%.10lf\n", ans);
	return 0;
}