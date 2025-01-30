#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    if(s == g){
        cout << 0;
        return 0;
    }
    vector<bool> visited(f + 1, false);
    queue<pair<int, int>> q;
    q.push({s, 0});
    visited[s] = true;
    while(!q.empty()){
        int currentFloor = q.front().first;
        int presses = q.front().second;
        q.pop();
        int nextFloor = currentFloor + u;
        if(nextFloor <= f && !visited[nextFloor]){
            if(nextFloor == g){
                cout << presses + 1;
                return 0;
            }
            visited[nextFloor] = true;
            q.push({nextFloor, presses + 1});
        }
        nextFloor = currentFloor - d;
        if(nextFloor >= 1 && !visited[nextFloor]){
            if(nextFloor == g){
                cout << presses + 1;
                return 0;
            }
            visited[nextFloor] = true;
            q.push({nextFloor, presses + 1});
        }
    }
    cout << "use the stairs";
    return 0;
}
