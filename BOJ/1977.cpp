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

char ch[5][15];

int main(void) {
	fastio;
	int M, N;
	cin >> M >> N;

	int sum = 0;
	int first = 0;
	for (int i = 1;; i++) {
		int i_sq = i * i;
		if (M <= i_sq && i_sq <= N) {
			if (first == 0) {
				first = i_sq;
			}
			sum += i_sq;
		}
		else if (N < i_sq) {
			break;
		}
	}

	if (sum == 0) {
		cout << -1;
	}
	else {
		cout << sum << endl << first;
	}

	return 0;
}