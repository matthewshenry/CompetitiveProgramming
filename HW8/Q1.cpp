#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const ll INF = 1e17;

struct Edge{
    ll maxFlow;
    ll currentFlow;
    ll to;
};

bool bfs(ll n, const vector<vector<Edge>>& adj, ll start, ll end, vector<ll>& parent){
    vector<bool> visited(n, false);
    queue<ll> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for (const Edge& edge : adj[u]){
            int v = edge.to;
            if (!visited[v] && edge.currentFlow < edge.maxFlow){
                parent[v] = u;
                visited[v] = true;
                q.push(v);
                if (v == end) return true; //found end
            }
        }
    }
    return false;
}

ll ek(ll n, vector<vector<Edge>> adj, ll start, ll end){
    ll maxFlow = 0;
    vector<ll> parent(n);
    while(bfs(n, adj, start, end, parent)){
        ll pathFlow = INF;
        for(ll v = end; v != start; v = parent[v]){
            ll u = parent[v];
            for (Edge& edge : adj[u]) {
                if (edge.to == v) {
                    pathFlow = min(pathFlow, edge.maxFlow - edge.currentFlow);
                    break;
                }
            }
        }
        for(ll v = end; v != start; v = parent[v]){
            ll u = parent[v];
            for (Edge& edge : adj[u]){
                if (edge.to == v){
                    edge.currentFlow += pathFlow;
                    break;
                }
            }
            for (Edge& edge : adj[v]){
                if (edge.to == u){
                    edge.currentFlow -= pathFlow;
                    break;
                }
            }
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> rooms(n);
    vector<vector<Edge>> adj(n); //max flow, current flow
    for(ll i=0; i<n; i++){
        cin >> rooms[i];
    }
    for(ll i=0; i<n; i++){
        for(ll j=i; j<n; j++){
            ll num1 = rooms[j];
            ll num2 = rooms[i];
            while(num1 != 0){
                ll temp = num1;
                num1 = num2 % num1;
                num2 = temp;
            }
            if(num2 > 1){
                adj[i].push_back({num2, 0, j});
                adj[j].push_back({num2, 0, i});
            }
        }
    }
    auto st = min_element(rooms.begin(), rooms.end());
    ll start = distance(rooms.begin(), st);
    auto en = max_element(rooms.begin(), rooms.end());
    ll end = distance(rooms.begin(), en);
    cout << ek(n, adj, start, end);
    return 0;
}
