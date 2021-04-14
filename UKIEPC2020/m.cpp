#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int MOD = 1000000007; 
const ll INF = 1e18;
const ld eps = 1e-8;

int n;
int a[100010], b[100010], c[100010];

int s[4];


int main() {
	ios::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	if (a == 1)
		cout << b << endl;
	else
		cout << a + b << endl;
    return 0;
}