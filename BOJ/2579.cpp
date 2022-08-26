//https://www.acmicpc.net/problem/2579
//n에 대한 모든 경우를 찾을때는 이미 제한조건을 만족하는 경우만을 찾는다
//1. n에 대한 모든 경우를 찾는다
//2. 경우들을 분류하여 그에 대응하는 점화식을 세운다.
//top-down 방식 --> 재귀호출을 이용한다
//
#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
vector<int> score;
int goal;

int solve(int i){
    if(i<0){
        return INT_MIN;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    else{
        return dp[i] = max(solve(i-2)+score[i], solve(i-3)+score[i-1]+score[i]);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    score.resize(n+1,-1);
    dp.resize(n+1,-1);
    for(int i=1;i<=n; i++){
        cin>>score[i];
    }
    dp[0] = 0;
    dp[1] = score[1];
    dp[2] = score[1]+score[2];
    
    for(int i=3; i<=n;i++){
        dp[i] = max(dp[i-2]+score[i], dp[i-3]+score[i-1]+score[i]);
    }
    cout<<solve(n);
    //cout<<dp[n];
    

    return 0;
}