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

vector<int> v;
int main(void) {
	fastio;
	
	int t;
	cin >> t;
	int a, b;
	
	for (int tt = 0; tt < t; tt++) {
		cin >> a >> b;
		vector<vector<int>> v(a + 1, vector<int>(b + 1,0));
		for (int i = 0; i <= a; i++) {
			for (int j = 1; j <= b; j++) {
				if (i == 0) {
					v[i][j] = j;
				}
				else {
					v[i][j] = v[i][j - 1] + v[i - 1][j];
				}
			}
		}
		cout << v[a][b] << endl;
	}
	return 0;
}