// Last updated: 31/10/2026, 19:59:55
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> result;
        int count = 0, lesser = 0;
        for (const int& val : nums){
            if (val < target) ++lesser;
            else if (val == target) ++count;
        }
        result.reserve(count);
        for (int i = 0; i < count; ++i){
            result.push_back(lesser + i);
        }
        return result;
    }
};