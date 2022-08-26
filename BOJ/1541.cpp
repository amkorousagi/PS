#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
    char s[100];
    cin >> s;
    char s_cp[100];
    strcpy(s_cp, s);
    bool pre_minus = false;
    char* pn;
    long long sum = 0;
    int idx = 0;

    pn = strtok(s, "+-");
    sum = atoi(pn);
    idx = strlen(pn);
    if (s_cp[idx] == '-') pre_minus = true;

    while ((pn = strtok(NULL, "+-")) != NULL) {

        if (pre_minus) {
            sum -= atoi(pn);
        }
        else {
            sum += atoi(pn);
        }


        idx += strlen(pn) + 1;
        if (s_cp[idx] == '-') pre_minus = true;
    }


    cout << sum;
    return 0;
}