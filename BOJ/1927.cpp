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

int main(void) {
	fastio;

	priority_queue<int,vector<int>,greater<int>> pq;

	int N, x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x > 0) {
			pq.push(x);
		}
		else {
			if (pq.empty()) {
				cout << 0<<endl;
			}
			else {
				cout << pq.top()<<endl;
				pq.pop();
			}
		}
	}

	return 0;
}