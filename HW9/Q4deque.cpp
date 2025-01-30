class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answer;
        deque<int> window;
        for(int i = 0; i < nums.size(); ++i){
            if(!window.empty() && window.front() < i - k + 1){
                window.pop_front();
            }
            while(!window.empty() && nums[window.back()] < nums[i]){
                window.pop_back();
            }
            window.push_back(i);
            if(i >= k - 1){
                answer.push_back(nums[window.front()]);
            }
        }
        return answer;
    }
};
