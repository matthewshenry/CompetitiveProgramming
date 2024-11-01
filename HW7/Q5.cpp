class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1' && !visited[i][j]){
                    count++;
                    vector<pair<int, int>> stack;
                    stack.push_back({i, j});
                    while(!stack.empty()){
                        auto [x, y] = stack.back();
                        stack.pop_back();
                        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0' || visited[x][y]){
                            continue;
                        }
                        visited[x][y] = true;
                        stack.push_back({x + 1, y});
                        stack.push_back({x - 1, y});
                        stack.push_back({x, y + 1});
                        stack.push_back({x, y - 1});
                    }
                }
            }
        }
        return count;
    }
};