#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;
int main(void) {
    int a, A;
    scanf("%d", &A);
    scanf("%d", &a);

    int a100 = a / 100;
    int a10 = a / 10 % 10;
    int a1 = a % 10;
    // printf("%d %d %d\n", a100, a10, a1);
    
    printf("%d\n", A * a1);
    printf("%d\n", A * a10);
    printf("%d\n", A * a100);
    printf("%d\n", A * a);
    
    return 0;
}