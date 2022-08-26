#include <bits/stdc++.h>
using namespace std;

int zan[10001];
long long dp[10001][3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n; i++){
        cin>>zan[i];
    }

    dp[1][0] = 0;
    dp[1][1] = zan[1];
    dp[1][2] = 0;
    for(int i=2; i<=n; i++){
        dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        dp[i][1] = dp[i-1][0] + zan[i];
        dp[i][2] = dp[i-1][1] + zan[i];
    }

    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]));

    return 0;
}