class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        int n = nums.size();
        if(n == 0) return {};
        int logn = log2(n) + 1;
        vector<vector<int>> st(n, vector<int>(logn, 0));
        for(int i = 0; i < n; ++i){
            st[i][0] = nums[i];
        }
        for(int j = 1; j < logn; ++j){
            for(int i = 0; i + (1 << j) - 1 < n; ++i){
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
        vector<int> result;
        for(int i = 0; i <= n - k; ++i){
            int left = i;
            int right = i + k - 1;
            int length = right - left + 1;
            int logLength = log2(length);
            int maxVal = max(st[left][logLength], st[right - (1 << logLength) + 1][logLength]);
            result.push_back(maxVal);
        }
        return result;
    }
};