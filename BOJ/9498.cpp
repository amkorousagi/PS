#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;
int main(void) {
    int a, b;
    scanf("%d", &a);
    //scanf("%d", &b);
    if (a > 89 ) {
        printf("A");
    }
    else if (a > 79) {
        printf("B");
    }
    else if (a > 69) {
        printf("C");
    }
    else if (a > 59) {
        printf("D");
    }
    else {
        printf("F");
    }
    
    return 0;
}