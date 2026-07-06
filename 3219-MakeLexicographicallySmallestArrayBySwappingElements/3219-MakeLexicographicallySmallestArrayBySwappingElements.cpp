// Last updated: 06/07/2026, 18:54:07
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        const int n = nums.size();
        if (n <= 1) return nums;

        vector<pair<int, int>> sortedPairs(n);
        for (int i = 0; i < n; ++i) 
            sortedPairs[i] = {nums[i], i};

        sort(sortedPairs.begin(), sortedPairs.end());

        vector<int> result(n);
        int group = 0;
        for (int i = 0; i < n; ++i){
            if (i == n - 1 || sortedPairs[i+1].first - sortedPairs[i].first > limit){
                vector<int> indices;
                for (int j = group; j <= i; ++j)
                    indices.push_back(sortedPairs[j].second);
                sort(indices.begin(), indices.end());

                for (int j = 0; j < indices.size(); ++j)
                    result[indices[j]] = sortedPairs[group + j].first;
                group = i + 1;
            }
        }
        return result;
    }
};