// Last updated: 06/07/2026, 18:59:17
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10, right = 1e10;
        while (left < right){
            long long mid = left + (right - left) / 2;
            if (countProducts(nums1, nums2, mid) < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    long long countProducts(vector<int>& nums1, vector<int>& nums2, long long target){
        long long count = 0;
        for (int num : nums1){
            if (num == 0){
                if (target >= 0) count += nums2.size();
                continue;
            }

            int low = 0, high = nums2.size();
            while (low < high){
                int mid = low + (high - low) / 2;
                long long prod = 1LL * num * nums2[mid];
                if (prod <= target){
                    if (num > 0) low = mid + 1;
                    else high = mid;
                }
                else{
                    if (num  > 0) high = mid;
                    else low = mid + 1;
                }
            }

            count += (num > 0) ? low : nums2.size() - low;
        }
        return count;
    }
};