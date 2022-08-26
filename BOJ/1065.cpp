#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;
int main(void) {
    
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 1;i <= n;i++) {
        int digit1 = i % 10;
        int digit10 = (i % 100 - digit1)/10;
        int digit100 = (i % 1000 - digit10*10 - digit1)/100;
        if (i == 1000) {
            break;
        }

        if (i <= 99) {
            cnt++;
        }
        // 세자리
        else if (digit1 - digit10 == digit10 - digit100) {
            cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}