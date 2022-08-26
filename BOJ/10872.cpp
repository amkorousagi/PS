#include <cstdio>

int fac(int n){
    if(n== 0) return 1;
    return n * fac(n-1);
}

int main(){
    int a;
    scanf("%d",&a);
    printf("%d",fac(a));
    return 0;
}