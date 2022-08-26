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
	vector<pair<int, string>> user;
	int N;
	cin >> N;
	int age;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> age >> s;
		user.push_back({ age, s });
	}

	stable_sort(
		user.begin(), 
		user.end(), 
		[](pair<int, string> a, pair<int, string> b) {
			return a.first < b.first;
		}
	);

	for (int i = 0; i < N; i++) {
		cout << user[i].first << " " << user[i].second << endl;
	}

	return 0;
}