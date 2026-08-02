// Last updated: 02/08/2026, 14:42:25
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int result = 0;
        int diff = INT_MAX;

        for (int i = 0; i < n-2; ++i){
            int low = i + 1;
            int high = n - 1;
            while (low < high){
                int temp = nums[i] + nums[low] + nums[high];
                
                if (abs(target - temp) < diff){
                    result = temp;
                    diff = abs(target - temp);
                }
                
                if (temp == target) return target;
                else if (temp > target) high --;
                else low++;
            }
        }
        return result;
    }
};