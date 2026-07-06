// Last updated: 06/07/2026, 18:48:03
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        unordered_set<int> numbers(nums.begin(), nums.end());
        vector<int> result;
        for (int i = mini; i < maxi; ++i){
            if (numbers.find(i) == numbers.end()) result.push_back(i);
        }
        return result;
    }
};