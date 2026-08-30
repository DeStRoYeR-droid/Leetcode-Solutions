// Last updated: 30/08/2026, 15:12:44
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); ++i){
            mp[nums[i]].push_back(i);
        }
        int result = 0;
        for (const auto& [val, vec]: mp){
            bool flag = true;
            for (int i = 0; i < vec.size() - 1; ++i){
                if (vec[i] != vec[i + 1] - 1){
                    flag = false;
                    break;
                }
            }
            result += flag;
        }
        return result;
    }
};