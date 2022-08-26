#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct node {
	int x;
	int y;
	vector<struct node*> connected;
} node;

vector<vector<node*>> map;
vector<vector<bool>> visited;
vector<vector<int>> distances;

void connect(node* a, node* b) {
	a->connected.push_back(b);
	b->connected.push_back(a);
}

void init_visited(int n, int m) {
	visited.clear();
	visited.assign(n, vector<bool>(m, false));
	distances.clear();
	distances.assign(n, vector<int>(m, 0));
}

int dfs_longest_distance(node* current, int d) { // dfs 쓰면 돌아서 가는 거리를 알 수 있다
	visited[current->x][current->y] = true;

	bool is_end = true;
	for (auto it = current->connected.begin(); it != current->connected.end(); it++) {
		if (!visited[(*it)->x][(*it)->y]) {
			is_end = false;
		}
	}
	if (is_end) {
		return d;
	}
	
	int longest = -1;
	for (auto it = current->connected.begin(); it != current->connected.end(); it++) {
		if(!visited[(*it)->x][(*it)->y])
			longest = max(longest, dfs_longest_distance(*it, d + 1)); // stack을 쓴다 (프로그램 자체의 함수 스텍)
	}
	return longest;
}

int bfs_longest_distance(node* current, int d) { // bfs 쓰면 구슬이 굴러가듯 최단 거리를 알 수 있다	
	
	visited[current->x][current->y] = true;
	queue<node*> q;
	q.push(current);

	int longest = -1;

	while (!q.empty()) {
		node* r = q.front();
		q.pop();

		d = distances[r->x][r->y];
		longest = max(longest, d);

		for (auto it = r->connected.begin(); it != r->connected.end(); it++) {
			distances[(*it)->x][(*it)->y] = d + 1;
			if (!visited[(*it)->x][(*it)->y]) {
				visited[(*it)->x][(*it)->y] = true;
				q.push(*it);
			}
		}
	}

	return longest;
}


int main(void) {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	map.assign(n, vector<node*>(m));


	// n이 50 밖에 안되네?  brute force ㄱㄴ
	// 시간 복잡도 대충..
	
	//초기화
	char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == 'L') {
				node* temp = new node(); // new를 쓰지 않으면 항상 같은 메모리 주소만을 줌
				temp->x = i;
				temp->y = j;
				map[i][j] = temp;
			}
			else {
				map[i][j] = NULL;
			}
		}
	}

	// 그래프 잇기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]) {
				//상
				if (i - 1 >= 0) {
					if (map[i - 1][j]) {
						connect(map[i][j], map[i - 1][j]);
					}
				}
				//하
				if (i + 1 < n) {
					if (map[i + 1][j]) {
						connect(map[i][j], map[i + 1][j]);
					}
				}
				//좌
				if (j - 1 >= 0) {
					if (map[i][j - 1]) {
						connect(map[i][j], map[i][j - 1]);
					}
				}
				//우
				if (j + 1 < n) {
					if (map[i][j + 1]) {
						connect(map[i][j], map[i][j + 1]);
					}
				}
			}
		}
	}

	int max_depth = -1;
	//모든 노드에 대해서 최대 깊이 조사
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]) {
				init_visited(n, m);
				max_depth = max(max_depth, bfs_longest_distance(map[i][j], 0));
			}
		}
	}

	cout << max_depth;

	return 0;
}