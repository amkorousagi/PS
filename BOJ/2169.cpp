#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));
using namespace std;
vector<pair<int, int>> dir(4);
vector<vector<int>> my_map;
vector<vector<bool>> visited;
vector<vector<vector<int>>> dp;
int n, m;
// dp에 dir 까지 넣어서 공간 복잡도를 늘리고 시간 복잡도를 줄임
//  행 단위로 계산? 순서를 강제?

int dfs(int x, int y, int d) {
	
	if (x == n - 1 && y == m - 1) return my_map[x][y]; // 더이상 갈곳이 없으니까 어느 dir로 들어오든 앞으로 얻을 수 있는 가치는 map[x][y] 뿐
	if (dp[x][y][d] != -INF) return dp[x][y][d];

	int res = -INF;
	visited[x][y] = true;
	for (int i = 1; i < 4; i++) {
		int nx = x + dir[i].first;
		int ny = y + dir[i].second;
		if (ny >= 0 && nx < n && ny < m) {
			if (visited[nx][ny] == false) {
				res = max(res, dfs(nx, ny, i));
			}
		}
	}
	visited[x][y] = false;
	dp[x][y][d] = my_map[x][y] + res; 
	return dp[x][y][d];
	
}

int main() {
	fastio;
	cin >> n >> m;
	my_map.assign(n, vector<int>(m));
	visited.assign(n, vector<bool>(m, false));
	dp.assign(n, vector<vector<int>>(m, vector<int>(4,-INF)));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> my_map[i][j];
		}
	}
	dir[1] = pair<int, int>(0, 1); // r
	dir[2] = pair<int, int>(1, 0); // d
	dir[3] = pair<int, int>(0, -1); // l
	cout << dfs(0, 0, 0);

	return 0;
}