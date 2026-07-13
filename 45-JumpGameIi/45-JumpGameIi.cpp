// Last updated: 13/07/2026, 22:29:25
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        int target = len - 1;
        vector<int> jumps(len, INT_MAX - 1);
        jumps[target] = 0;

        for (int i = nums.size() - 2; i > -1; i--){
            int cur = nums[i];
            int k = i + 1;
            while (k <= min(cur + i, target)){
                jumps[i] = min(jumps[i], 1 + jumps[k]);
                k++;
            }
        }
        return jumps[0];
    }
    
};