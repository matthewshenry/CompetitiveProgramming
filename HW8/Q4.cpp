class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n), result;
        vector<int> disc(n, -1), low(n, -1);
        int time = 0;
        for(const auto& conn : connections){
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        function<void(int, int)> dfs = [&](int node, int parent){
            disc[node] = low[node] = time++;
            for(int neighbor : adj[node]){
                if(neighbor == parent) continue;
                if(disc[neighbor] == -1){
                    dfs(neighbor, node);
                    low[node] = min(low[node], low[neighbor]);
                    if(low[neighbor] > disc[node]){
                        result.push_back({node, neighbor});
                    }
                } else{
                    low[node] = min(low[node], disc[neighbor]);
                }
            }
        };

        for(int i = 0; i < n; ++i){
            if(disc[i] == -1){
                dfs(i, -1);
            }
        }
        return result;
    }
};
