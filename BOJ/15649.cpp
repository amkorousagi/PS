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

int N, M;
vector<bool> used;
vector<int> selected;
void nm(int current_length) {
	for (int i = 1; i <= N; i++) {
		if (used[i] == false) {
			used[i] = true;
			selected.push_back(i);
			if (current_length + 1 == M) {
				for (int j = 0; j < M; j++) {
					cout << selected[j] << " ";
				}
				cout << endl;
			}
			else {
				nm(current_length + 1);
			}
			used[i] = false;
			selected.pop_back();
		}
	}
}

int main(void) {
	fastio;
	cin >> N >> M;
	used.assign(N + 1, false);
	nm(0);
	return 0;
}