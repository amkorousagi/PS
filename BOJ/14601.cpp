#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));
using namespace std;

vector<vector<int>> board;
int k, x, y;
int cnt;
void draw(int sx, int ex, int sy, int ey) {
	int unit = (ex - sx + 1) / 2; // 2**k-1
	if (unit == 1) {
		//더이상 나눌수 없음
		cnt++;
		for (int i = sx; i <= ex; i++) {
			for (int j = sy; j <= ey; j++) {
				if (board[j][i] == 0) {
					board[j][i] = cnt;
				}
			}
		}
		return;
	}

	// 가운데 다 칠함
	cnt++;
	board[sy + unit - 1][sx + unit - 1] = cnt;
	board[sy + unit][sx + unit - 1] = cnt;
	board[sy + unit - 1][sx + unit] = cnt;
	board[sy + unit][sx + unit] = cnt;

	// 비워야 하는 곳 비움
	if (y < sy || ey < y || x < sx || ex < x) {
		if (board[sy][sx] != 0)
			board[sy + unit - 1][sx + unit - 1] = 0;
		if (board[ey][sx] != 0)
			board[sy + unit][sx + unit - 1] = 0;
		if (board[sy][ex] != 0)
			board[sy + unit - 1][sx + unit] = 0;
		if (board[ey][ex] != 0)
			board[sy + unit][sx + unit] = 0;
	}
	else {
		if (sy<=y && y<= sy + unit - 1 && sx<=x && x<= sx + unit - 1)
			board[sy + unit - 1][sx + unit - 1] = 0;
		if (ey >= y && y >= sy + unit && sx <= x && x <= sx + unit - 1)
			board[sy + unit][sx + unit - 1] = 0;
		if (sy <= y && y <= sy + unit - 1 && ex >= x && x >= sx + unit)
			board[sy + unit - 1][sx + unit] = 0;
		if (ey >= y && y >= sy + unit && ex >= x && x >= sx + unit)
			board[sy + unit][sx + unit] = 0;
	}
	//비운곳이 x,y 일 경우 대비
	board[y][x] = -1;

	draw(sx, sx + unit - 1, sy, sy + unit - 1);
	draw(sx, sx + unit - 1, sy + unit, ey);
	draw(sx + unit, ex, sy, sy + unit - 1);
	draw(sx + unit, ex, sy + unit, ey);
}
int main() {
	fastio;
	cin >> k;
	cin >> x >> y;
	int MAX = pow(2, k);
	board.assign(pow(2, k) + 1, vector<int>(MAX + 1, 0));
	board[y][x] = -1;
	draw(1, MAX, 1, MAX);

	for(int j = MAX; j >= 1; j--){
		for (int i = 1; i < MAX; i++) {
			cout << board[j][i]<<" ";
		}
		cout << board[j][MAX] << endl;
	}

	return 0;
}