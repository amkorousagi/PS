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
int n;
int k;
int c[2000000];

//애초에 재귀로 풀려는 시도가 잘못됨
void merge_sort(int start, int end, int d) {
}

int main(void) {
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	cin >> k;
	
	for (int i = 1; i <= n; i *= 2) {

		int prior = 0;
		for (int j = i; j <= n; j += i) {
			sort(c + prior, c + j);
			prior = j;
		}
		if (n / k == i) {
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << c[i] << " ";
	}


	return 0;
}