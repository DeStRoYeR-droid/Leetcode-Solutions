// Last updated: 06/07/2026, 18:48:14
class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        const int n = t1.size();
        vector<pair<int, int>> loss;

        for (int i = 0; i < n; ++i){
            loss.push_back({t1[i] - t2[i], i});
        }

        set<int> indices;
        sort(loss.rbegin(), loss.rend());
        long long result = 0;
        int i = 0;
        while (i < n && (i < k || loss[i].first > 0)){
            result += t1[loss[i].second];
            indices.insert(loss[i].second);
            ++i;
        }
        for (int i = 0; i < n; ++i){
            if (indices.find(i) == indices.end()) result += t2[i];
        }
        return result;
    }
};