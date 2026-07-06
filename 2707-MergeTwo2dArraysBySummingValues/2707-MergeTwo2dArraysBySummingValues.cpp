// Last updated: 06/07/2026, 18:55:31
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        const int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> result;
        result.reserve(n1 + n2);
        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < n1 && ptr2 < n2){
            if (nums1[ptr1][0] > nums2[ptr2][0]){
                result.push_back(nums2[ptr2]);
                ptr2++;
            }
            else if (nums1[ptr1][0] < nums2[ptr2][0]){
                result.push_back(nums1[ptr1]);
                ptr1++;
            }
            else{
                result.push_back({nums1[ptr1][0], nums1[ptr1][1] + nums2[ptr2][1]});
                ptr1++, ptr2++;
            }
        }

        while (ptr1 < n1) result.push_back(nums1[ptr1++]);
        while (ptr2 < n2) result.push_back(nums2[ptr2++]);
        return result;
    }
};