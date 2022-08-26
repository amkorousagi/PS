#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>

using namespace std;

int main() {
    stack<int> s;
    int n;
    char str[10];
    int data;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        scanf("%s", str);



        if (strcmp(str, "push") == 0) {
            scanf("%d", &data);
            s.push(data);
        }
        else if (strcmp(str, "pop") == 0) {
            if (s.size() == 0) {
                printf("-1\n");
            }
            else {
                printf("%d\n", s.top());
                s.pop();
            }
        }
        else if (strcmp(str, "size") == 0) {
            printf("%d\n", s.size());
        }
        else if (strcmp(str, "empty") == 0) {
            if (s.size() == 0) {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
        }
        else if (strcmp(str, "top") == 0) {
            if (s.size() == 0) {
                printf("-1\n");
            }
            else {
                printf("%d\n", s.top());
            }
        }


    }


    return 0;
}