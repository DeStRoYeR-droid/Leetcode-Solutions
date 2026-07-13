// Last updated: 13/07/2026, 22:20:52
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (const int& num : nums) freq[num]++;
        priority_queue<pair<int, int>> pq;
        for (const auto& iter : freq){
            pq.push({iter.second, iter.first});
        }

        vector<int> result;
        for (int i = 0; i < k; ++i){
            auto val = pq.top(); pq.pop();
            result.push_back(val.second);
        }
        return result;
    }
};