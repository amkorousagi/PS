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

int main(void) {
	fastio;
	int n;
	int nn = 0;
	cin >> n;
	for (long i = 0;; i++) {
		string s = to_string(i);
		int cnt = 0;
		int p = -1;
		bool t = false;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '6') {
				if (cnt == 0) {
					cnt++;
					p = j;
				}
				else {
					if (p + 1 == j) {
						cnt++;
						p = j;
					}
					else {
						cnt = 1;
						p = j;
					}
				}
			}
			if (cnt == 3) {
				t = true;
				break;
			}
		}
		if (t) {
			nn++;
			if (nn == n) {
				cout << i;
				break;
			}
		}
	}

	return 0;
}