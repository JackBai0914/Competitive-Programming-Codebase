#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
using namespace std;

typedef long double ld;
typedef double db;
typedef float fl;
fl a, delt, ti, b;


int main() {
	cout << "size : " << sizeof(fl) << " " << sizeof(db) << " " << sizeof(ld) << endl;
	
	fl ini = 0, aft = 0;
	for (int i = 1; i <= 10000000; i ++) {
		aft = ini + (fl)1 / i;
		cout << fixed << setprecision(20) << aft << '\n';
		ini = aft;
	}
	/*
	for (int i = 1; i <= ti; i ++) {
		cout << fixed << setprecision(20) << a + i * delt << endl;
	}*/
	return 0;
}