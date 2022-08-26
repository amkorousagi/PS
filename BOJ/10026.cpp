#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));
using namespace std;

pair<int, int> dir[4] = { {0,1},{1,0},{0,-1},{-1,0} };

int N;
int area_cnt;
int weakness_area_cnt;
char board[101][101];
int area[101][101];
int weakness_area[101][101];

void fill_area(int row, int col, char c, int an) {
	if (row < 0 || N <= row || col < 0 || N <= col) return;

	if (board[row][col] == c && area[row][col] == -1) {
		area[row][col] = an;
		for (int i = 0; i < 4; i++) {
			fill_area(row + dir[i].first, col + dir[i].second, c, an);
		}
	}
	else {
		return;
	}

}

void fill_weakness_area(int row, int col, char c, int an) {
	if (row < 0 || N <= row || col < 0 || N <= col) return;

	if ((board[row][col] == c || ((c == 'R' || c == 'G') && (board[row][col] == 'R' || board[row][col] == 'G'))) && weakness_area[row][col] == -1) {
		weakness_area[row][col] = an;
		for (int i = 0; i < 4; i++) {
			fill_weakness_area(row + dir[i].first, col + dir[i].second, c, an);
		}
	}
	else {
		return;
	}
}

int main() {
	fastio;
	init(area, -1);
	init(weakness_area, -1);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (area[i][j] == -1) {
				fill_area(i, j, board[i][j], ++area_cnt);
			}
			if (weakness_area[i][j] == -1) {
				fill_weakness_area(i, j, board[i][j], ++weakness_area_cnt);
			}
		}
	}
	cout << area_cnt << " " << weakness_area_cnt;
	return 0;
}