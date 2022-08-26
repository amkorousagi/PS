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
char paper[65][65];
int cntb, cntw;

bool is_paper(int startr, int endr, int startc, int endc) {
	char c = paper[startr][startc];

	for (int i = startr; i <= endr; i++) {
		for (int j = startc; j <= endc; j++) {
			if (c != paper[i][j]) {
				return false;
			}
		}
	}

	return true;
}

void check(int startr, int endr, int startc, int endc) {
	int midrs = (startr + endr) / 2;
	int midre = (startr + endr) / 2+1;
	int midcs = (startc + endc) / 2;
	int midce = (startc + endc) / 2+1;

	

	if (startr==endr ||  is_paper(startr, endr, startc, endc)) {
		if (paper[startr][startc] == '1') {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	else {
		cout << "(";
		check(startr, midrs, startc, midcs);
		check(startr, midrs, midce, endc);
		check(midre, endr, startc, midcs);
		check(midre, endr, midce, endc);
		cout << ")";
	}


}

int main(void) {
	fastio;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> paper[i];
	}
	check(0, n - 1, 0, n - 1);
	return 0;
}