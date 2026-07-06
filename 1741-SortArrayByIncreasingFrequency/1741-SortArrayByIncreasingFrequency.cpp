// Last updated: 06/07/2026, 19:01:53
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> freq;
        for (const auto& val : nums) freq[val]++;
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second)
                return a.first < b.first; 
            return a.second > b.second;  
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (const auto& val : freq){
            pq.push(val);
        }

        vector<int> result;
        while (!pq.empty()){
            auto val = pq.top(); pq.pop();
            for (int i = 0; i < val.second; ++i) result.push_back(val.first);
        }
        return result;
    }
};