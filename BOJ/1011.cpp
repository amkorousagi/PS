/**
 * @file template.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-11-18 16:29
 *
 * @copyright Copyright (c) 2021
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
	fastio;
	int t, x, y;
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		cin >> x >> y;
		int d = y - x;
		int cnt = 0;
		for (int i = 1;; i++) {
			if (d >= i * 2) {
				d -= i * 2;
				cnt += 2;
			}
			else if (d == 0) {
				break;
			}
			else if (d <= i) {
				cnt++;
				break;
			}
			else {
				cnt += 2;
				break;
			}
		}
		cout << cnt << endl;
	}
	

	return 0;
}