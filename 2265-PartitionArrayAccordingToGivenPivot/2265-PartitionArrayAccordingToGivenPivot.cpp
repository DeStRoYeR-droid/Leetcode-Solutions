// Last updated: 06/07/2026, 18:58:20
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        const int n = nums.size();
        vector<int> result(n);
        int left = 0, right = n - 1;
        for (int i = 0, j = n - 1; i < nums.size(); ++i, --j){
            if (nums[i] < pivot) result[left++] = nums[i];
            if (nums[j] > pivot) result[right--] = nums[j];
        }

        for (int i = left; i <= right; ++i) result[i] = pivot;
        return result;
    }
};