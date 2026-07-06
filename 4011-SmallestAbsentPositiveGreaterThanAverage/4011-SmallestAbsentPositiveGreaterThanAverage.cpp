// Last updated: 06/07/2026, 18:49:01
class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        float average = (float) total / nums.size();
        int start = max(1, (int)average + 1);
        for (int i = start; i <= 101; ++i){
            if (find(nums.begin(), nums.end(), i) == nums.end()) return i;
        }
        return -1;
    }
};