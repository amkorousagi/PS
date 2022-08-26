/*
2020 3 4 park se chan
https://www.acmicpc.net/problem/2668
this problem does require dfs
*/
/*

Q.how do i access this problem?
A. limit the wat to count

Q.critical point for solving the problem
A.
divide case without overlap,
up line and left side is already counted !!


*/

#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

vector<pair<int, int>> deck;
vector<int> overlap(101, 0);
void compress(int n);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		deck.push_back(make_pair(i + 1, c));
		overlap[c]++;
	}
	compress(n);



	return 0;
}
void compress(int n) {
	set<int> comp;
	vector<int> check(n, -1);
	for (int i = 0; i < n;i++) {
		comp.insert(deck[i].second);
	}
	while (comp.size() != deck.size()) {
		for (int i = 1; i <= n;i++) {
			//check for node that first line == i 		
			if (comp.end() == comp.find(i)) {
				// erase node that first line == i in deck and comp
				for (int j = 0; j < deck.size();j++) {
					if (deck[j].first == i) {
						overlap[deck[j].second]--;
						if (overlap[deck[j].second] == 0)
							comp.erase(comp.find(deck[j].second));//---consider overlap element!
						deck.erase(deck.begin() + j);
						
					}
				}

			}

		}
	}
	cout << deck.size() << endl;
	for (int i = 0; i < deck.size();i++) {
		cout << deck[i].first << endl;
	}
}