// Last updated: 13/07/2026, 22:18:58
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        return mergesort(nums, 0, nums.size() - 1, temp);
    }

    int mergesort(vector<int>& nums, int lo, int hi, vector<int>& temp){
        int count = 0;
        if (lo >= hi) return count;

        int mid = lo + (hi - lo) / 2;
        count += mergesort(nums, lo, mid, temp);
        count += mergesort(nums, mid + 1, hi, temp);
        count += countpairs(nums, lo, mid, hi);
        
        merge(nums, lo, mid, hi, temp);
        
        return count;
    }

    int countpairs(vector<int>& nums, int lo, int mid, int hi){
        int count = 0;
        int j = mid + 1;
        for (int i = lo; i <= mid; ++i){
            while (j <= hi && (long long) nums[i] > 2LL * nums[j]) ++j;
            count += (j - mid - 1);
        }
        return count;
    }

    void merge(vector<int>& nums, int lo, int mid, int hi, vector<int>& temp){
        int i = lo, j = mid + 1;
        int k = lo;

        while (i <= mid && j <= hi){
            if (nums[i] < nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }

        while (i <= mid) temp[k++] = nums[i++];
        while (j <= hi) temp[k++] = nums[j++];

        for (int i = lo; i <= hi; ++i) nums[i] = temp[i];
    }
};