// Last updated: 06/07/2026, 18:55:38
class Solution {
public:
    bool isPossible(int& maxCapacity, const vector<int>& nums, int k){
        const int n = nums.size();

        int i = 0;
        while(i < n) {
            if(nums[i] <= maxCapacity) {
                i += 2;
                k--;
            } else {
                i++;
            }

            if(k == 0) {
                return true;
            }
        }
        return false;
    }

    int minCapability(const vector<int>& nums, const int k) {
        int left = *min_element(nums.begin(), nums.end()), 
            right = *max_element(nums.begin(), nums.end());

        while (left <= right){
            int mid = left + (right - left) / 2;
            if (isPossible(mid, nums, k)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};