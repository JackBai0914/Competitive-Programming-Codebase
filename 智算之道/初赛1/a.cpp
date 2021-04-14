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
	inline void inputstring(string &x) {
		x = "";
		bool neg = 0;
		char c = inputchar();
		while (!isalpha(c) && !isdigit(c))
			c = inputchar();
		while (isalpha(c) || isdigit(c))
			x = x + c, c = inputchar();
	}
}

int n;
string s;

int inv = 0;

int main() {
	ios::sync_with_stdio(false);
	Input_Opt::inputint(n);
	Input_Opt::inputstring(s);
	for (int i = s.size() - 1; i >= 0; i --) {
		if ((s[i] - '0' + inv) % 2) {
			inv ++;
		}
	}
	cout << inv << endl;
	return 0;
}