#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;
int main(void) {
    int a, b;
    scanf("%d", &a);
    //scanf("%d", &b);
    if (a%4==0 && (a%100!=0||a%400==0)) {
        printf("1");
    }
    else {
        printf("0");
    }
    
    return 0;
}