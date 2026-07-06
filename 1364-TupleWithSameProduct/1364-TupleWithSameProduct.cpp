// Last updated: 06/07/2026, 19:04:46
class Solution {
public:
    int tupleSameProduct(const vector<int>& nums) {
        unordered_map<int, int> products;
        const int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                products[nums[i] * nums[j]]++;
        
        for (const auto& pair : products){
            if (pair.second > 1) result += pair.second * (pair.second - 1) * 4;
        }
        
        return result;
    }
};