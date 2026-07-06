// Last updated: 06/07/2026, 18:55:01
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int k = unordered_set<int>(nums.begin(), nums.end()).size();
        
        unordered_map<int, int> mpp;
        int left = 0;
        int result = 0;

        for (int i = 0; i < nums.size(); ++i){
            mpp[nums[i]]++;
            while (mpp.size() == k){
                result += nums.size() - i;
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) mpp.erase(nums[left]);
                ++left;
            }
        }

        return result;
    }
};