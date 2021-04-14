

void dfs (int n, ull k) {
	if (!n)
		return ;
	ull v = (1 << (n - 1));
	if (k >= v) {
		cout << 1;
		dfs (n - 1, v - (k - v) - 1);
	}
	else {
		cout << 0;
		dfs (n - 1, k);
	}
}