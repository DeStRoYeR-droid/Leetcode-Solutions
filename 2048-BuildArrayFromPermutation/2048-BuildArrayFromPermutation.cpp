// Last updated: 06/07/2026, 18:59:56
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) 
            nums[i] += 1001 * (nums[nums[i]] % 1001);
        
        for (int i = 0; i < nums.size(); ++i)
            nums[i] /= 1001;
        
        return nums;
    }
};

static const bool __boost = []() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return std::ios_base::sync_with_stdio(false);
}();