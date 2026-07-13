// Last updated: 13/07/2026, 22:27:54
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result(n + m);
        int i = 0, j = 0;
        int index = 0;
        while (i < m && j < n){
            if (nums1[i] > nums2[j]) result[index++] = nums2[j++];
            else result[index++] = nums1[i++];
        }

        while (i < m) result[index++] = nums1[i++];
        while (j < n) result[index++] = nums2[j++];
        nums1 = result;
    }
};