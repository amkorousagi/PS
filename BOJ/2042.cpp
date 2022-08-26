#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));


using namespace std;
pair<int, int> dir[4] = { {0,1},{1,0},{0,-1},{-1,0} };

long long arr[1000001];
vector<long long> seg(pow(2, 21) - 1 + 1); // nodes count = 2^(H+1) - 1, H = lg N, 근데 1이 root 니까

long long init_tree(int node, int start, int end) {
	if (start == end) {
		return seg[node] = arr[start];
	}
	else {
		return seg[node] = init_tree(node * 2, start, (start + end) / 2) + init_tree(node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

long long sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return seg[node];
	}
	return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	seg[node] = seg[node] + diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int main() {
	fastio;
	int N, M, K;
	cin >> N >> M >> K;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}
	init_tree(1, 1, N);
	long long a, b, c;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, 1, N, b, c - arr[b]);
			arr[b] = c;
		}
		else {
			cout << sum(1, 1, N, b, c) << endl;
		}
	}
	return 0;
}