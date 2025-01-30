#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int tc, n, m, l, first, second, tipped;
    cin >> tc;
    while(tc--){
        int total = 0;
        cin >> n >> m >> l;
        vector<vector<int>> adj(n+1);
        queue<int> q;
        vector<bool> toppled(n+1, false);
        while(m--){
            cin >> first >> second;
            adj[first].push_back(second);
        }
        while(l--){
            cin >> tipped;
            if(!toppled[tipped]) {
                q.push(tipped);
                total++;
                toppled[tipped] = true;
            }
        }
        while(!q.empty()){
            int start = q.front();
            q.pop();
            for(int tile : adj[start]){
                if(!toppled[tile]){
                    toppled[tile] = true;
                    total++;
                    q.push(tile);
                }
            }
        }
        cout << total << endl;
    }
    return 0;
}
