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
	int a[3];
	for (;;) {
		cin >> a[0] >> a[1] >> a[2];
		if (a[0] == 0 && a[1] == 0 && a[2] == 0) break;

		int sum = 0;
		sum = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];

		if (sum == 2 * a[0] * a[0]) {
			cout << "right" << endl;
		}
		else if (sum == 2 * a[1] * a[1]) {
			cout << "right" << endl;
		}
		else if (sum == 2 * a[2] * a[2]) {
			cout << "right" << endl;
		}
		else {
			cout << "wrong" << endl;
		}
	}



	return 0;
}