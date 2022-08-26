#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;
int main(void) {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    printf("%.9lf", (double)a/(double)b);

    return 0;
}