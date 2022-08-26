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
#define m_start first
#define m_end second

int main(void) {
	fastio;
	
	int n;
	cin >> n;
	vector<pair<int, int>> meet(n);
	int s, e;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		meet[i] = { s, e };
	}
	sort(meet.begin(), meet.end(), [](auto a, auto b) {
		if (a.m_end < b.m_end) {
			return true;
		}
		else if (a.m_end == b.m_end) {
			return a.m_start < b.m_start;
		}
		else {
			return false;
		}
		});
	int cnt = 0;
	int start = 0;
	for (int i = 0; i < n; i++) {
		if (start <= meet[i].m_start) {
			cnt++;
			start = meet[i].m_end;
		}
	}
	cout << cnt;

	return 0;
}