// Last updated: 06/07/2026, 18:53:19
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        const int n = nums.size();
        int increasing = 0;
        int decreasing = 0;
        int cur = INT_MIN;
        int index = 0;
        int res = 0;
        while (index < n){
            if (nums[index] > cur){
                res++;
            }
            else{
                increasing = max(res, increasing);
                res = 1;
            }
            cur = nums[index++];
        }
        increasing = max(res, increasing);

        cur = INT_MAX;
        res = 0;
        index = 0;
        while (index < n){
            if (nums[index] < cur){
                res++;
            }
            else{
                decreasing = max(res, decreasing);
                res = 1;
            }
            cur = nums[index++];
        }
        decreasing = max(res, decreasing);

        cout << increasing << " " << decreasing << endl;

        return max(increasing, decreasing);
    }
};