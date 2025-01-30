#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

const int INF = numeric_limits<int>::max();

vector<pair<int, int>> adj[500005]; // adjacency list: node -> [(neighbor, weight)]
vector<int> dijkstra(int n, int start) {
    vector<int> dist(n, INF); // Distance array
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Min-heap

    dist[start] = 0; // Distance to self is 0
    pq.emplace(0, start); // (distance, node)

    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (curr_dist > dist[u]) continue; // Skip outdated distances

        for (auto [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    // Build the graph
    for (int i = 0; i < m; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        adj[a].emplace_back(b, l);
        adj[b].emplace_back(a, l); // Undirected graph
    }

    vector<int> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }

    // Process each query
    for (int query : queries) {
        vector<int> dist = dijkstra(n, query);

        // Find the farthest reachable city and count them
        int max_dist = -1, count = 0;
        for (int d : dist) {
            if (d < INF) {
                if (d > max_dist) {
                    max_dist = d;
                    count = 1;
                } else if (d == max_dist) {
                    ++count;
                }
            }
        }

        // Output the result for this query
        cout << max_dist << " " << count << endl;
    }

    return 0;
}
