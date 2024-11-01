#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
const ll INF = 1e17;

struct Edge{
    int neighbor;
    int weight;
};

vector<ll> djikstras(int s, int n, vector<vector<Edge>> adjList){
    vector<ll> distances(n, INF);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    distances[s] = 0;
    while(!pq.empty()){
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        if (visited[currentNode]) continue;
        visited[currentNode] = true;
        for(Edge e : adjList[currentNode]){
            if(distances[e.neighbor]>e.weight+currentDistance && !visited[e.neighbor]) {
                pq.push({e.weight + currentDistance, e.neighbor});
                distances[e.neighbor] = e.weight+currentDistance;
            }
        }
    }
    return distances;



}


int main() {
    while(true){
        int n, m, q, s;
        cin >> n >> m >> q >> s;
        if(n==0&&m==0&&q==0&&s==0) break;
        vector<vector<Edge>> adjList(n);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adjList[u].push_back({v, w});
            //adjList[v].push_back({u, w}); //include if bidirectional
        }
        vector<ll> dj = djikstras(s, n, adjList);
        while (q--) {
            int num;
            cin >> num;
            if (dj[num] == INF) {
                cout << "Impossible" << endl;
            } else {
                cout << dj[num] << endl;
            }
        }
    }
    return 0;
}
