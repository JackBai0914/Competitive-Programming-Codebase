#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <stack>
#include <sstream>
using namespace std;

int op_num;

char rand_ch () {return (char)('a' + rand() % 26);}

int main() {
	srand(time(0));
	cin >> op_num;
	for (int t = 1; t <= 10; t ++) {
		stringstream I, O;
		I << "[";
		stack <string> q;
		int num = 0;
		for (int i = 1; i <= op_num; i ++) {
			int tp = rand() % 3;
			if (tp == 0 && q.empty())
				tp += 2;
			if (tp == 0) {
				I << "[\"get\"]";
				O << "\"" << q.top() << "\", ";
				q.pop();
				num --;
			}
			if (tp == 1) {
				I << "[\"qsize\"]";
				O << num << ", ";
			}
			if (tp == 2) {
				int sz = rand() % 4 + 1;
				string x;
				for (int j = 1; j <= sz; j ++)
					x += rand_ch();
				I << "[\"put\", \"" << x << "\"]";
				q.push(x);
				num ++;
			}
			if (i != op_num)
				I << ", ";
		}
		I << "]";
		cout << I.str() << endl;
		cout << O.str() << endl;
		cout << endl;
	}

	return 0;
}