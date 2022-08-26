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

int hanoi(int n) {
	if (n == 1) {
		return 1;
	}
	return 2 * hanoi(n - 1) + 1;
}
void hanoi_print(int n, int start, int middle, int end) {
	if (n == 1) {
		cout << start << " " << end << endl;
	}
	else {
		hanoi_print(n - 1, start, end, middle);
		cout << start << " " << end << endl;
		hanoi_print(n - 1, middle, start, end);
	}
}
int main(void) {
	fastio;
	int N;
	cin >> N;
	cout << hanoi(N)<<endl;
	hanoi_print(N, 1,2, 3);
	return 0;
}