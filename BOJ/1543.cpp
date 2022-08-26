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
	string doc;
	getline(cin, doc);
	string word;
	getline(cin, word);

	int cursor = 0;
	int cnt=0;
	while (doc.find(word, cursor)!=-1) {
		cnt++;
		cursor = doc.find(word, cursor) + word.size();
	}

	cout << cnt;


	return 0;
}