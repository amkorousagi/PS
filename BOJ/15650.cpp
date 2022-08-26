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
int n, m;
vector<int> arr;

void nm(int start) {
	for (int i = start; i <= n; i++) {
		arr.push_back(i);
		if (arr.size() == m) {
			for (int a : arr)
				cout << a << " ";
			cout << endl;
		}
		else {
			nm(i + 1);
		}
		arr.pop_back();
	}
}


int main(void) {
	fastio;

	cin >> n >> m;
	nm(1);
	
	return 0;
}