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
#include <unordered_set>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
	fastio;
	int n, m;
	cin >> n >> m;

	//트리를 사용한 집합
	//set<string> s;
	//multiset<string> input;
	
	//해시를 사용한 집합
	unordered_set<string> s;
	unordered_multiset<string> input;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		s.insert(temp);
	}
	for (int i = 0; i < m; i++) {
		string temp;
		cin >> temp;
		input.insert(temp);
	}

	int cnt = 0;
	for (auto it = input.begin(); it != input.end(); it++) {
		if (s.count(*it)) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}