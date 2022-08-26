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

	string s;
	cin >> s;
	vector<string> suffix;

	int n = s.size();
	for (int i = 0; i <n; i++) {
		suffix.push_back(s.substr(i, n - i));
	}

	sort(suffix.begin(), suffix.end());

	for (string t : suffix) {
		cout << t << endl;
	}
	
	
	return 0;
}