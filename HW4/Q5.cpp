class Solution {
public:
    int jump(vector<int>& nums) {
        int move_power = 0;
        int current = 0;
        int jumps = 0;
        int finish = nums.size() - 1;
        while(current != finish){
            move_power = nums[current];
            if(current + move_power >= finish){
                current = finish;
                jumps++;
            }else{
                int max_reach = 0;
                int next_position = current;
                for (int j = 1; j <= move_power; j++){
                    if (current + j < nums.size() && current + j + nums[current + j] > max_reach){
                        max_reach = current + j + nums[current + j];
                        next_position = current + j;
                    }
                }
                current = next_position;
                jumps++;
            }
        }
        return jumps;
    }
};