#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

float prims(const vector<vector<float>> distances, int sat, int n){
    vector<bool> done(n, false);
    priority_queue<float> radios;
    priority_queue<pair<float, int>, vector<pair<float, int>>, greater<>> pq;
    pq.push({0, 0});  // Pair of {distance, node}
    while (!pq.empty()){
        float min_dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (done[node]) continue;
        done[node] = true;

        if (min_dist > 0) {
            radios.push(min_dist);
        }

        for (int i = 0; i < n; i++) {
            if (!done[i] && distances[node][i] > 0) {
                pq.push({distances[node][i], i});
            }
        }
    }
    while (--sat && !radios.empty()) {
        radios.pop();
    }
    return radios.top();
}

int main(){
    int tc, sat, n;
    cin >> tc;
    while(tc--){
        cin >> sat >> n;
        vector<vector<float>> distances(n, vector<float>(n));
        map<int, pair<int, int>> outposts;
        for(int i=0; i<n; i++){
            cin >> outposts[i].first >> outposts[i].second;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j){
                    distances[i][j]=sqrt(pow(outposts[i].first-outposts[j].first, 2)+pow(outposts[i].second-outposts[j].second, 2));
                }else{
                    distances[i][j]=0;
                }
            }
        }
        cout << fixed << setprecision(2) << prims(distances, sat, n) << endl;
    }
}
