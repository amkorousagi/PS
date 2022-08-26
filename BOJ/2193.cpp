#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long dp[91][2];
    //dp[i][0] means the number binary not having sub string 11, its length is i, start 0
    //dp[i][1] means the number binary not having sub string 11, its length is i, start 1
    int n;
    cin>>n;
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    
    for(int i=2; i<= n-1;i++){
        dp[i][0] = dp[i-1][0]+dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    cout<<dp[n-1][0];

    return 0;
}
