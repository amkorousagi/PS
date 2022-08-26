#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;
int main(void) {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    //scanf("%d", &b);
    if (a>0) {
        if (b > 0)
            printf("1");
        else
            printf("4");
    }
    else {
        if (b > 0)
            printf("2");
        else
            printf("3");
    }
    
    return 0;
}