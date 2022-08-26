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

char s[1000002];
int main(void) {
	fastio;

	fgets(s, sizeof(char) * 1000002, stdin);
	int cnt = 0;
	int ss = 0;
	for (int i = 0; ; i++) {
		if ((s[i] == '\n')) {
			ss = i;
			break;
		}
		if ((s[i + 1] == '\n')) {
			ss = i + 1;
			break;
		}
		if (s[i] == ' ' && !(i == 0)) cnt++;
		
	}
	if (ss == 1 && s[0] == ' ') {
		cout << 0;
	}
	else if (ss == 0) {
		cout << 0;
	}
	else {
		cout << cnt + 1;
	}
	return 0;
}