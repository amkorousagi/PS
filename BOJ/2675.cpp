/**
 * @file template.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-11-18 16:29
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'


char S[21];
int main(void) {
    fastio;
  
    int T;
    cin >> T;
    for (int t = 0;t < T;t++) {
        int R;
        cin >> R;
        cin >> S;

        for (int i = 0;i < 20;i++) {
            if (S[i] != 0) {
                for (int j = 0;j < R;j++)
                    cout << S[i];
            }
            S[i] = 0;
        }
        cout << endl;
    }

    return 0;
}