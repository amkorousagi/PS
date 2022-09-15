/**
 * @template file author kadrick (kbk2581553@gmail.com)
 *
 * author:amkorousagi (hasmi5452@gmail.com)
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m;
int m_min = INT_MAX;
vector<vector<char>> board;

enum {LEFT, RIGHT, UP, DOWN};
bool move(int dir, vector<int>& pos, int cnt) {
	if (cnt >= m_min) {
		return false;
	}

	vector<int> res(4);
	bool qb = false;
	bool qr = false;
	if (dir == LEFT) {
		for (int i = 1; pos[1] - i>=0; i++) {
			if (board[pos[0]][pos[1] - i] == '#') {
				res[0] = pos[0];
				res[1] = pos[1] - i + 1;
				break;
			}
			else if (board[pos[0]][pos[1] - i] == 'O') {
				qr = true;
			}
		}
		for (int i = 1; pos[3] - i >= 0; i++) {
			if (board[pos[2]][pos[3] - i] == '#') {
				res[2] = pos[2];
				res[3] = pos[3] - i + 1;
				break;
			}
			else if (board[pos[2]][pos[3] - i] == 'O') {
				qb = true;
			}
		}

		if (res[0] == res[2] && res[1] == res[3]) {
			if (pos[1] < pos[3]) {
				res[3] += 1;
			}
			else {
				res[1] += 1;
			}
		}

	}
	else if (dir == RIGHT) {
		for (int i = 1; pos[1] + i < m; i++) {
			if (board[pos[0]][pos[1] + i] == '#') {
				res[0] = pos[0];
				res[1] = pos[1] + i - 1;
				break;
			}
			else if (board[pos[0]][pos[1] + i] == 'O') {
				qr = true;
			}
		}
		for (int i = 1; pos[3] + i < m; i++) {
			if (board[pos[2]][pos[3] + i] == '#') {
				res[2] = pos[2];
				res[3] = pos[3] + i - 1;
				break;
			}
			else if (board[pos[2]][pos[3] + i] == 'O') {
				qb = true;
			}
		}

		if (res[0] == res[2] && res[1] == res[3]) {
			if (pos[1] < pos[3]) {
				res[1] -= 1;
			}
			else {
				res[3] -= 1;
			}
		}
	}
	else if (dir == UP) {
		for (int i = 1; pos[0] - i >=0; i++) {
			if (board[pos[0]-i][pos[1]] == '#') {
				res[0] = pos[0] - i + 1;
				res[1] = pos[1];
				break;
			}
			else if (board[pos[0]-i][pos[1]] == 'O') {
				qr = true;
			}
		}
		for (int i = 1; pos[2] - i >=0; i++) {
			if (board[pos[2]-i][pos[3]] == '#') {
				res[2] = pos[2]-i+1;
				res[3] = pos[3];
				break;
			}
			else if (board[pos[2]-i][pos[3]] == 'O') {
				qb = true;
			}
		}

		if (res[0] == res[2] && res[1] == res[3]) {
			if (pos[0] < pos[2]) {
				res[2] += 1;
			}
			else {
				res[0] += 1;
			}
		}
	}
	else if (dir == DOWN) {
		for (int i = 1; pos[0] + i < n; i++) {
			if (board[pos[0] + i][pos[1]] == '#') {
				res[0] = pos[0] + i - 1;
				res[1] = pos[1];
				break;
			}
			else if (board[pos[0] + i][pos[1]] == 'O') {
				qr = true;
			}
		}
		for (int i = 1; pos[2] + i >= 0; i++) {
			if (board[pos[2] + i][pos[3]] == '#') {
				res[2] = pos[2] + i - 1;
				res[3] = pos[3];
				break;
			}
			else if (board[pos[2] + i][pos[3]] == 'O') {
				qb = true;
			}
		}

		if (res[0] == res[2] && res[1] == res[3]) {
			if (pos[0] < pos[2]) {
				res[0] -= 1;
			}
			else {
				res[2] -= 1;
			}
		}
	}




	pos.clear();
	pos.assign(res.begin(), res.end());
	if (qb) {
		return false;
	}
	else {
		if (qr) {
			m_min = min(m_min, cnt);
			return false;
		}
		else {
			return true;
		}
	}
}

void bo( int cnt, vector<int>& pos) {
	if (cnt + 1 > 10) {
		return;
	}

	vector<int> p;
	for (int i = 0; i < 4; i++) {
		p.clear();
		p.assign(pos.begin(),pos.end());
		if (move(i, p, cnt+1)) {
			bo(cnt + 1, p);
		}
	}
}


int main(void) {
	fastio;
	cin >> n >> m;
	board.assign(n, vector<char>(m));
	vector<int> pos(4);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j];
			if (s[j] == 'R') {
				board[i][j] = '.';
				pos[0] = i;
				pos[1] = j;
			}
			if (s[j] == 'B') {
				board[i][j] = '.';
				pos[2] = i;
				pos[3] = j;
			}
		}
	}

	bo(0, pos);
	if (m_min == INT_MAX) {
		cout << -1;
	}
	else {
		cout << m_min;
	}
	return 0;
}