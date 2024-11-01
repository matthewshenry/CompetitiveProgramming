//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<vector<int>> adj;
//vector<bool> visited;
//vector<int> discovered, low, parent;
//int timeCounter;
//bool necessaryBridge;
//
//void findBridges(int current){
//    visited[current] = true;
//    discovered[current] = ++timeCounter;
//    low[current] = timeCounter;
//    for (int visiting : adj[current]){
//        if (!visited[visiting]){
//            parent[visiting] = current;
//            findBridges(visiting);
//            low[current] = min(low[current], low[visiting]);
//            // if low[visiting] > discovered[current], then there is no other way back to the origin from visiting.
//            if (low[visiting] > discovered[current]){
//                necessaryBridge = true;
//            }
//        } else if (visiting != parent[current]){
//            low[current] = min(low[current], discovered[visiting]);
//        }
//    }
//}
//
//int main(){
//    int p, c;
//    cin >> p;
//    cin >> c;
//    while(p != 0 || c!= 0){
//        adj.assign(p, vector<int>());
//        visited.assign(p, false);
//        discovered.assign(p, -1);
//        low.assign(p, -1);
//        parent.assign(p, -1);
//        timeCounter = 0;
//        necessaryBridge = false;
//        for (int i = 0; i < c; ++i){
//            int a, b;
//            cin >> a >> b;
//            adj[a].push_back(b);
//            adj[b].push_back(a);
//        }
//        findBridges(0);
//        for (int i = 0; i < p; ++i){
//            if (!visited[i]) {
//                necessaryBridge = true;
//            }
//        }
//        if(necessaryBridge){
//            cout << "Yes" << endl;
//        }else{
//            cout << "No" << endl;
//        }
//        cin >> p;
//        cin >> c;
//    }
//    return 0;
//}
