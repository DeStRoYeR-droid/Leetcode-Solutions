// Last updated: 07/09/2026, 22:50:27
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        vector<long> distances = {
            min_element(nums.begin(), nums.end()) - nums.begin(), 
            max_element(nums.begin(), nums.end()) - nums.begin()
        };
        if (distances[0] > distances[1]) swap(distances[0], distances[1]);
        int n = nums.size();
        vector<long> results = {
            distances[1] + 1,
            n - distances[0],
            distances[0] + 1 + n - distances[1]
        };
        return *min_element(results.begin(), results.end());
    }
};