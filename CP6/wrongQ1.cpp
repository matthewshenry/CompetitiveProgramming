#include <iostream>
#include <vector>
using namespace std;

int elevator(int f, int s, int g, int u, int d, int presses, vector<bool> visited){
    visited[s] = true;
    if(s == g){
        return presses;
    }else{
        presses++;
    }
    if(s - d < 0){
        if(s + u > f){
            cout << "use the stairs";
            return -1;
        }else{
            if(!visited[s+u]) {
                return elevator(f, s + u, g, u, d, presses, visited);
            }
        }
    }
    if(s + u > f){
        if(!visited[s-d]) {
            return elevator(f, s - d, g, u, d, presses, visited);
        }
    }
    if(!visited[s+u] && !visited[s-d]) {
        return min(elevator(f, s + u, g, u, d, presses, visited), elevator(f, s - d, g, u, d, presses, visited));
    }else if(!visited[s+u]){
        return elevator(f, s + u, g, u, d, presses, visited);
    }else if(!visited[s-d]){
        elevator(f, s - d, g, u, d, presses, visited);
    }else{
        cout << "use the stairs";
        return -1;
    }
}

int main() {
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    vector<bool> visited(f+1, false);
    visited[0] = true;
    if(elevator(f, s, g, u, d, 0, visited) != -1) {
        cout << elevator(f, s, g, u, d, 0, visited);
    }
}
