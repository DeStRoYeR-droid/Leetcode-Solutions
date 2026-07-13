// Last updated: 13/07/2026, 22:18:46
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        const int n = score.size();
        vector<string> result(n, "");
        
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; ++i){
            pq.push({score[i], i});
        }

        pair<int, int> p = pq.top(); pq.pop();
        result[p.second] = "Gold Medal";

        if (n == 1) return result;

        p = pq.top(); pq.pop();
        result[p.second] = "Silver Medal";
        
        if (n == 2) return result;

        p = pq.top(); pq.pop();
        result[p.second] = "Bronze Medal";

        if (n == 3) return result;

        int position = 4;
        while (!pq.empty()){
            p = pq.top(); pq.pop();
            result[p.second] = to_string(position);
            ++position;
        }

        return result;
    }
};