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

int arr[2000000];


int main(void) {
	fastio;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N + M);
	for (int i = 0; i < N + M; i++) {
		cout << arr[i] <<" ";
	}
	return 0;
}