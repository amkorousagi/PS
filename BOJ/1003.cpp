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

vector<int> dp(41, -1);
vector<int> cnt0(41, -1);
vector<int> cnt1(41, -1);

int fill_cnt0(int n) {
	if (cnt0[n] == -1) {
		int& ret = cnt0[n];
		ret = fill_cnt0(n - 1) + fill_cnt0(n - 2);
		return ret;
	}
	else {
		return cnt0[n];
	}
}

int fill_cnt1(int n) {
	if (cnt1[n] == -1) {
		int& ret = cnt1[n];
		ret = fill_cnt1(n - 1) + fill_cnt1(n - 2);
		return ret;
	}
	else {
		return cnt1[n];
	}
}

int main(void) {
	fastio;
	dp[0] = 0;
	dp[1] = 1;

	cnt0[0] = 1;
	cnt0[1] = 0;
	cnt1[1] = 1;
	cnt1[0] = 0;
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << fill_cnt0(N) << " " << fill_cnt1(N) << endl;
	}
	
	
	return 0;
}