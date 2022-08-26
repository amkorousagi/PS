#include <bits/stdc++.h>
using namespace std;
vector<int> v;

int add123(int n){
    if(v[n]!= -1){
        return v[n];
    }
    else{
        int a,b,c;
        a = add123(n-1);
        b = add123(n-2);
        c = add123(n-3);
        return v[n] = a+b+c;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin>>n;
    v.resize(11+1,-1);
    v[0] = 0; v[1] =1; v[2]=2; v[3]=4; 
    for(int i=0; i<n; i++){
        int data;
        cin>>data;
        cout<<add123(data)<<endl;
    }

    return 0;
}