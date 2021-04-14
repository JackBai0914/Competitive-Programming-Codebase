#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#define SQRT3 1.7320508075688772
#define SQRT2 1.4142135623730951
#define TIME (double)clock()/CLOCKS_PER_SEC
#define MP make_pair
#define F first
#define S second
using namespace std;
int N;
const int MX = 1010;
typedef long double ld;
typedef pair <ld, ld> P;
ld sqr(ld x) {return x * x;}
//self rand 
namespace RAND {
	typedef unsigned long long ull;
	ull Hash = 1000000007;
	int rand2() {
		// return rand();
		Hash = Hash * 2333 + 10000007;
		// if (Hash % RAND_MAX != 1)
		// cerr << Hash % RAND_MAX << endl;
		return Hash % RAND_MAX;
	}
} using namespace RAND;
ld Rand() {return (ld)rand2() / RAND_MAX;}
bool legal(P x) 
{return (x.S <= SQRT3 *(0.5 + x.F)
	  && x.S <= SQRT3 * (0.5 - x.F)
	  && x.S >= 0);}

P generate () {
	P ans;
	do {
		ans.F = Rand() - 0.5;
		ans.S = Rand();
	} while (!legal(ans));
	return ans;
}
P pt[MX], rec[MX], mv[MX];

int c[MX];
ld mx, ans1, ans2;

P cpy[MX];
ld dis (int x, int y) {return hypot(cpy[x].F - cpy[y].F, cpy[x].S - cpy[y].S);}
ld calc_dis() {
	ld mn = 100;
	bool ok = 1;
	for (int i = 0; i < N; i ++) {
		cpy[i] = pt[i];
		ok &= (i == 0 || pt[i] >= pt[i - 1]);
	}
	if (!ok)
		sort(cpy, cpy + N);
	for (int i = 0; i < N; i ++) {
		mn = min(mn, 2 * cpy[i].S);
		mn = min(mn, 2 * fabs(-cpy[i].F * SQRT3 * 0.5 + cpy[i].S * 0.5 - SQRT3 * 0.25));
		mn = min(mn, 2 * fabs(cpy[i].F * SQRT3 * 0.5 + cpy[i].S * 0.5 - SQRT3 * 0.25));
		for (int j = 0; j < i && cpy[j].F - cpy[i].F < mn; j ++)
				mn = min(mn, dis(i, j));
	}
	return mn;
}

P record[110][110];
ld Fans[110];
void output() {
//	cerr << "turn " << id << ", answer = " << ans1 << ", " << TIME << endl;
//	if (ans1 == mx) {
	// freopen("data.txt", "w", stdout);
	
	for (int N = 2; N <= 100; N ++) {
	cout << Fans[N] << endl;
	cout << "[";
	for (int i = 0; i < N - 1; i ++) cout << record[N][i].F << ",";
	cout << record[N][N - 1].F << "], " << "[";
	for (int i = 0; i < N - 1; i ++) cout << record[N][i].S << ",";
	cout << record[N][N - 1].S << "]";
	cout << endl;
	}
	// fclose(stdout);
//	}
}


int main() {
	srand(time(0));
	cout << fixed << setprecision(9);
	cerr << fixed << setprecision(9);
	// for (int NN = 2; NN <= 50; NN ++) {
	// cerr << "doing " << NN << endl;
	// N = NN;
	cin >> N;
	const ld ADJ = 1;
	mv[0] = MP(ADJ, ADJ);
	mv[1] = MP(-ADJ, ADJ);
	mv[2] = MP(ADJ, -ADJ);
	mv[3] = MP(-ADJ, -ADJ);
	mv[4] = MP(ADJ, 0);
	mv[5] = MP(-ADJ, 0);
	mv[6] = MP(0, ADJ);
	mv[7] = MP(0, -ADJ);
	mv[8] = MP(0, 0);
	mx = 0;
	//following is the Simulated Annealing Algorithm.
	int cnt = 0;
	do {
		cnt ++;
		
		for (int i = 0; i < N; i ++)
			pt[i] = generate();
		ans1 = calc_dis();
		ld Tmx = 1e-3, Tmin = 1e-9, delta = pow(0.9999999, N);
		int cntt = 0;
		for (ld T = Tmx; T >= Tmin; T *= delta) { //T is temperature
			ld C = T * N / 2;
			if (C < 0.000001 * N / 2)	C = 0.000001 * N / 2;
			else						C *= Rand();
			if ((++ cntt) % 1000 == 0)
				cout << T << " " << C << " " << ans1 << endl;
			for (int i = 0; i < N; i ++) {
				c[i] = rand2() % (8 * (N + 10) / 5);
				if (T < 0.00000001)
					c[i] = rand2() % (8 * N / 3);
				if (c[i] < 8) {
					pt[i].F += mv[c[i]].F * C;
					pt[i].S += mv[c[i]].S * C;
					if (!legal(pt[i])) {
						pt[i].F -= mv[c[i]].F * C;
						pt[i].S -= mv[c[i]].S * C;
						c[i] = 8;
						continue ;
					}
				}
			}
			ans2 = calc_dis();
			ld dE = ans2 - ans1;
			if (dE > 0 || exp(dE / T) >= Rand()) { // metropolis principle
				// cout << ans1 << " -> " << ans2 << endl;
				ans1 = ans2;
			}
			else {
				for (int i = 0; i < N; i ++) {
					pt[i].F -= mv[c[i]].F * C;
					pt[i].S -= mv[c[i]].S * C;
				}
			}
			if (ans1 > mx) {
				mx = ans1;
				for (int i = 0; i < N; i ++)
					rec[i] = pt[i];
			}
		}
		cerr << "SA " << cnt << " " << ans1 << endl;
	} while(cnt <= 2);
	for (int i = 0; i < N; i ++) {
		record[N][i] = rec[i];
		Fans[N] = mx;
	}
	// }
	// output();
	return 0;
}