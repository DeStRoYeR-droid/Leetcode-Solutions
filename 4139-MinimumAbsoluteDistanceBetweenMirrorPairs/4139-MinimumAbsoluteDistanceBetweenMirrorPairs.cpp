// Last updated: 06/07/2026, 18:47:49
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int result = INT_MAX;
        for (int i = 0; i < nums.size(); i++){
            if (mp.find(nums[i]) != mp.end()){
                result = min(result, i - mp[nums[i]]);
            }
            mp[reverse(nums[i])] = i;
        }
        return (result == INT_MAX) ? -1 : result;
    }

    int reverse(int num){
        int result = 0;
        while (num){
            result = result * 10 + num % 10;
            num = num / 10;
        }
        return result;
    }
};