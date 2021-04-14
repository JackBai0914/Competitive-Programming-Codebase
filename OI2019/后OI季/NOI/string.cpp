#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <vector>
#include "combo.h"
using namespace std;
string op[4] = {"A", "B", "X", "Y"};
int n;
string c = "";

string guess_sequence(int N) {
	n = N;
	for (int i = 1; i <= n; i += 2) {
		if (i == 1) {
			if (press (op[0] + op[1])) {
				if (press (op[0]))	c += op[0];
				else				c += op[1];
			}
			else {
				if (press (op[2]))	c += op[2];
				else				c += op[3];
			}
			for (int j = 0; j < 4; j ++)
				if (op[j] == c) {
					swap (op[j], op[3]);
					break;
				}
			i --;
		}
		else if (i == n) {
//			cerr << "this step " << i << " " << N << " " << press (c + op[0] + c + op[1]) << " " << press (c + op[0]) << endl;
//			cerr << "info " << c[0] << " " << c[1] << " " << c[2] << " " << c[3] << endl;
			if (press (c + op[0] + c + op[1]) == n) {
				if (press (c + op[0]) == n)	c += op[0];
				else					c += op[1];
			}
			else {
				c += op[2];
			}
		}
		else {
			int a1 = press (c + op[0] + op[0] + c + op[0] + op[1] + c + op[1] + op[0]);
			if (a1 == i - 1) {
				c += op[2];
				i --;
			}
			else if (a1 == i + 1) {
				int a2 = press(c + op[0] + op[0]);
				if (a2 == i - 1)	c += op[1] + op[0];
				if (a2 == i)		c += op[0] + op[1];
				if (a2 == i + 1)	c += op[0] + op[0];
			}
			else {
				int a2 = press(c + op[1] + op[1]);
				if (a2 == i - 1)	c += op[0] + op[2];
				if (a2 == i)		c += op[1] + op[2];
				if (a2 == i + 1)	c += op[1] + op[1];
			}
		}
	}

	// cerr << "take the guess: " << c << endl;
	return c;
}
