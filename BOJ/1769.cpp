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

int cnt;
void ismultiple3(int n) {
	if (n < 10) {
		cout << cnt << endl;
		if (n % 3 == 0) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
		return;
	}
	cnt++;
	int sum = 0;
	for (int i = 1; i <= n; i *= 10) {
		sum += (n / i) % 10;
	}
	ismultiple3(sum);
}

int main(void) {
	fastio;

	string s;
	cin >> s;
	if (s.size() > 9) {
		int sum = 0;
		for (int i = 0; i < s.size(); i++)
			sum += (s[i] - '0');
		cnt++;
		ismultiple3(sum);
	}
	else {
		ismultiple3(atoi(s.c_str()));
	}
	return 0;
}