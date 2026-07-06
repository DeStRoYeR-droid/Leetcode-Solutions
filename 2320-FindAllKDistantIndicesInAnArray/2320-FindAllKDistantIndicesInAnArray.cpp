// Last updated: 06/07/2026, 18:57:57
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        const int n = nums.size();
        
        vector<bool> resultant(n, false);
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == key)
            for (int j = max(0, i - k); j <= min(n, i + k); ++j){
                resultant[j] = true;
            }
        }
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i){
            if (resultant[i]) result.push_back(i);
        }
        return result;
    }
};