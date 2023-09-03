class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m = times.size();
        vector<vector<pair<int, int>>> adj(105);
        for (int i = 0; i < m; i++) {
            adj[times[i][0]].push_back({ times[i][1], times[i][2] });
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(105, 1e5);
        dist[k] = 0;
        pq.push({ dist[k], k });
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int prev_dist = it.first;
            int prev_pos = it.second;
            for (auto x : adj[prev_pos]) {
                int next_pos = x.first;
                int next_dist = x.second;
                if (dist[next_pos] > dist[prev_pos] + next_dist) {
                    dist[next_pos] = dist[prev_pos] + next_dist;
                    pq.push({ dist[next_pos], next_pos });
                }
            }
        }
        int mini = INT_MIN; // Change from INT_MAX to INT_MIN to find the maximum delay
        for (int i = 1; i <= n; i++) { // Change the loop condition
            if (i != k && dist[i] == 1e5)  return -1;
            mini = max(mini, dist[i]);
        }
        return mini;
    }
};
