#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <complex>
#define PI 3.1415926535898
using namespace std;
typedef long double ld;
const ld eps = 1e-8;
int n, N;
complex <ld> x[600060], y[600060], z[600060];

int rev[600060];
void ini () {
	for (int i = 1; i < N; i ++)
		rev[i] = ((rev[i >> 1] >> 1) | ((i & 1) ? (N >> 1) : 0));
}

void FFT (complex <ld> *f, int inv)
{
	for (int i = 0; i < N; i ++)
		if (i < rev[i])
			swap(f[i], f[rev[i]]);
	for (int i = 1; i < N; i <<= 1) {
		complex <ld> w(cos(PI / i), sin(PI / i) * inv);
		for (int j = 0; j < N; j += (i << 1)) {
			complex <ld> wn(1, 0);
			for (int k = 0; k < i; k ++) {
				complex<ld> x = f[j + k], y = f[j + k + i] * wn;
				f[j + k] = x + y;
				f[j + k + i] = x - y;
				wn *= w;
			}
		}
	}
	if (inv == -1)
		for (int i = 0; i < N; i ++)
			f[i] /= N;
}

long long ans[600060];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	char v;
	for (int i = n - 1; i >= 0; i --)	cin >> v, x[i].real(v - '0');
	for (int i = n - 1; i >= 0; i --)	cin >> v, y[i].real(v - '0');
	for (N = 1, n <<= 1; N <= n; N <<= 1);

	// for (int i = 0; i < N; i ++)	cout << x[i] << " ";	cout << endl;
	// for (int i = 0; i < N; i ++)	cout << y[i] << " ";	cout << endl;
	ini();
	FFT(x, 1);
	FFT(y, 1);
	for (int i = 0; i < N; i ++)
		z[i] = x[i] * y[i];
	FFT(z, -1);
	// for (int i = 0; i < N; i ++)	cout << z[i] << " ";	cout << endl;
	for (int i = 0; i < N; i ++) {
		ans[i] += (int)(z[i].real() + 0.5);
		ans[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}
	int mx;
	for (mx = N - 1; !ans[mx]; mx --);
	// for (int i = N - 1; i >= 0; i --)
		// cout << ans[i] << " ";
	// cerr << "mx : " << mx << endl;
	for (int i = mx; i >= 0; i --)
		cout << ans[i];
	cout << endl;
	return 0;
}