#include <bits/stdc++.h>

using namespace std;
vector<long long> v;
long long getMinOper(long long n){
    if(v[n] != -1){
        return v[n];
    }
    else{
        long long a ,b,c;
        a=b=c= LONG_MAX;
        if(n%3==0){
            a = getMinOper(n/3)+1;
        }
        if(n%2==0){
            b = getMinOper(n/2)+1;
        }
        c =getMinOper(n-1)+1;

        return v[n]=min(min(a,b),c);
    }
 
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    long long n, times =0;
    cin>>n;
    v.resize(n+1,-1);
    v[0] = v[1] = 0;
    times = getMinOper(n);
    cout<<times;

    return 0;
}