#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

long long x;
vector <int> f;
vector <long long> ans;

long long solve(int g)
{
	return x / g + (x - g) * x / 2 / g;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> x;
	for (int i = 1; i * i <= x; i ++) {
		if (x % i == 0) {
			f.push_back(i);
			if (i * i != x)
				f.push_back(x / i);
		}
	}
	for (int i = 0; i < f.size(); i ++)
		ans.push_back(solve(f[i]));
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i ++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
