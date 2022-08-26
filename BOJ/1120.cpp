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

	string a, b;
	cin >> a >> b;

	int min = 51;
	for (int i = 0; i < b.size(); i++) {
		if (i + a.size() > b.size()) {
			break;
		}
		int cnt = 0;
		for (int j = 0; j < a.size(); j++) {
			if (b[i + j] != a[j]) cnt++;
		}
		if (min > cnt) {
			min = cnt;
		}
	}
	cout << min;

	
	return 0;
}