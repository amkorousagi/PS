/**
 * @file template.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-11-18 16:29
 *
 * @copyright Copyright (c) 2021
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
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int x1, y1, r1;
		int x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		int rsq = (r1 + r2) * (r1 + r2);
		int xysq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		if (r1 == r2 && x1 == x2 && y1 == y2) {
			cout << -1 << endl;
		}
		else if (rsq == xysq ) {
			cout << 1 << endl;
		}
		else if (rsq > xysq) {
			if (r1 < r2) {
				if (r2 * r2 > (r1 + sqrt(xysq)) * (r1 + sqrt(xysq))) {
					cout << 0 << endl;
				}
				else if (r2 * r2 == (r1 + sqrt(xysq)) * (r1 + sqrt(xysq))) {
					cout << 1 << endl;
				}
				else {
					cout << 2 << endl;
				}
			}
			else {
				if (r1 * r1 > (r2 + sqrt(xysq)) * (r2 + sqrt(xysq))) {
					cout << 0 << endl;
				}
				else if (r1 * r1 == (r2 + sqrt(xysq)) * (r2 + sqrt(xysq))) {
					cout << 1 << endl;
				}
				else {
					cout << 2 << endl;
				}
			}
		}
		else {
			cout << 0 << endl;
		}
	}


	return 0;
}