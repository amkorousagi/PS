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
	int n, m;
	cin >> n >> m;

	int mmax = -1;
	v.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int a;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int l = j + 1; l < n; l++) {
				a = v[i] + v[j] + v[l];
				if (mmax < a && a <= m) {
						mmax = a;
				}
			}
		}
	}
	cout << mmax;
	return 0;
}