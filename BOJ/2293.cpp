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

vector<int> coin;
/*
//without memoization
int coin_recur(int i, int k) {
	if (i == 0) {
		if (k % coin[i] == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (k == 0) {
		return 1;
	}
	if (coin[i] > k) {
		return coin_recur(i - 1, k);
	}
	else if (coin[i] <= k) {
		return coin_recur(i - 1, k) + coin_recur(i, k - coin[i]);
	}
}

vector<vector<int>> dp(101, vector<int>(10001, -1));
int coin_top_down(int i, int k) {
	if (i == 0) {
		if (dp[i][k] == -1) {
			if (k % coin[i] == 0) {
				dp[i][k] = 1;
			}
			else {
				dp[i][k] = 0;
			}
		}
		return dp[i][k];
	}
	if (k == 0) {
		if (dp[i][k] == -1) {
			dp[i][k] = 1;
		}
		return dp[i][k];
	}
	if (coin[i] > k) {
		if (dp[i][k] == -1) {
			dp[i][k] = coin_top_down(i - 1, k);
		}
		return dp[i][k];
	}
	else if (coin[i] <= k) {
		if (dp[i][k] == -1) {
			dp[i][k] = coin_top_down(i - 1, k) + coin_top_down(i, k - coin[i]);
		}
		return dp[i][k];
	}
}

vector<vector<int>> dp2(101, vector<int>(10001, -1));
int coin_bottom_up(int n, int k) {
	for (int j = 0; j <= k; j++) {
		if (j % coin[0] == 0) {
			dp2[0][j] = 1;
		}
		else {
			dp2[0][j] = 0;
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (coin[i] > j) {
				dp2[i][j] = dp2[i - 1][j];
			}
			else {
				dp2[i][j] = dp2[i - 1][j] + dp2[i][j - coin[i]];
			}
		}
	}
}
*/
vector<int> dp3(10001, -1);
int coin_bottom_up_overwrite(int n, int k) {
	for (int j = 0; j <= k; j++) {
		if (j % coin[0] == 0) {
			dp3[j] = 1;
		}
		else {
			dp3[j] = 0;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp3[j] = dp3[j] + dp3[j - coin[i]];
		}
	}
	return dp3[k];
}

int main(void) {
	fastio;
	int n, k, c;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> c;
		coin.push_back(c);
	}
	//sort(coin.begin(), coin.end());
	/*
	cout << coin_recur(n - 1, k) << endl;
	cout << coin_top_down(n - 1, k) << endl;
	cout << coin_bottom_up(n - 1, k) << endl;
	*/
	cout << coin_bottom_up_overwrite(n, k);
	return 0;
}