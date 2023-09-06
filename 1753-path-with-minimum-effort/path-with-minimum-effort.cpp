class Solution {
public:
    bool isValid(int n, int m, int i, int j, vector<vector<int>>& heights) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int row = front.first;
            int col = front.second;
            
            for (int i = 0; i < 4; i++) {
                int x = row + dx[i];
                int y = col + dy[i];
                
                if (isValid(n, m, x, y, heights)) {
                    int neweffort = max(abs(heights[row][col] - heights[x][y]), dist[row][col]);
                    if (neweffort < dist[x][y]) {
                        dist[x][y] = neweffort;
                        q.push({x, y});
                    }
                }
            }
        }
        
        return dist[n - 1][m - 1];
    }
};
