#include <bits/stdc++.h>
using namespace std;

const long long LINF = 1e18;

int n;
int start_y, end_x;

int main(){
    scanf("%d %d %d", &n, &start_y, &end_x);
    vector<tuple<int,int,int>> lines;
    for(int i=0;i<n;i++){
        int x,yl,yh;
        scanf("%d %d %d",&x,&yl,&yh);
        lines.push_back(make_tuple(x,yl,yh));
    }
    sort(lines.begin(),lines.end());
    set<pair<long long, long long>> s;
    s.insert(make_pair(start_y,0));
    for(int i=0;i<n;i++){
        int x,yl,yh;
        tie(x,yl,yh) = lines[i];
        auto lb = s.lower_bound(make_pair(yl,-LINF));
        auto ub = s.upper_bound(make_pair(yh,+LINF));

        long long cand_top = LINF;
        long long cand_bottom = LINF;
        for(auto it = lb;it !=ub;++it){
            cand_top = min(cand_top,it->second + (yh-it->first));
            cand_bottom = min(cand_bottom, it->second + (it->first - yl));

        }
        s.erase(lb,ub);
        s.insert(make_pair(yh,cand_top));
        s.insert(make_pair(yl,cand_bottom));
    }
    long long min_h = LINF;
    int cnt_min = 0;
    for(auto it = s.begin(); it != s.end();++it){
        if(min_h == it->second){
            cnt_min++;
        }
        else if(min_h>it->second){
            min_h = it->second;
            cnt_min = 1;
        }
    }
    printf("%lld\n%d ",end_x + min_h, cnt_min);
    for(auto it = s.begin(); it != s.end(); ++it){
        if(it->second == min_h){
            printf("%lld ",it->first);
        }
    }
    return 0;
}