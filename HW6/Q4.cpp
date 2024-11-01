#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);

        long long max = numeric_limits<int>::max();

        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                if(dp[i] + dp[i - coin] <= max){
                    dp[i] = dp[i] + dp[i - coin];
                } else {
                    dp[i] = max;
                }
            }
        }

        if(dp[amount] > max) {
            return 0;
        } else {
            return dp[amount];
        }
    }
};