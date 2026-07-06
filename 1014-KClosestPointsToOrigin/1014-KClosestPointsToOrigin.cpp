// Last updated: 06/07/2026, 19:06:37
class Solution {
public:
    vector<vector<int>> kClosest(const vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        priority_queue<pair<int, vector<int>>> pq;
        
        for (const auto& p : points){
            int dist = p[0] * p[0] + p[1] * p[1];
            pq.emplace(make_pair(-dist, p));
        }

        while (!pq.empty() && k > 0){
            auto p = pq.top(); pq.pop();
            result.push_back(p.second);
            --k;
        }
        return result;
    }
};