#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<long long> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    
    for(int i=2; i<=n; i++){
        dp[i] = (dp[i-1]+dp[i-2])%10007;
    }
    
    cout<<dp[n];
    
    return 0;
}