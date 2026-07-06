// Last updated: 06/07/2026, 18:55:55
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int index1 = 0;
        int index2 = 0;
        while (!(index1 == nums1.size() || index2 == nums2.size())){
            if (nums1[index1] == nums2[index2]) return nums1[index1];
            if (nums1[index1] > nums2[index2]) index2++;
            else index1++;
        }

        return -1;
    }
};