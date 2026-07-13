// Last updated: 13/07/2026, 22:29:31
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int length = nums.size();
        for (int i = 0; i < length; i++){
            while (nums[i] > 0 && nums[i] <= length && 
                   nums[nums[i] - 1] != nums[i]){
                swap(nums[i] , nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < length; i++){
            if (nums[i] != i+1){
                return i+1;
            }
        }
        return length + 1;
    }
};