#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));
#define mem first
#define cost second
using namespace std;

int main() {
	fastio;
	int n, m;
	
	cin >> n >> m;
	vector<pair<int, int>> app(n);
	for (int i = 0; i < n; i++) {
		cin >> app[i].mem;
	}
	for (int i = 0; i < n; i++) {
		cin >> app[i].cost;
	}
	sort(app.begin(), app.end(), [](auto a, auto b)->bool {if (a.first / (float)a.second == b.first / (float)b.second) { return  a.second < b.second; } else { return a.first / (float)a.second > b.first / (float)b.second; } });
	vector<int> dp(10000001);
	vector<int> dp_is(10000001,false);
	dp_is[0] = true;
	int max_mem = app[0].mem;
	int min_cost = INT_MAX;
	for (int i = 0; i < n; i++) {// app
		for (int j = max_mem; j >= 0; j--) { // dp
			if (dp_is[j]) {
				//cout << i << " " << j << " " << dp[j] << endl;
				if (dp[j + app[i].mem]==0 || dp[j + app[i].mem] > dp[j] + app[i].cost) {
					dp[j + app[i].mem] = dp[j] + app[i].cost;
					dp_is[j + app[i].mem] = true;
					if (j + app[i].mem > max_mem) {
						max_mem = j + app[i].mem;
						//cout << "max" << max_mem << endl;
					}
					if (j + app[i].mem >= m) {
						if (min_cost > dp[j + app[i].mem]) {
							min_cost = dp[j + app[i].mem];
						}
					}
				}
			}
		}
		//cout << max_mem << " " << min_cost<<endl;
	}
	cout << min_cost;

	return 0;
}