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

int num = 0;
ll k;

ll N, a[5000050], b[5000050], v[5000050];
ll val[5000050];


void next() {
	ll num = 0;
	while (true) {
		int op = 0;
		for (int i = 1; i <= N; i ++)
			if (val[i] == i) {
				for (int j = 1; j < i; j ++)
					val[j] ++;
				val[i] = 0;
				op = 1;
				num ++;
				break ;
			}
		if (!op)
			break;
	}
	bool zero = true;
	for (int i = 1; i <= N; i ++)
		zero &= (val[i] == 0);
	cerr << "test: " << num-N << " zero: " << zero << endl;
}


pair <ll, ll> calc (int n) {
	for (int i = 1; i <= n; i ++)
		a[i] = b[i] = v[i] = 0;
	a[n] = b[n] = 1;
	v[n] = n;
	ll suma = 1, sumb = 1;
	for (int i = n - 1; i >= 1; i --) {
		ll numa = suma / i + (suma % i != 0);
		ll numb = sumb / i + (sumb % i != 0);
		ll cp = sumb;
		v[i] = i - sumb%i;
		a[i] = numa, suma += numa;
		b[i] = numb, sumb += numb;
		if (cp % i == 0)
			sumb ++, b[i] ++;
	}
	return MP(suma - n, sumb - n);
}

ll dfs (int n, ll sum, int fix) { //fix: 0, -1, 1
	if (sum > k)
		return sum;
	if (n == 0)
		return sum;
	while (n) {
		// cerr << "dealing " << n << " : " << val[n + 1] << endl;
		if (sum % n != 0) {
			val[n] = n - sum%n;
			sum += sum/n + 1;
			n --;
			continue ;
		}
		else {
			if (fix == -1) {
				val[n] = 0;
				sum += sum / n;
				n --;
				continue ;
			}
			if (fix == 1) {
				val[n] = n;
				sum += sum / n + 1;
				n --;
				continue ;
			}
			if (fix == 0) {
				val[n] = 0;
				sum += sum / n;
				ll test = dfs (n - 1, sum, 1);
				if (test == k) {
					for (int i = 1; i <= N; i ++)
						cout << val[i] << ' ';
					cout << endl;
					// next();
					exit(0);
				}
				if (test < k) {
					val[n] = n;
					sum ++;
				}
				n --;
				continue ;
			}
		}
	}
	return sum;
}


int main() {
	ios::sync_with_stdio(false);
	cin >> k;
	int st = 1, ed = 2e6;
	while (st != ed) {
		int mid = (st + ed) >> 1;
		pair <ll, ll> cur = calc (mid);
		if (cur.S < k)	st = mid + 1;
		else			ed = mid;
	}
	N = st;
	cout << N << endl;
	k += N;
	val[N] = N;
	dfs (N - 1, 1, 0);
	for (int i = 1; i <= N; i ++)
		cout << val[i] << ' ';
	cout << endl;
	// next();

	return 0;
}