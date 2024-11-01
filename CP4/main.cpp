//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> nums(n);
//    vector<int> lis(n);
//    for(int i=0; i<n; i++){
//        cin >> nums[i];
//    }
//    lis[n-1] = 1;
//    for(int i=n-2; i>=0; i--){
//        if(nums[i] < nums[i+1]){
//            lis[i] = lis[i+1]+1;
//            cout << endl << i << endl;
//        }else{
//            lis[i] = lis[i+1];
//        }
//    }
//    for(int i : lis){
//        //cout << i << endl;
//    }
//    //cout << lis[0];
//}


//vector<pair<int, int>> nums;
//vector<pair<int, int>> lis;
//for(int i=0; i<n; i++){
//nums[i].first = i;
//cin >> nums[i].second;
//}
//sort(nums.begin(), nums.end(), [](const pair<int, int>& a, const pair<int, int>& b){
//return a.second > b.second;
//});
//lis.push_back(nums[0]);
//for(int i=1; i<n; i++){
//if(nums[i].first
//}