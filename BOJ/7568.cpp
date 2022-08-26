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
#define weight first
#define height second

int main(void) {
	fastio;
	vector<pair<int, int>> man;
	int N;
	int x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		man.push_back({ x,y });
		//man.push_back(make_pair(x, y));
	}
	
	int cnt = 0;
	// auto == vector<pair<int,int>>::iterator
	for (auto it = man.begin(); it != man.end(); it++) {
		cnt = 0;
		for (auto jt = man.begin(); jt != man.end(); jt++) {
			if (jt->weight > it->weight && jt->height > it->height) {
				cnt++;
			}
		}
		cout << cnt+1 << " ";
	}


	return 0;
}