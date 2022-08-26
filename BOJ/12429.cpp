#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

#define deadline first
#define survive second

#define Food pair<int, int>

int n, dp[101010];
vector<Food> foodBox;

bool comp(const Food& left, const Food& right)
{
    return left.deadline + left.survive > right.deadline + right.survive;
}

void solve()
{
    memset(dp, 0, sizeof(dp));

    cin >> n;
    foodBox.resize(n);
    for (int i = 0; i < n; i++)
        cin >> foodBox[i].deadline >> foodBox[i].survive;

    sort(foodBox.begin(), foodBox.end(), comp);

    for (int i = 0; i < n; i++)
    {
        int deadline = foodBox[i].deadline;
        int survive = foodBox[i].survive;
        for (int j = 0; j <= deadline; j++)
        {
            if (dp[j] < j + survive)
                dp[j] = j + survive;
            if (dp[j] < dp[j + survive])
                dp[j] = dp[j + survive];
        }
    }

    cout << dp[0];
}

int main(void)
{
    fastio;

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
        cout << endl;
    }

    return 0;
}