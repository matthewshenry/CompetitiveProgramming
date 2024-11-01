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
    int n;
    cin >> n;
    unordered_map<int, int> dogs; // SIZE --> NUMBER OF PACKS
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        vector<pair<int, int>> arr = {make_pair(num,1)};
        for (auto it: dogs) {
            arr.push_back({it.first+num, it.second+1});
        }
        for (int i = 0; i < arr.size(); i++) {
            if (dogs.count(arr[i].first)) {
                dogs[arr[i].first] = min(dogs[arr[i].first], arr[i].second);
            } else {
                dogs[arr[i].first] = arr[i].second;
            }
        }
    }
    cin >> n;
    unordered_map<int, int> buns;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        vector<pair<int, int>> arr = {make_pair(num,1)};
        for (auto it: buns) {
            arr.push_back({it.first+num, it.second+1});
        }
        for (int i = 0; i < arr.size(); i++) {
            if (buns.count(arr[i].first)) {
                buns[arr[i].first] = min(buns[arr[i].first], arr[i].second);
            } else {
                buns[arr[i].first] = arr[i].second;
            }
        }
    }   
    int res = INT_MAX; 
    for (auto it: buns) {
        if (dogs.count(it.first)) {
            // we also have the same amount of hot dogs
            res = min(res, dogs[it.first]+it.second);
        }
    }
    cout << (res == INT_MAX ? "impossible" : to_string(res)) << '\n';
    return 0;
}