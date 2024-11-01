#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define ll long long
#define ar array


int main()
{
    // disables synchronization between C and C++ std streams
    ios::sync_with_stdio(0);
    cin.tie(0);

    // code here
    int n, k;
    while (cin >> n) {
        cin >> k;
        if (n == 0 && k == 0) {
            break;
        }
        vector<vector<int>> values(2, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            cin >> values[0][i];
            cin >> values[1][i];
        }
        vector<vector<int>> prevDP(2, vector<int>(n+1, 0));
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        for (int i = 1; i <= k; i++) {
            // every single i is a DP iteration
            dp[0][i] = values[0][i-1]+prevDP[0][i-1];
            dp[1][i] = values[1][i-1]+prevDP[1][i-1];
            for (int j = i+1; j <= n; j++) {
                int bestBefore = min(dp[0][j-1], dp[1][j-1]);
                dp[0][j] = min(bestBefore, values[0][j-1]+prevDP[0][j-1]);
                dp[1][j] = min(bestBefore, values[1][j-1]+prevDP[1][j-1]);
            }
            prevDP = dp;
        }
        cout << accumulate(values[0].begin(), values[0].end(), 0)+accumulate(values[1].begin(), values[1].end(), 0)-min(dp[0][n], dp[1][n]) << '\n';
    }

    return 0;
}