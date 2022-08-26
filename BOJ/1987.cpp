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

vector<pair<int, int>> di = { {1,0},{-1,0},{0,1},{0,-1} };

int n, m;

char miro[21][21];
vector<vector<bool>> visited;


typedef struct {
	int x;
	int y;
	int d;
	//set<char> s;
	//vector<vector<bool>> visited;
} node;

int mmax = -1;
vector<bool> s;
void dfs(int x,int y,int d) {
	if (d > mmax) mmax = d;
	if (d >= 26) return;
	for (pair<int, int> dd : di) {
		int nx, ny;
		nx = x + dd.first;
		ny = y + dd.second;
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (s[miro[nx][ny] - 'A']) continue;
		//if (temp.s.find(miro[nx][ny])!=temp.s.end()) continue;
		if (visited[nx][ny]) continue;
		s[miro[nx][ny] - 'A'] = true;
		visited[nx][ny] = true;
		//t.visited = temp.visited;
		//t.visited[nx][ny] = true;
		dfs(nx, ny, d + 1);
		s[miro[nx][ny] - 'A'] = false;
		visited[nx][ny] = false;
	}
}

int main(void) {
	fastio;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> miro[i];
	}
	s.assign(27, false);
	visited.assign(n, vector<bool>(m, false));
	visited[0][0] = true;
	s[miro[0][0] - 'A'] = true;
	dfs( 0,0,1 );
	cout << mmax;

	return 0;
}
// 256*10^6 == 400*2+ 400*400*2
// 400*4*400= 64*10^4 < 2*10^9
// set --> string