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
int cnt = 0;
int sum = 0;
int n, s;
vector<int> se;
void r(int cursor) {
	sum += se[cursor];
	if (sum == s) {
		cnt++;
	}
	for (int i = cursor + 1; i < n; i++) {
		//sum += se[i];
		r(i);
		//sum -= se[i];
	}
	sum -= se[cursor];
}
int main(void) {
	fastio;
	
	cin >> n >> s;
	se.assign(n,0);
	for (int i = 0; i < n; i++) {
		cin >> se[i];
	}
	
	int sum;
	for (int i = 0; i < n; i++) {
		sum = 0;
		r(i);
	}
	cout << cnt;

	return 0;
}