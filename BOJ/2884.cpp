#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;
int main(void) {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    //scanf("%d", &b);
    if (b >= 45)
        printf("%d %d", a, b - 45);
    else {
        if (a != 0) {
            printf("%d %d", a - 1, b + 60 - 45);
        }
        else {
            printf("23 %d", b + 15);
        }
    }
    
    return 0;
}