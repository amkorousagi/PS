#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));
using namespace std;
struct ticket {
	int to, cost, date;
};
struct comp {
	bool operator()(ticket a, ticket b) { return a.date > b.date; }
};
int T, N, M, K;
int dp[101][10001]; // 자동으로 0 초기화
int main() {
	fastio;
	int u, v, c, d;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M >> K;
		vector<vector<ticket>> tickets(N+1);
		for (int i = 1; i <= N; i++)
			for (int j = 0; j <= M; j++)
				dp[i][j] = INF;
		for (int k = 0; k < K; k++) {
			cin >> u >> v >> c >> d;
			ticket temp;
			temp.to = v;
			temp.cost = c;
			temp.date = d;
			tickets[u].push_back(temp);
		}
		priority_queue <ticket, vector<ticket>, comp> pq;

		dp[1][0] = 0; // 1에서 1까지 0일 만에 0원을 쓰고 갈수 있다. 기저사례

		ticket start;
		start.to = 1;
		start.cost = 0;
		start.date = 0;
		pq.push(start);
		// 다익스트라 알고리즘 - priority queue를 사용한 버전
		while (!pq.empty()) {
			ticket current = pq.top(); pq.pop();
			for (const ticket& item : tickets[current.to]) { // 현재 도착지를 출발지로 하는 모든 티켓(edge)들에 대해 반복
				ticket next;
				next.to = item.to; // 그 티켓의 도착지가 다음 도착지
				next.date = dp[current.to][current.cost] + item.date; // 1에서 cost만큼의 돈을 써서 현재 도착지를 거쳐서 다음 도착지로 가는데 걸리는 시간
				next.cost = current.cost + item.cost; // 다음 도착지로 가는데 든 돈은 지금까지 쓴 돈과 다음 티켓값

				if (next.cost > 10000) continue; // 문제의 조건에서 어긋나는 경우
				if (dp[next.to][next.cost] > next.date) { // dp에는 최적값(이 문제의 경우는 최소값)이 있어야 되는데, 지금 item의 티켓을 써서 cost만큼의 돈을 써서 다음 도착지로 가는데 걸리는 시간이, 이전에 계산해두었던 값보다 더 최적일 경우 업데이트
					dp[next.to][next.cost] = next.date;
					pq.push(next);
				}
			}
		}
		int ans = INF;
		for (int i = 0; i <= M; i++) {
			ans = min(ans, dp[N][i]);
		}
		if (ans != INF)
			cout << ans << endl;
		else
			cout << "Poor KCM" << endl;
	}

	return 0;
}