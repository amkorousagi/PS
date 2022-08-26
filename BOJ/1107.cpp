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


int main(void) {
	fastio;
	vector<bool> b(10, true);
	int n, m, bb;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> bb;
		b[bb] = false;
	}
	int nn = n;
	int n_digit = 1;
	for (;;) {
		if (nn / 10 == 0) {
			break;
		}
		else {
			n_digit++;
			nn = nn / 10;
		}
	}
	int res1= 5000000, res2=5000000;

	//최소값을 구하는 방법.
	// 계속 빼거나 더하면서 만족하는 수 찾기
	// 만족하는 수 만들기

	int nnn, i;
	for (nn = n;nn<=1000000; nn++) {
		nnn = nn;
		int n_digit2 = 1;
		for (;;) {
			if (nnn / 10 == 0) {
				break;
			}
			else {
				n_digit2++;
				nnn = nnn / 10;
			}
		}
		nnn = nn;
		for (i = 0; i < n_digit2; i++) {
			if (b[nnn % 10] == false) {
				break;
			}
			nnn = nnn / 10;
		}
		if (i == n_digit2) {
			if (res1 > (nn - n)+n_digit2) {
				res1 = (nn - n) + n_digit2;
			}
			break;
		}
	}

	for (nn = n;nn>=0; nn--) {
		nnn = nn;
		int n_digit2 = 1;
		for (;;) {
			if (nnn / 10 == 0) {
				break;
			}
			else {
				n_digit2++;
				nnn = nnn / 10;
			}
		}
		nnn = nn;
		for (i = 0; i < n_digit2; i++) {
			if (b[nnn % 10] == false) {
				break;
			}
			nnn = nnn / 10;
		}
		if (i == n_digit2) {
			if (res2 > (n - nn) + n_digit2) {
				res2 = (n - nn) + n_digit2;
			}
			break;
		}
	}
	if (min(res1,res2) > abs(n - 100)) {
		cout << abs(n - 100);
	}
	else {
		cout << min(res1, res2);
	}
	return 0;
}