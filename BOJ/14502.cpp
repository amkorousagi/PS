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
vector<pair<int, int>> udrl = { {1,0},{0,-1},{0,1},{-1,0} };

int n, m, cnt, safe_max=-1, wc;
vector<vector<int>> adj;
vector<vector<bool>> visited;

vector<pair<int, int>> virus;
void dfs(int r, int c) {
	for (pair<int,int> d : udrl) {
		if (r + d.first < 0 || r + d.first >= n || c + d.second < 0 || c + d.second >= m) continue;
		if (adj[r+d.first][c+d.second] == 1) continue;
		if (!visited[r+d.first][c+d.second]) {
			cnt++;
			visited[r + d.first][c + d.second] = true;
			dfs(r + d.first, c + d.second);
		}
	}
}
void spread_virus(void) {
	for (pair<int, int> v : virus) {
		if (!visited[v.first][v.second]) {
			visited[v.first][v.second] = true;
			cnt++;
			dfs(v.first, v.second);
		}
	}
}

void build_wall(int sr, int sc, int wall_cnt) {

	for(int i=sr;i<n;i++)
		for (int j = (i == sr) ? sc : 0; j < m; j++) {
			if (adj[i][j] == 0) {
				adj[i][j] = 1;
				if (wall_cnt + 1 == 3) {
					visited.assign(n, vector<bool>(m, false));
					spread_virus();
					if (n * m - cnt - wc - 3 > safe_max) {
						safe_max = n * m - cnt - wc - 3;
					}
					cnt = 0;
				}
				else {
					build_wall(i, j+1, wall_cnt + 1);
				}
				adj[i][j] = 0;
			}
		}
}


int main(void) {
	fastio;
	int start;
	int a, b;
	cin >> n >> m;

	adj.assign(n, vector<int>(m, 0));
	visited.assign(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> adj[i][j];
			if (adj[i][j] == 2) {
				virus.push_back({ i,j });
			}
			else if (adj[i][j] == 1) {
				wc++;
			}
		}
	}
	
	build_wall(0,0,0);
	cout << safe_max;

	return 0;
}