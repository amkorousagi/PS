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

int chess[15][15];
int n;
int cnt;
bool isAvaiable(int row, int col) {
	for (int i = 0; i < n; i++) {
		if (chess[i][col] == 1) {
			return false;
		}
	}
	int i, j;
	i = row;
	j = col;
	for (;;) {
		i++; j++;
		if (i >= n || j >= n) {
			break;
		}
		if (chess[i][j] == 1) {
			return false;
		}
	}
	i = row;
	j = col;
	for (;;) {
		i++; j--;
		if (i >= n || j < 0) {
			break;
		}
		if (chess[i][j] == 1) {
			return false;
		}
	}
	i = row;
	j = col;
	for (;;) {
		i--; j++;
		if (i < 0 || j >= n) {
			break;
		}
		if (chess[i][j] == 1) {
			return false;
		}
	}
	i = row;
	j = col;
	for (;;) {
		i--; j--;
		if (i < 0 || j < 0) {
			break;
		}
		if (chess[i][j] == 1) {
			return false;
		}
	}
	return true;
}
void queen(int row) {
	if (row == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isAvaiable(row, i)) {
			chess[row][i] = 1;
			queen(row + 1);
			chess[row][i] = 0;
		}
	}
}

int main(void) {
	fastio;

	cin >> n;
	queen(0);
	cout << cnt;
	
	return 0;
}