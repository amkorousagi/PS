#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));

using namespace std;

pair<int, int> dir[4] = { { 0,1 }, { 1,0 },{ 0,-1 },{ -1,0 } };

deque<pair<int, int>> snake;
vector<pair<int, int>> apple;
char _rotate[10001];

int main() {
	fastio;
	int n, k, l;

	cin >> n >> k;
	int row, col;
	for (int kk = 0; kk < k; kk++) {
		cin >> row >> col;
		apple.push_back({ row,col });
	}
	cin >> l;
	int x;
	char c;
	for (int ll = 0; ll < l; ll++) {
		cin >> x >> c;
		_rotate[x] = c;
	}


		
	pair<int, int> current = { 1,1 };
	snake.push_front(current);
	int current_dir = 0;
	for (int t = 1;; t++) {
		// 벽
		pair<int, int> _next = { current.first + dir[current_dir].first,current.second + dir[current_dir].second };
		if (_next.first <=0 || _next.first>n || _next.second<=0 || _next.second>n) {
			cout << t;
			return 0;
		}
		// 몸
		for (auto it = snake.begin(); it != snake.end(); it++) {
			if (it->first == _next.first && it->second == _next.second) {
				cout << t;
				return 0;
			}
		}

		snake.push_front(_next);

		// 사과
		bool eaten = false;
		for (auto it = apple.begin(); it != apple.end(); it++) {
			if (it->first == _next.first && it->second == _next.second) {
				eaten = true;
				it->first = -1;
				it->second = -1;
				break;
			}
		}
		if (!eaten) {
			snake.pop_back();
		}

		current = _next;
		if (_rotate[t]) {
			if (_rotate[t] == 'L') {
				current_dir = (4 + current_dir - 1) % 4;
			}
			else {
				current_dir = (4 + current_dir + 1) % 4;
			}
		}
	}


	return 0;
}