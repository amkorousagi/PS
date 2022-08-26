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
#define SMAX 5000
int dp[5001];

int sugarmin(int n) {
	if (dp[n] != 0) {
		return dp[n];
	}
	int sm = SMAX;
	int t;
	for (int i = 1; i < n; i++) {
		t = sugarmin(i) + sugarmin(n - i);
		if (t < sm) {
			sm = t;
		}
	}
	dp[n] = sm;
	return dp[n];
	
}

int main(void) {
	fastio;
	
	dp[1] = SMAX;
	dp[2] = SMAX;
	dp[4] = SMAX;

	dp[3] = 1;
	dp[5] = 1;
	int n;
	cin >> n;
	
	int ret = sugarmin(n);
	if (ret >= SMAX) {
		cout << -1;
	}
	else {
		cout << ret;
	}

	
	return 0;
}