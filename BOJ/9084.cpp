#include <iostream>
#include <cstring>

using namespace std;
int T, N, M;
int dp[10001];
int coin[21];
int main(void) {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int n = 0; n < N; n++) {
			cin >> coin[n];
		}
		cin >> M;
		
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < N; i++) {
			for (int m = 0; m <= M; m++) {//정순으로해야 중복으로세림
				if (dp[m] != 0 && m + coin[i] <= M) {
					dp[m + coin[i]] += dp[m];
				}
			}
		}
		cout << dp[M] << endl;
	}


	return 0;
}