// Last updated: 06/07/2026, 18:54:23
class Solution {
public:
    long long minSum(const vector<int>& nums1, const vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        bool find1 = find(nums1.begin(), nums1.end(), 0) == nums1.end();
        bool find2 = find(nums2.begin(), nums2.end(), 0) == nums2.end();

        long long total1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        long long total2 = accumulate(nums2.begin(), nums2.end(), 0LL);

        for (const int& val : nums1) if (val == 0) ++total1;
        for (const int& val : nums2) if (val == 0) ++total2;

        int caseNo = find1 + find2;

        switch (caseNo){
            case 2:
                return (total1 == total2) ? total1 : -1;

            case 1:
                if (find1) return (total2 <= total1) ? total1 : -1;
                else return (total1 <= total2) ? total2 : -1;
            
            case 0:
                return max(total1, total2);
        }
        return -1;
    }
};