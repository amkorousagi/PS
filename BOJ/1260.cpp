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

int n, m;
vector<vector<bool>> adj;
vector<bool> visited;
void dfs(int start) {
	for (int i = 1; i <= n; i++) {
		if (adj[start][i] && !visited[i]) {
			cout << i << " ";
			visited[i] = true;
			dfs(i);
		}
	}
}

void dfs_stack(int start) {
	stack<int> s;

	for (int i = 1; i <= n; i++) {
		if (adj[start][i]) { 
			s.push(i);
			break;
		}
	}

	while (!s.empty()) {
		start = s.top();
		s.pop();
		if (visited[start]) continue;

		cout << start << " ";
		visited[start] = true;

		for (int i = 1; i <= n; i++) {
			if (adj[start][i] && !visited[i]) {
				s.push(i);
				break;
			}
		}
	}
}


void bfs(int start) {
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (adj[start][i]) q.push(i);
	}

	while (!q.empty()) {
		start = q.front();
		q.pop();
		if (visited[start]) continue;

		cout << start << " ";
		visited[start] = true;

		for (int i = 1; i <= n; i++) {
			if (adj[start][i] && !visited[i]) q.push(i);
		}
	}
}

int main(void) {
	fastio;
	int start;
	int a, b;
	cin >> n >> m >> start;

	adj.assign(n+1, vector<bool>(n+1, false));
	visited.assign(n+1, false);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a][b] = true;
		adj[b][a] = true;
	}
	
	cout << start << " ";
	visited[start] = true;
	dfs(start);
	cout << endl;
	/*
	visited.assign(n + 1, false);
	cout << start << " ";
	visited[start] = true;
	dfs_stack(start);
	cout << endl;
	*/
	visited.assign(n+1, false);
	cout << start << " ";
	visited[start] = true;
	bfs(start);
	

	return 0;
}