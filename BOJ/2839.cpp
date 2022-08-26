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
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
	fastio;
	int n;
	cin >> n;
	
	bool answer = false;
	for (int i = (n / 5) * 5; i >= 0; i -= 5) {
		if ((n - i) % 3 == 0) {
			cout << (n - i) / 3 + i / 5;
			answer = true;
			break;
		}
	}

	if (!answer) cout << -1;
	
	return 0;
}