#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;

namespace Input_Opt {
	namespace Input {
		const int BUF = 65536;
		char buf[BUF];
		char *head = buf, *tail = buf;
	}
	inline char inputchar() {
		using namespace Input;
		if (head == tail)
			*(tail = (head = buf) + fread(buf, 1, BUF, stdin)) = 0;
		return *head ++;
	}
	inline void inputint(int &x) {
		x = 0;
		bool neg = 0;
		char c = inputchar();
		while (!isdigit(c) && c != '-')
			c = inputchar();
		if (c == '-')
			neg = 1, c = inputchar();
		while (isdigit(c))
			x = x * 10 + c - '0', c = inputchar();
		if (neg)
			x = -x;
	}
}using namespace Input_Opt;

int n, m;
int b[110];
bool flag[1000010];

int fans = 0;

int main() {
	ios::sync_with_stdio(false);
	inputint(n);
	inputint(m);
	fans = n;
	for (int i = 1; i <= m; i ++) {
		inputint(b[i]);
		for (int j = b[i]; j <= n; j += b[i]) {
			fans -= (flag[j] == 0);
			flag[j] = 1;
		}
	}	
	cout << fans << endl;
	return 0;
}