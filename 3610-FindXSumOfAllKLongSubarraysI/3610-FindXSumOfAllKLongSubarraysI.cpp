// Last updated: 06/07/2026, 18:52:13
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        const int n = nums.size();
        vector<int> result(n - k + 1);

        for (int i = 0; i < n - k + 1; ++i){
            result[i] = getTopXFreqSum(nums, i, k, x);
        }
        return result;
    }

    int getTopXFreqSum(const vector<int>& nums, const int& start, const int& k, const int& x){
        unordered_map<int, int> freq;
        for (int i = start; i < start + k; ++i) freq[nums[i]]++;

        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second < b.second) return true;
            else if (a.second > b.second) return false;
            return a.first < b.first;
        };

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            decltype(cmp)
        > pq(freq.begin(), freq.end(), cmp);

        int result = 0, i = 0;
        while (i < x && pq.size()){
            pair<int, int> val = pq.top(); pq.pop();
            result += val.first * val.second;
            ++i;
        }
        return result;
    }
};