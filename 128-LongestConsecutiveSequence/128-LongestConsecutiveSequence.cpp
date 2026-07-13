// Last updated: 13/07/2026, 22:26:24
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        int result = 0;
        for (const int num : numsSet){
            if (numsSet.find(num - 1) == numsSet.end()){
                int cur = num;
                int streak = 1;
                while (numsSet.find(cur + 1) != numsSet.end()){
                    cur++;
                    streak++;
                }

                result = max(result, streak);
            }
        }
        return result;
    }
};