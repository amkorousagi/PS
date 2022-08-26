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
	int e, s, m;
	cin >> e >> s >> m;

	int ee, ss, mm;
	ee = ss = mm =0;

	for (int i = 1;; i++) {
		if (ee+1 == e && ss+1 == s && mm+1 == m) {
			cout << i;
			break;
		}

		ee = (ee + 1) % 15;
		ss = (ss + 1) % 28;
		mm = (mm + 1) % 19;
	}

	return 0;
}