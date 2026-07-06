// Last updated: 06/07/2026, 18:48:54
class Solution {
public:
    bool isBipartite(const vector<vector<int>>& adj, int n){
        vector<int> color(n, -1);
        for (int i = 0; i < n; ++i){
            if (color[i] == -1){
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty()){
                    int val = q.front(); q.pop();

                    for (int v : adj[val]){
                        if (color[v] == -1){
                            color[v] = 1 - color[val];
                            q.push(v);
                        }
                        else if (color[v] == color[val]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    
    bool cansplit(const vector<vector<int>>& points, const vector<int>& distVals, int idx){
        int n = points.size();
        int dist = distVals[idx];

        vector<vector<int>> adj(n);

        for (int i = 0; i < n - 1; ++i){
            for (int j = i + 1; j < n; ++j){
                int d = abs(points[i][0] - points[j][0]) + 
                    abs(points[i][1] - points[j][1]);

                if (d < dist){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        return isBipartite(adj, n);
    }
    
    int maxPartitionFactor(vector<vector<int>>& points) {
        const int n = points.size();
        if (n == 2) return 0;

        vector<int> distVals;
        distVals.reserve(n * (n - 1) / 2);

        for (int i = 0; i < n - 1; ++i){
            for (int j = i + 1; j < n; ++j){
                distVals.push_back(
                    abs(points[i][0] - points[j][0]) + 
                    abs(points[i][1] - points[j][1])
                );
            }
        }

        sort(distVals.begin(), distVals.end());
        distVals.erase(unique(distVals.begin(), distVals.end()), distVals.end());

        int lo = 0, high = distVals.size() - 1, resIdx = 0;
        while (lo <= high){
            int mid = lo + (high - lo) / 2;
            if (cansplit(points, distVals, mid)){
                resIdx = mid;
                lo = mid + 1;
            }
            else high = mid - 1;
        }
        return distVals[resIdx];
    }
};