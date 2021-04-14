#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
using namespace std;

const int maxn = 600002;

int n, len;
char str[maxn];
int cnt5;
int pos5[maxn];
int ans[maxn][6];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", str + 1);
		n = strlen(str + 1) / 6;
		len = 6 * n;
		cnt5 = 0;
		set<int> s1, s4;
		for (int i = 1; i <= len; i++) {
			if (str[i] == '1') s1.insert(i);
			if (str[i] == '4') s4.insert(i);
			if (str[i] == '5') pos5[++cnt5] = i;
		}
		for (int i = 1; i <= n; i++) {
			ans[i][3] = pos5[i];
			set<int>::iterator it = s1.begin();
			it++;
			ans[i][2] = *(s4.lower_bound(*it));
			s4.erase(ans[i][2]);
			ans[i][1] = *it;
			it--;
			ans[i][0] = *it;
			s1.erase(ans[i][0]);
			s1.erase(ans[i][1]);
		}
		for (int i = 1; i <= n; i++) {
			ans[i][4] = *(s1.lower_bound(ans[i][3]));
			s1.erase(ans[i][4]);
			ans[i][5] = *(s4.lower_bound(ans[i][4]));
			s4.erase(ans[i][5]);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 6; j++) {
				printf("%d ", ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}