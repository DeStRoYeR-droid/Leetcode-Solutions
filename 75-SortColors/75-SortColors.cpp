// Last updated: 13/07/2026, 22:28:25
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0};
        for (const int& val : nums){
            count[val]++;
        }
        int iter = 0;
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < count[i]; ++j){
                nums[iter] = i;
                ++iter;
            }
        }
    }
};