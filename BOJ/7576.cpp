#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));
using namespace std;

int box[1001][1001];
int M, N; // M이 가로칸 수
pair<int, int> dir[4] = { {0,1},{1,0},{0,-1},{-1,0} };
typedef struct {
	int row;
	int col;
	int day;
} tomato;

int max_ripe(int row, int col) {
	// 박스 범위 벗어남
	if (row < 0 || N <= row || col < 0 || M <= col) {
		return -1;
	}
	// 전이가 불가능함
	if (box[row][col] == 0 || box[row][col] == -1) {
		return -1;
	}
	
	
}


int main() {
	fastio;
	cin >> M >> N;
	queue<tomato> q;
	int none_cnt = 0;
	int ripe_cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				q.push({ i, j, 0 });
				ripe_cnt++;
			}
			else if (box[i][j] == -1) {
				none_cnt++;
			}
		}
	}
	
	if (none_cnt + q.size() == M * N) {
		cout << 0;
		return 0;
	}

	int max_ripe = 0;
	int prior_cnt = q.size();
	tomato cur;
	pair<int, int> next_loc;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		max_ripe = max(max_ripe, cur.day);

		for (int i = 0; i < 4; i++) {
			if (cur.row + dir[i].first < 0 || cur.row + dir[i].first >= N || cur.col + dir[i].second < 0 || cur.col + dir[i].second >= M) continue;
			next_loc = { cur.row + dir[i].first,cur.col + dir[i].second };
			if (box[next_loc.first][next_loc.second] == 0) {
				box[next_loc.first][next_loc.second] = 1;
				q.push({ next_loc.first,next_loc.second,cur.day + 1 });
				ripe_cnt++;
			}
		}
	}

	if (ripe_cnt + none_cnt == M * N) {
		cout << max_ripe;
	} else {
		cout << -1;
	}

	return 0;
}