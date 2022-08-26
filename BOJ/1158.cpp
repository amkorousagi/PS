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

int main(void) {
	fastio;
	int n, k;
	cin >> n >> k;
	vector<bool> person(n, true);
	int cnt = 0;
	int cursor = 0;
	int kk=0;
	cout << "<";
	for (int i=0;;i++) {
		if (cnt + 1 == n) {
			int a=0;
			for (int j = 0; j < n; j++) {
				if (person[j] == true) {
					a = j;
					break;
				}
			}
			cout << a+1 << ">";
			break;
		}
		if (person[(cursor + i) % (n)]) {
			kk++;
		}
		if (kk == k) {
			kk = 0;
			cnt++;
			person[(cursor + i) % (n)] = false;
			cout << (cursor + i) % (n)+1 << ", ";
		}
		
	}

	return 0;
}