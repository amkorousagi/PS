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


int coin[10];
int main(void) {
	fastio;
	
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}
	
	int cnt = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (K >= coin[i]) {
			cnt += K / coin[i];
			K = K % coin[i];
		}
	}
	cout << cnt;

	return 0;
}