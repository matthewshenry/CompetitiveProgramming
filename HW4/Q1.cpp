#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int bankq(int time, int n, vector<pair<int, int>> patrons){
    priority_queue<int> q;
    int moneyInTheBank = 0;
    int personIndex = n - 1;
    for(int t=time-1; t >= 0; --t) {
        while (personIndex >= 0 && patrons[personIndex].second >= t) {
            q.push(patrons[personIndex].first);
            --personIndex;
        }
        if (!q.empty()) {
            moneyInTheBank += q.top();
            q.pop();
        }
    }
    return moneyInTheBank;
}

int main(){
    int n, t;
    cin >> n;
    cin >> t;
    vector<pair<int, int>> patrons(n);
    for(int i=0; i<n; i++){
        cin >> patrons[i].first;
        cin >> patrons[i].second;
    }
    sort(patrons.begin(), patrons.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    cout << bankq(t, n, patrons);
}