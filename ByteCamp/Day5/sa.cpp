/*
 * Code Info
 * This is a code for D
 * starting date: 2017/_/_
 *algorithm :suffix array
 *ac mark:
 *note:

 */
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;

string s;
int sa[100010], rk[100010], height[100010], h[100010];
namespace sorte
{
	int r[100010], yy[100010], bar[100010], fp[100010];
	bool cmp(int *ary, int pos1, int pos2, int bt)
	{return ary[pos1] == ary[pos2] && ary[pos1 + bt] == ary[pos2 + bt];}
	void main(string s, int n, int m)
	{
		for (int i = 0; i < s.size(); i ++)
			r[i] = s[i] - 'a' + 1;
		int *x = rk, *y = yy;
		for (int i = 0; i < m; i ++)	bar[i] = 0;
		for (int i = 0; i < n; i ++)	bar[x[i] = r[i]] ++;
		for (int i = 1; i < m; i ++)	bar[i] += bar[i - 1];
		for (int i = 0; i < n; i ++)	sa[--bar[x[i]]] = i;
		for (int j = 1, p = 1; p < n; j <<= 1, m = p) {
			p = 0;
			for (int i = n - j; i < n; i ++)	y[p ++] = i;
			for (int i = 0; i < n; i ++)
				if (sa[i] >= j)
					y[p ++] = sa[i] - j;
			for (int i = 0; i < n; i ++)	fp[i] = x[y[i]];
			for (int i = 0; i < m; i ++)	bar[i] = 0;
			for (int i = 0; i < n; i ++)	bar[fp[i]] ++;
			for (int i = 1; i < m; i ++)	bar[i] += bar[i - 1];
			for (int i = n - 1; i >= 0; i --)	sa[--bar[fp[i]]] = y[i];
			swap(x, y);
			x[sa[0]] = 0, p = 1;
//			cout << "here!!!!!!!!!!!  " << sa[1] << endl;
			for (int i = 1; i < n; i ++)
				x[sa[i]] = (cmp(y, sa[i], sa[i - 1], j) ? p - 1 : p ++);
		}
		for (int i = 0; i <= n; i ++)
			rk[i] = x[i];
	}
}
void counting_height()
{
	for (int i = 0; i < s.size(); i ++) {
		h[i] = max(h[i - 1] - 1, 0);
	//	cout << "compareing " << s.substr(i) << " " << s.substr(sa[rk[i] - 1]) << endl;
//		cout << rk[i] << " " << sa[rk[i] - 1] << endl;
	//	cout << "initial h[] " << h[i] << endl;
		while (s[i + h[i]] == s[sa[rk[i] - 1] + h[i]])	h[i] ++;
				// cout << ".." << s[i + h[i]] << ".. .." << s[sa[rk[i] - 1] + h[i]] << endl;
	//	cout << "result " << h[i] << endl;
	}
	for (int i = 0; i < s.size(); i ++)	height[rk[i]] = h[i];
}
int main()
{
 	ios::sync_with_stdio(false);
 	while (cin >> s) {
		sorte::main(s, s.size() + 1, 27);
		for (int i = 1; i <= s.size(); i ++)
			cout << sa[i] + 1 << " ";
		cout << endl;
	}
	
	return 0;
}
/*
*/

