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

int n, m, cnt;
vector<vector<bool>> adj;
vector<bool> visited;
void dfs(int start) {
	for (int i = 1; i <= n; i++) {
		if (adj[start][i] && !visited[i]) {
			cnt++;
			visited[i] = true;
			dfs(i);
		}
	}
}



int main(void) {
	fastio;
	int start;
	int a, b;
	cin >> n >> m;

	adj.assign(n+1, vector<bool>(n+1, false));
	visited.assign(n+1, false);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a][b] = true;
		adj[b][a] = true;
	}
	
	
	visited[1] = true;
	dfs(1);
	cout << cnt;

	return 0;
}