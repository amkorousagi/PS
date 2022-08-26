#include <cstdio>

int num[2001];

int main(){
    int n;
    int idx;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&idx);
        num[idx+1000] = 1;
    }
    int i = 0;
    int cnt = 0;
    while(1){
        if(cnt == n){
            break;
        }
        if(num[i]){
            printf("%d\n",i-1000);
            cnt++;
        }
        i++;
    }
    return 0;
    
    
}