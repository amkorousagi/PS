#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    
    int n_city;
    long long sum =0;
    vector<pair<long long,int>> city;
    vector<long long> path;
    long long ch =0;

    scanf("%d",&n_city);
    vector<int> check(n_city-1,0);
    for(int i=0; i<n_city-1;i++){
        long long len;
        scanf("%lld",&len);
        path.push_back(len);
    }
    for(int i=0; i<n_city;i++){
        long long price;
        scanf("%lld",&price);
        city.push_back(make_pair(price,i));
    }
    sort(city.begin(),city.end());
    for(auto it=city.begin(); it!=city.end(); ++it){
        if(ch == n_city-1){
            break;
        }
        int current = it->second;//can be 0
        for(auto it2 = path.begin() + current; it2 != path.end();){
            if(check[current] == 0){
                check[current++] = 1;
                ch++;
                sum += (*it2)*(it->first);
                it2++;

            }
            else{
                break;
            }

            
        }
    }
    printf("%lld",sum);

    

    return 0;
}