class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();
        vector<int> masks(m, 0);

        for(int i = 0; i < m; i++){
            int mask = 0;
            for(int j = 0; j < n; j++){
                if(seats[i][j] == '.'){
                    mask |=(1 << j);
                }
            }
            masks[i] = mask;
        }
        vector<vector<int>> dp(m + 1, vector<int>(1 << n, -1));
        dp[0][0] = 0;

        for(int i = 0; i < m; i++){
            for(int mask = 0; mask <(1 << n); mask++){
                if((mask & masks[i]) != mask ||(mask &(mask >> 1))) continue;
                int students = __builtin_popcount(mask);
                for(int prevMask = 0; prevMask <(1 << n); prevMask++){
                    if(dp[i][prevMask] == -1) continue;
                    if((mask &(prevMask >> 1)) == 0 &&(mask &(prevMask << 1)) == 0){
                        dp[i + 1][mask] = max(dp[i + 1][mask], dp[i][prevMask] + students);
                    }
                }
            }
        }
        return *max_element(dp[m].begin(), dp[m].end());
    }
};

