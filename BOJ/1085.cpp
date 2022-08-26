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
	int x,y,w,h;
	cin >> x >> y >> w >> h;
	
	int d = min(x, min(y, min(w - x, h - y)));
	cout << d;
	

	return 0;
}