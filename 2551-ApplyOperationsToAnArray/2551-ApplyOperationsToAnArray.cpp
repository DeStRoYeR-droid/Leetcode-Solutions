// Last updated: 06/07/2026, 18:56:23
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        const int n = nums.size();
        vector<int> result(n, 0);
        int i = 0;
        int index = 0;
        while (i < n){
            if (nums[i] != 0){
                if (i != n - 1 && nums[i] == nums[i + 1]){
                    result[index++] = 2 * nums[i];
                    i++;
                }
                else result[index++] = nums[i];
            }
            i++;
        }
        return result;
    }
};