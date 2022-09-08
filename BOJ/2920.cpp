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
	int a[8];
	int s = 0;

	for (int i = 0; i < 8; i++) {
		cin >> a[i];
		if (i == 0) {
			if (a[0] == 8) { s = -1; }
			else if (a[0] == 1) { s = 1; }
			else {
				cout << "mixed";
				return 0;
			}
		}

		if (s == 1 && a[i] == i + 1) {
			continue;
		}
		else if (s == -1 && a[i] == 8 - i) {
			continue;
		}
		else {
			cout << "mixed";
			return 0;
		}
	}
	if (s == 1) cout << "ascending";
	if (s == -1) cout << "descending";


	return 0;
}