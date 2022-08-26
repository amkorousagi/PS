#include <bits/stdc++.h>
using namespace std;

int tree[501][501] ;
long long sum[501][501];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            int dat;
            cin>>dat;
            tree[i][j] = dat;
        }
    }

    sum[1][1] = tree[1][1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
           if(j==1){
               sum[i][1] = sum[i-1][1] + tree[i][1];
           }
           else if(j==i){
               sum[i][i] = sum[i-1][i-1] + tree[i][i];
           }
           else{
               sum[i][j] = max(sum[i-1][j-1],sum[i-1][j])+ tree[i][j];           }
        }
    }
    
    long long mi = sum[n][1];
    for(int i=1; i<=n;i++){
        if(mi<sum[n][i]){
            mi = sum[n][i];
        }
    }
    cout<<mi;
    return 0;
}