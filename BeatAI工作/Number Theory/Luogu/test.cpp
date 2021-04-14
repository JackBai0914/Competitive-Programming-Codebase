#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

int lst[20000020];

int f(int x) {return x*(x-1)/2;}

int main() {
	const int lim = 50;
	for (int i = 1; i <= lim; i ++)
		for (int j = i; j <= lim; j ++)
			for (int k = j; k <= lim; k ++)
				for (int x = i + 1; x <= lim; x ++)
					for (int y = i + 1; y <= lim; y ++) {
						int z = i + j + k - x - y;
						if (x < 0)
							continue;
						if (f(i) + f(j) + f(k) == f(x) + f(y) + f(z)) {
							cout << "find! " << i << " " << j << " " << k << " " << x << " " << y << " " << z << endl;
							cout << ":  " << f(i) << " " << f(j) << " " << f(k) << " " << f(x) << " " << f(y) << " " << f(z) << endl;
						}
					}

	return 0;
}

	