// Last updated: 06/07/2026, 18:47:15
class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        const int n = nums.size();
        vector<int> L(n, 2), R(n, 2);

        for (int i = 2; i < n; ++i){
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]){
                L[i] = L[i - 1] + 1;
            }
        }
        for (int i = n - 3; i >= 0; --i){
            if (nums[i + 1] - nums[i] == nums[i + 2] - nums[i + 1]){
                R[i] = R[i + 1] + 1;
            }
        }

        int result = 0;

        for (int i = 0; i < n; ++i){
            if (i > 0) result = max(result, L[i - 1] + 1);
            if (i < n - 1) result = max(result, R[i + 1] + 1);

            if (i > 0 && i < n - 1){
                int diff = nums[i + 1] - nums[i - 1];
                if (diff % 2 == 0){
                    int d = diff / 2;
                    int bridgeSize = 1;

                    if (i > 1 && (nums[i - 1] - nums[i - 2] == d)){
                        bridgeSize += L[i - 1];
                    }
                    else bridgeSize += 1;

                    if (i < n - 2 && (nums[i + 2] - nums[i + 1] == d)){
                        bridgeSize += R[i + 1];
                    }
                    else bridgeSize += 1;

                    result = max(result, bridgeSize);
                }
            }
        }
        return result;
    }
};