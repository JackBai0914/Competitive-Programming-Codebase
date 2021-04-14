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


int main() {
	srand(time(0));
	cin >> op_num;
	for (int t = 1; t <= 20; t ++) {
		stringstream I, O;
		I << "[";
		O << "[";
		priority_queue <int> q;
		int num = 0;
		for (int i = 1; i <= op_num; i ++) {
			int tp = rand() % 4;
			if (tp == 0 && q.empty())
				tp += 2;
			if (tp == 0) {
				I << "[\"get\"]";
				O << -q.top() << ", ";
				q.pop();
				num --;
			}
			if (tp == 1) {
				I << "[\"qsize\"]";
				O << num << ", ";
			}
			if (tp >= 2) {
				int x = rand() % 100 + 1;
				q.push(-x);
				num ++;
				I << "[\"put\", " << x << "]";
			}
			if (i != op_num)
				I << ", ";
		}
		I << "]";
		O << "]";
		cout << I.str() << endl;
		cout << O.str() << endl;
		cout << endl;
	}

	return 0;
}