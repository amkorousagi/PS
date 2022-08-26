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

int cnt[100];

int main(void) {
	fastio;
	string s;
	cin >> s;


	for (int i = 0; i < s.size(); i++) {
		cnt[toupper(s[i])- 'A']++;
	}

	int max = -1;
	int max_cnt;
	int max_value;
	for (int i = 0; i <= 'Z' - 'A'; i++) {
		if (cnt[i] > max) {
			max_cnt = 1;
			max = cnt[i];
			max_value = i + 'A';
		}
		else if (cnt[i] == max) {
			max_cnt++;
		}
	}

	if (max_cnt >= 2) {
		cout << "?";
	}
	else {
		cout << (char)max_value;
	}


	return 0;
}