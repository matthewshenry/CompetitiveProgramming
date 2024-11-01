#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nested_dolls(const vector<pair<int, int>>& dolls){
    vector<vector<int>> groups;
    for (const auto& doll : dolls){
        int height = doll.second;
        bool placed = false;
        for (auto& group : groups) {
            if (height > group.back()) {
                group.push_back(height);
                placed = true;
                break;
            }
        }
        if (!placed) {
            groups.push_back({height});
        }
    }
    return groups.size();
}

int main(){
    int tc, n;
    cin >> tc;
    while(tc--){
        cin >> n;
        vector<pair<int, int>> dolls(n);
        for(int i=0; i<n; i++){
            cin >> dolls[i].first;
            cin >> dolls[i].second;
        }
        sort(dolls.begin(), dolls.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        cout << nested_dolls(dolls) << endl;
    }
}
