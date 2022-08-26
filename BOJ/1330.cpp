#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;
int main(void) {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    if (a > b) {
        printf(">");
    }
    if (a < b) {
        printf("<");
    }
    if (a == b) {
        printf("==");
    }
    
    return 0;
}