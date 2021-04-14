#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mx = 2e6 + 10;
ll n, a[mx], b[mx];
string fans = "";
//fans ==> final_ans

void outp() {
	//since we are changing b to a and the task requires changing a to b, the whole operation queue (fans) should be reversed when outputted.
	reverse(fans.begin(),fans.end());
	int num = count(fans.begin(), fans.end(), 'P');
	if (num > 200000)	cout << "BIG" << '\n' << num << '\n';
	else				cout << "SMALL" << '\n' << fans.size() << '\n' << fans << '\n';
	exit(0);
}

//this function checks if array a equals to array b. If so, we add string s (representing some operations) to fans.
void if_equal (string s) {
	for (int i = 1; i <= n; i ++)
		if (a[i] != b[i])
			return ;
	fans += s;
	outp();
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i ++)	cin >> a[i];
	for (int i = 1; i <= n; i ++)	cin >> b[i];

	//the following four lines check "if b equals a" and "if b equals to a in reversed order".
	if_equal("");
	reverse(b + 1, b + n + 1);
	if_equal("R");
	reverse(b + 1, b + n + 1);

	ll ti = 0;
	//the following loop simulates the first 2000000 'P' operations to change b to a.
	while ((ti ++) < 2000000) {
		if (b[1] > b[2]) {
			//if b[1] > b[2], we know for certain that 'R' must be operated before 'P', so that we don't get negative numbers.
			fans += 'R';
			reverse(b + 1, b + n + 1);
		}

		//doing operation 'P'.
		fans += 'P';
		for (int i = n; i >= 2; i --)
			b[i] -= b[i - 1];

		//checking if b is still legal.
		for (int i = 1; i <= n; i ++)
			if (b[i] <= 0) {
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}

		//checking "if b equals a" and "if b equals to a in reversed order".
		if_equal("");
		reverse(b + 1, b + n + 1);
		if_equal("R");
		reverse(b + 1, b + n + 1);
	}
	ti --;

	//when the program reaches this place, it means that t (same meaning as the tutorial mensioned) is larger than 2000000, which also means that n = 2.
	//the following process is nothing different from what the tutorial said. We just calculate the first 2000000 'P' in brutal-forced way, and it doesn't influence the answer.

	//n=2
	ll x = b[1], y = b[2];
	if (a[1] > a[2])	
		swap (a[1], a[2]);
	while (true) {
		if (x < y)
			swap (x, y);
		if (y == 0) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		if (a[1] == y) {
			if ((x - a[2]) % y != 0 || x < a[2])
				cout << "IMPOSSIBLE" << endl;
			else 
				cout << "BIG" << endl << ti + (x - a[2]) / y << endl;
			return 0;
		}	
		ti += x / y;
		x -= x / y * y;
	}
	// cout << "WTF " << endl;
	return 0;
}