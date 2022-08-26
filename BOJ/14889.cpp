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
int arr[20][20];
int n;
bool selected[20];
int team_min = INT_MAX;

void calc_team() {
	int sum_t = 0, sum_f = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (selected[i] == selected[j]) {
				if (selected[i] == true) {
					sum_t += arr[i][j];
				}
				else {
					sum_f += arr[i][j];
				}
			}
		}
	}
	if (team_min > abs(sum_t - sum_f)) {
		team_min = abs(sum_t - sum_f);
	}

}
//start 를 넣어서 20!/10!을 20C10으로 //특정 형태의 정답만을 고려
void make_team(int cnt, int start) {
	for (int i = start; i < n; i++) {
		if (selected[i] == false) {
			selected[i] = true;
			if (cnt + 1 != n / 2) {
				make_team(cnt + 1,i+1);
			}
			else {
				calc_team();
			}
			selected[i] = false;
		}
	}
}



int main(void) {
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	make_team(0,0);
	cout << team_min;
	
	return 0;
}