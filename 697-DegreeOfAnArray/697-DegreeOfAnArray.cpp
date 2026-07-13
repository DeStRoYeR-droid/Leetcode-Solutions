// Last updated: 13/07/2026, 22:17:05
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, tuple<int, int, int>> mp;
        for (int i = 0; i < nums.size(); i++){
            if (mp.find(nums[i]) != mp.end()){
                mp[nums[i]] = {get<0>(mp[nums[i]]) + 1, get<1>(mp[nums[i]]), i};
            }
            else{
                mp[nums[i]] = {1, i, i};
            }
        }
        int maxFreq = 0, result = INT_MAX;
        for (const auto& p : mp){
            if (maxFreq < get<0>(p.second)){
                maxFreq = get<0>(p.second);
                result = (get<2>(p.second) - get<1>(p.second) + 1);
            } 
            else if (maxFreq == get<0>(p.second)){
                result = min(result ,get<2>(p.second) - get<1>(p.second) + 1);
            }
        }
        return result;
    }
};