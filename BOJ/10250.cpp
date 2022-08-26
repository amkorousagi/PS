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
		int h, w, n;
		cin >> h >> w >> n;
		int floor = (n - 1) % h + 1;
		int room = (n - 1) / h + 1;
		if (room < 10) {
			cout << floor << "0" << room << endl;
		}
		else {
			cout << floor << room << endl;
		}
		
	}


	return 0;
}