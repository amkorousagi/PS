#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v(110,0);
int dp[110][110];
//dp[i][j] is minum value to add for i day and j coupon
//if having coupon, use immediately
//but we can consider optimized answer

int solve(int day, int coupon, int price){
    if(n<day)return price;
    if(dp[day][coupon])return dp[day][coupon] + price;
    if(v[day])return solve(day+1,coupon,price);

    int ans = (1<<31)-1;
    ans = min(ans,solve(day+1,coupon,price+10000));
    ans = min(ans,solve(day+3,coupon+1,price+25000));
    ans = min(ans,solve(day+5,coupon+2,price+37000));

    if(coupon>=3){
        ans = min(ans,solve(day+1,coupon-3,price));
    }

    dp[day][coupon] = ans -price;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int t;cin>>t;v[t]=1;
    }
    cout<<solve(1,0,0);
}