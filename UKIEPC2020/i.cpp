#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn], pos[maxn];
bool mark[maxn];
int tmp[maxn];
bool cmp(int x, int y)
{
	return a[x] < a[y];
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		pos[a[i]] = i;
	}
	cout << 3 << endl;

	for(int i = 1; i <= n; i ++)
		mark[i] = 0;
	int cnt = 0;
	for(int i = 1; i <= n / 4; i ++)
	{
		tmp[++ cnt] = i;
		mark[i] = 1;
	}
	for(int i = 1; i <= n / 4; i ++)
		if(pos[i] > n / 4)
		{
			tmp[++ cnt] = pos[i];
			mark[pos[i]] = 1;
		}
	for(int i = n / 4 + 1; i <= n; i ++)
		if(!mark[i] && cnt < n / 2)
		{
			tmp[++ cnt] = i;
			mark[i] = 1;
		}
	for(int i = 1; i <= cnt; i ++)
		cout << tmp[i] << " ";
	cout << endl;
	sort(tmp + 1, tmp + cnt + 1, cmp);
	cnt = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(mark[i])
			b[i] = a[tmp[++ cnt]];
		else
			b[i] = a[i];
	}
	for(int i = 1; i <= n; i ++)
	{
		a[i] = b[i];
		pos[a[i]] = i;
	}

	for(int i = 1; i <= n; i ++)
		mark[i] = 0;
	cnt = 0;
	for(int i = n / 4 + 1; i <= n / 2; i ++)
	{
		tmp[++ cnt] = i;
		mark[i] = 1;
	}
	for(int i = n / 4 + 1; i <= n / 2; i ++)
		if(pos[i] > n / 2)
		{
			tmp[++ cnt] = pos[i];
			mark[pos[i]] = 1;
		}
	for(int i = n / 2 + 1; i <= n; i ++)
		if(!mark[i] && cnt < n / 2)
		{
			tmp[++ cnt] = i;
			mark[i] = 1;
		}
	for(int i = 1; i <= cnt; i ++)
		cout << tmp[i] << " ";
	cout << endl;

	for(int i = n / 2 + 1; i <= n; i ++)
		cout << i << " ";
	cout << endl;

	return 0;
}