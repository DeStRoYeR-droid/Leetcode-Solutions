// Last updated: 06/07/2026, 18:48:00
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        const int n = nums.size();
        int result = -1;
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                if (nums[i] == nums[j]){
                    for (int k = j + 1; k < n; ++k){
                        if (nums[k] == nums[j]){
                            if (result == -1){
                                result = abs(k - j) + abs(j - i) + abs(k - i);
                            }
                            else result = min(result, abs(k - j) + abs(j - i) + abs(k - i));
                        }
                    }
                }
            }
        }
        return result;
    }
};