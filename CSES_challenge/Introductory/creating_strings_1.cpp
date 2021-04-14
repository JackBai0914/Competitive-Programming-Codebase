#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int can[26];

vector <string> v;

int main() {
	std::ios::sync_with_stdio(false);
	string s;
	cin >> s;
	sort(s.begin(), s.end());

	do {
		v.push_back(s);
	} while (next_permutation(s.begin(), s.end()));

	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i ++)
		cout << v[i] << '\n';

	return 0;
}
