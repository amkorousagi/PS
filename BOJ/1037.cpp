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
	int n, a;
	cin >> n;
	vector<int> s;
	for (int i = 0; i < n; i++) {
		cin >> a;
		s.push_back(a);
	}
	sort(s.begin(), s.end());
	if (n % 2 == 0) {
		cout << s[0] * s[n - 1];
	}
	else {
		cout << s[n / 2] * s[n / 2];
	}
	

	return 0;
}