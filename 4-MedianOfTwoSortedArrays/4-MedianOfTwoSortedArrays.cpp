// Last updated: 13/07/2026, 22:30:46
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> combined;
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        int ptr1 = 0;
        int ptr2 = 0;
        while (ptr1 != nums1.size() && ptr2 != nums2.size()){
            if (nums1[ptr1] <= nums2[ptr2]){
                combined.push_back(nums1[ptr1]);
                ptr1++;
            }
            else{
                combined.push_back(nums2[ptr2]);
                ptr2++;
            }
        }

        while (ptr1 != nums1.size()){
            combined.push_back(nums1[ptr1]);
            ptr1++;
        }

        while (ptr2 != nums2.size()){
            combined.push_back(nums2[ptr2]);
            ptr2++;
        }

        bool length_combined = (nums1.size() + nums2.size()) % 2 ? true: false;
        int halfway = (nums1.size() + nums2.size()) / 2;
        if (!length_combined){
            return (combined[halfway - 1] + combined[halfway]) / 2.0;
        }
        return combined[halfway];
    }
};