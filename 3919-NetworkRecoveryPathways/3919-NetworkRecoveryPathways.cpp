// Last updated: 06/07/2026, 18:49:56
class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int hi = 0;
        for (auto& e : edges){
            adj[e[0]].push_back({e[1], e[2]}); // Source - [next, cost]
            hi = max(hi, e[2]);
        }
        
        int lo = 0;
        int result = -1;
        while (lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if (canReach(mid, adj, online, k, n)){
                result = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return result;
    }

    bool canReach(int minCost, const vector<vector<pair<int, int>>>& adj, const vector<bool>& online, const long long& k, const int& n){
        if (!online[0] || !online[n - 1]) return false;
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; 
        vector<long long> min_cost(n, LLONG_MAX);
        
        pq.push({0LL, 0});
        min_cost[0] = 0;

        while (!pq.empty()){
            auto [c, e] = pq.top(); pq.pop();

            if (e == n - 1) return true;

            if (c > min_cost[e]) continue;

            for (const auto [next, costTo]: adj[e]){
                if (!online[next]) continue;
                else if (costTo < minCost) continue;
                
                long long nextCost = c + costTo;
                
                if (nextCost <= k && nextCost < min_cost[next]){
                    min_cost[next] = nextCost;
                    pq.push({nextCost, next});
                }
            }
        }
        return false;
    }
};