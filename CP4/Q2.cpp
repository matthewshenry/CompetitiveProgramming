#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        vector<int> dp;
        vector<int> prev(n, -1);
        vector<int> position(n);
        for(int i = 0; i < n; i++){
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            int idx = distance(dp.begin(), it);
            if(it == dp.end()){
                dp.push_back(nums[i]);
            } else{
                *it = nums[i];
            }
            position[idx] = i;
            if(idx > 0){
                prev[i] = position[idx-1];
            }
        }
        cout << dp.size() << endl;

        vector<int> result;
        int curr = position[dp.size()-1];
        while(curr != -1){
            result.push_back(curr);
            curr = prev[curr];
        }
        reverse(result.begin(), result.end());
        for(int idx : result){
            cout << idx << " ";
        }
        cout << endl;
    }
}
