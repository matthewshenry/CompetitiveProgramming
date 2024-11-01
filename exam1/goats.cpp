#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

long long goats(long long n, long long k){
    if(n==k){
        return 0;
    }
    vector<long long> goats(n);
    vector<pair<long long, long long>> diffs(n);
    for(long long i=0; i<n; i++){
        cin >> goats[i];
    }
    sort(goats.begin(), goats.end());
    // for(long long goat : goats){
    //     cout << goat << endl;
    // }
    for(long long i=1; i<n; i++){
        diffs[i].first = goats[i]-goats[i-1];
        diffs[i].second = i;
    }
    sort(diffs.begin(), diffs.end());
    long long max_diff=0;
    long long gaps=k-1;
    if(gaps == 0){
        max_diff = goats[goats.size()-1] - goats[0];
        return max_diff;
    }
    stack<long long> first_in_group;
    for(long long i=0; i<gaps; i++){
        first_in_group.emplace(diffs[diffs.size() - 1 - i].second);
    }
    vector<long long> group;
    long long counter = 0;
    for(long long i=0; i<k; i++){
        // cout << counter << endl;
        //cout << first_in_group.top() << endl;
        for(long long j=counter; j<first_in_group.top(); j++){
            group.push_back(goats[j]);
        }
        sort(group.begin(), group.end());
        // for(long long goat : group){
        //  cout << goat << endl;
        // }
        // cout << endl;
        long long diff = group[group.size()-1] - group[0];
        if(diff > max_diff){
            max_diff = diff;
        }
        counter = first_in_group.top();
        first_in_group.pop();
        if(first_in_group.empty()){
            first_in_group.push(n);
        }
        group.clear();
    }
    return max_diff;
}
int main() {
    /* Enter your code here. Read input from STDIN. Prlong long output to STDOUT */
    long long n, k;
    cin >> n >> k;
    cout << goats(n, k);

}

