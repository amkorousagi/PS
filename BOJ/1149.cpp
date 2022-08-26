#include <bits/stdc++.h>

using namespace std;
int main(){
    typedef tuple<int,int,int> h;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long sum =0;
    int count =0;
    int n;
    cin>>n;
    int price[1001][3];
    long long dp[1001][3];
    for(int i=1; i<=n; i++){
        cin>>price[i][0]>>price[i][1]>>price[i][2];
    }
    dp[1][0] = price[1][0];
    dp[1][1] = price[1][1];
    dp[1][2] = price[1][2];
    for(int i =2; i<=n; i++){
        dp[i][0] = min(dp[i-1][1],dp[i-1][2])+ price[i][0];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2])+ price[i][1];
        dp[i][2] = min(dp[i-1][1],dp[i-1][0])+ price[i][2];

    }
    cout<<min(dp[n][0],min(dp[n][1],dp[n][2]));
    
    return 0;
}