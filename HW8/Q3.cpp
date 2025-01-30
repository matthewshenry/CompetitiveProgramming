#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
const ll INF = 1e17;

struct Edge{
    int neighbor;
    int startTime;
    int interval;
    int travelTime;
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
            ll nextAvailableTime = e.startTime;
            if (currentDistance > e.startTime) {
                if (e.interval == 0) continue;
                nextAvailableTime = e.startTime + ((currentDistance - e.startTime + e.interval - 1) / e.interval) * e.interval;
            }
            ll newDistance = nextAvailableTime + e.travelTime;
            if (distances[e.neighbor] > newDistance) {
                distances[e.neighbor] = newDistance;
                pq.push({newDistance, e.neighbor});
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
            int u, v, t0, P, d;
            cin >> u >> v >> t0 >> P >> d;
            adjList[u].push_back({v, t0, P, d});
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