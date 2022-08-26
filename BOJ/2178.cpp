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

vector<pair<int, int>> d = { {1,0},{-1,0},{0,1},{0,-1} };

int n, m;

char miro[101][101];
vector<vector<bool>> visited;

typedef struct {
	int x;
	int y;
	int d;
} node;

int main(void) {
	fastio;

	cin >> n >> m;
	visited.assign(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		cin >> miro[i];
	}

	queue<node> q;
	q.push({ 0,0,1 });
	visited[0][0] = true;

	node temp;
	int nx, ny;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp.x == n - 1 && temp.y == m - 1) {
			cout << temp.d;
			break;
		};

		for (pair<int, int> dd : d) {
			nx = temp.x + dd.first;
			ny = temp.y + dd.second;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (miro[nx][ny] == '0') continue;
			if (visited[nx][ny]) continue;
			q.push({ nx,ny,temp.d + 1 });
			visited[nx][ny] = true;
		}
	}


	return 0;
}