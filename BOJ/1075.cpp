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
	int n, f;
	cin >> n >> f;
	n -= n % 100;
	vector<int> s;
	for (int i = 1; ; i++) {
		if (f * i >= n) { //  && n < f*(i+1)
			cout.width(2);
			cout.fill('0');
			cout << (f * i) % 100;
			break;
		}
	}
	

	return 0;
}