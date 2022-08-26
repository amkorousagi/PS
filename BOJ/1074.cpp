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

int cnt(int n, int r, int c, int startr, int startc) {
	if (n == 0) {
		return 0;
	}
	int p = pow(2, n - 1);

	if (r < p + startr && c < p + startc) {
		return cnt(n - 1, r, c, startr, startc);
	} else if (r < p + startr && c >= p + startc) {
		return cnt(n - 1, r, c, startr, startc+p) + p*p;
	}
	else if (r >= p + startr && c < p + startc) {
		return cnt(n - 1, r, c, startr + p, startc) + p*p*2;
	}
	else if (r >= p + startr && c >= p + startc) {
		return cnt(n - 1, r, c, startr + p, startc +p) + p*p*3;
	}
}


int main(void) {
	fastio;
	int n, c, r;
	cin >> n >> c >> r;
	cout << cnt(n, c, r, 0, 0);
	

	return 0;
}