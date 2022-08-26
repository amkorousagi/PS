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
int paper[128][128];
int cntb, cntw;

bool is_paper(int startr, int endr, int startc, int endc) {
	int c = paper[startr][startc];

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

	//cout << startr << " " << endr << " " << startc << " " << endc << endl;

	if (startr==endr ||  is_paper(startr, endr, startc, endc)) {
		if (paper[startr][startc] == 1) {
			cntb++;
		}
		else {
			cntw++;
		}
	}
	else {
		check(startr, midrs, startc, midcs);
		check(startr, midrs, midce, endc);
		check(midre, endr, startc, midcs);
		check(midre, endr, midce, endc);
	}


}




int main(void) {
	fastio;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}
	check(0, n - 1, 0, n - 1);
	cout << cntw << endl << cntb;
	return 0;
}