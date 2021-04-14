#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
using namespace std;
typedef long long ll;

int n, I, a[1000010];
int L;

vector <int> v;

int pans = 0, fans = 0;

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> I;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];

	(I *= 8) /= n;
	if (I > 30) {
		cout << 0 << endl;
		return 0;
	}
	L = (1 << I);


	int mx = 0;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) {
		int j = i;
		while (j + 1 <= n && a[j + 1] == a[i])
			j ++;
		int num = j - i + 1;
		v.push_back(num);

		pans += num;
		if (v.size() > L)
			pans -= v[v.size() - 1 - L];
		// cerr << num << " " << pans << endl;
		fans = max (fans, pans);
		i = j;
	}
	cout << n - fans << endl;
	return 0;
}