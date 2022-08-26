#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));
using namespace std;

int dirx[4] = { 1,0,-1,0 };
int diry[4] = { 0,-1,0,1 };

bool space[101][101][20];
bool overlap[101][101];
bool tmp[101][101];
// 90도 회전 : x,y => 100-y,x
// 끝점 서로 맞추기 : 다 이동

void draw(int n, int x, int y, int d, int g) {
	int end_y = y + diry[d];
	int end_x = x + dirx[d];
	
	space[y][x][n] = true;
	overlap[y][x] = true;

	space[end_y][end_x][n] = true;
	overlap[end_y][end_x] = true;

	int move_x, move_y;
	for (int i = 1; i <= g; i++) {
		move_y = end_y - end_x;
		move_x = end_x + end_y - 100;
		for (int a = 0; a <= 100; a++) {
			for (int b = 0; b <= 100; b++) {
				if (space[b][a][n]) {
					tmp[b][a] = true;
				}
				else {
					tmp[b][a] = false;
				}
			}
		}
		
		for (int a = 0; a <= 100; a++) {
			for (int b = 0; b <= 100; b++) {
				if (tmp[b][a]) {
					space[a + move_y][100 - b + move_x][n] = true;
					overlap[a + move_y][100 - b + move_x] = true;
					if (y == b && x == a) {
						// 시작점이 다음 끝점이 되기 때문에 update
						end_y = a + move_y;
						end_x = 100 - b + move_x;
					}
				}
			}
		}
	}
}
int res() {
	int cnt = 0;
	for (int j = 0; j < 100; j++) {
		for (int i = 0; i < 100; i++) {
			if (overlap[j][i] && overlap[j + 1][i] && overlap[j][i + 1] && overlap[j + 1][i + 1]) {
				cnt++;
			}
		}
	}
	return cnt;
}
int main() {
	fastio;
	int n;
	cin >> n;
	int x, y, d, g;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		draw(i, x, y, d, g);
	}
	
	cout << res();
	return 0;
}