// Last updated: 13/07/2026, 22:22:45
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        const int n = nums.size();
        vector<string> result;
        
        if (n == 0) return result;

        int i = 0;
        while (i < n){
            int j = i;
            int a = nums[i], b = nums[j];
            while (j + 1 < n && nums[j] + 1 == nums[j+1]){
                j++;
                b = nums[j];
            }

            if (a == b) result.push_back(to_string(a));
            else result.push_back(to_string(a) + "->" + to_string(b));
            i = j + 1;
        }

        return result;
    }
};