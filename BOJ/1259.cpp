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

	for (;;) {
		string s;
		cin >> s;
		if (s == "0") {
			return 0;
		}
		bool f = true;
		for (int i = 0; ; i++) {
			if (i >= (signed int)(s.size()) - 1 - i) {
				break;
			}
			if (s[i] != s[s.size() - 1 - i]) {
				f = false;
				break;
			}
		}

		if (f) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
	

	return 0;
}