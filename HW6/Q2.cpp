#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define ll long long
#define ar array

void getAns(vector<int>& dp, vector<int>& arr, int query) {
    // try to get the query
    stack<int> nums;
    while (query > 0) {
        nums.push(dp[query]+1);
        query -= arr[dp[query]];
    }
    while (!nums.empty()) {
        cout << nums.top() << ' ';
        nums.pop();
    }
}

int main()
{
    // disables synchronization between C and C++ std streams
    ios::sync_with_stdio(0);
    cin.tie(0);

    // code here
    int n;
    cin >> n;
    vector<int> items(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> items[i];
    }

    vector<int> dp(30001, -1); // -1 is IMPOSSIBLE -2 is AMGBG, otherwise that's the index
    dp[0] = 0;
    for (int i = 1; i < 30001; i++) {
        for (int j = 0; j < n; j++) {
            if (i-items[j] >= 0) {
                // we're able to access some previous index
                if (dp[i-items[j]] == -1 || dp[i-items[j]] > j) {
                    // either the element doesn't exist
                    // OR the element uses a greater index
                    continue;
                } else {
                    // our element uses a <= index and the prevous one definitely exists
                    if (dp[i-items[j]] == -2 || dp[i] > -1){
                        dp[i] = -2;
                        break;
                    } else {
                        // we are good
                        dp[i] = j;
                    }
                }
                // this means we are allowed to look back
            }
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;
        if (dp[query] == -1) {
            cout << "Impossible" << '\n';
        } else if (dp[query] == -2) {
            cout << "Ambiguous" << '\n';
        } else {
            getAns(dp, items, query);
        }
    }


    return 0;
}