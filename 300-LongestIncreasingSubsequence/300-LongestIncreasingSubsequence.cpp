// Last updated: 13/07/2026, 22:21:31
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int length = nums.size();
        int* arr = new int[length];
        for (int i = 0; i < length; i++) arr[i] = 1;

        for (int i = 1; i < length; i++){
            for (int j = 0; j < i; j++){
                if (nums[j] < nums[i]){
                    arr[i] = max(arr[i] , arr[j] + 1);
                }
            }
        }

        int result = 0;
        for (int i = 0; i < length; i++) result = max(result , arr[i]);
        return result;
    }
};