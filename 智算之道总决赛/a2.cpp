#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <map>
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int q;
string s, t;
int main() {
	ios::sync_with_stdio(false);
	
	q = 1;
	s = "";
	for (int i = 0; i < 200000; i ++)
		s += (char)(rand() % 26 + 'a');

	t = "";
	for (int i = 0; i < 100000; i ++)
		t += (char)(rand() % 26 + 'a');
	cout << s << endl << q << endl << t << endl;
	return 0;
}