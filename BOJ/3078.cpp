#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));

using namespace std;
pair<int, int> dir[4] = { {0,1},{1,0},{0,-1},{-1,0} };

int name[21];
int main() {
	fastio;
	int N, K;
	cin >> N >> K;
	string* s = new string[N];
	for (int n = 0; n < N; n++) {
		cin >> s[n];
	}
	queue<int> q;
	long long cnt = 0;

	for (int i = 0; i < K; i++) {
		name[s[i].size()]++;
		q.push(s[i].size());
	}
	for (int i = 2; i <= 20; i++) {
		if (name[i]>1) {
			cnt += name[i] * (name[i] - 1) / 2;
		}
	}
	int t;
	for (int i = K; i < N; i++) {
		t = q.front();
		q.pop();
		name[t]--;
		q.push(s[i].size());
		name[s[i].size()]++;
		if (t == s[i].size()) {
			cnt++; // K만큼 떨어진 친구를 위해서
		}
		cnt += (name[s[i].size()] - 1) * 1;
	}
	cout << cnt;
	return 0;
}