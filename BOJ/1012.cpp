/**
 * @template file author kadrick (kbk2581553@gmail.com)
 *
 * author:amkorousagi (hasmi5452@gmail.com)
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'
int n, m;
int go[51][51];
int flag[51][51];
int cnt;

void dfs(int x, int y) {
	if (x < 0 || x >= m || y < 0 || y >= n) return;
	if (go[x][y] == 0) return;
	if (flag[x][y] != 0) return;

	cnt++;
	flag[x][y] = 1;
	dfs(x + 1, y);
	dfs(x, y + 1);
	dfs(x - 1, y);
	dfs(x, y - 1);
}

int main(void) {
	fastio;
	int t,k,a,b;
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		cin >> m >> n >> k;
		memset(go, 0, sizeof(int) * 51 * 51);
		memset(flag, 0, sizeof(int) * 51 * 51);
		for (int kk = 0; kk < k; kk++) {
			cin >> a >> b;
			go[a][b] = 1;
		}
		int nabi = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cnt = 0;
				dfs(i, j);
				if (cnt > 0) {
					nabi++;
				}
			}
		}
		cout << nabi<<endl;
	}

	return 0;
}