#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main(){
    int n, k, a, b;
    cin >> n >> k;
    vector<vector<int>> adjList(n);
    vector<int> indegree(n, 0);
    queue<int> kahnQueue;
    vector<int> series;
    for(int i=0; i<k; i++){
        cin >> a >> b;
        adjList[a].push_back(b);
        indegree[b]++;
    }
    for(int i=0; i<n; i++){
        if(indegree[i] == 0){
            kahnQueue.emplace(i);
        }
    }
    while(!kahnQueue.empty()){
        if(kahnQueue.size() > 1){
            cout << "back to the lab" << endl;
            return 0;
        }
        int top = kahnQueue.front();
        kahnQueue.pop();
        series.push_back(top);
        for(int i : adjList[top]){
            indegree[i]--;
            if(indegree[i] == 0){
                kahnQueue.emplace(i);
            }
        }
    }
    if (series.size() != n) {
        cout << "back to the lab" << endl;
    } else {
        for (int metal: series) {
            cout << metal << " ";
        }
    }

}