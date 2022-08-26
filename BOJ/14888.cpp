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

int arr[11];
int n;
vector<char> oper;
bool used[10];
int res_min = INT_MAX, res_max = INT_MIN;

void insert_oper(int carry, int idx) {
	if (idx == n) {
		if (res_min > carry) {
			res_min = carry;
		}
		if (res_max < carry) {
			res_max = carry;
		}
		return;
	}
	for (int i = 0; i < n-1; i++) {
		if (used[i] == false) {
			used[i] = true;
			if (oper[i] == '+') {
				insert_oper(carry + arr[idx], idx + 1);
			}else if (oper[i] == '-') {
				insert_oper(carry - arr[idx], idx + 1);
			}
			else if (oper[i] == '*') {
				insert_oper(carry * arr[idx], idx + 1);
			}
			else if (oper[i] == '/') {
				insert_oper(carry / arr[idx], idx + 1);
			}
			used[i] = false;
		}
	}
}

int main(void) {
	fastio;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int n_plus, n_minus, n_multiple, n_divide;
	cin >> n_plus >> n_minus >> n_multiple >> n_divide;
	
	for (int i = 0; i < n_plus; i++) {
		oper.push_back('+');
	}
	for (int i = 0; i < n_minus; i++) {
		oper.push_back('-');
	}
	for (int i = 0; i < n_multiple; i++) {
		oper.push_back('*');
	}
	for (int i = 0; i < n_divide; i++) {
		oper.push_back('/');
	}

	insert_oper(arr[0],1);
	cout << res_max << endl;
	cout << res_min << endl;
	
	return 0;
}