// Last updated: 06/07/2026, 18:47:57
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        const int n = nums.size();
        unordered_map<int, vector<int>> mapping;
        for (int i = 0; i < nums.size(); ++i){
            mapping[nums[i]].push_back(i);
        }
        int result = -1;
        for (const auto& p : mapping){
            if (p.second.size() >= 3){
                int s = p.second.size();
                for (int i = 0; i < s - 2; ++i){
                    if (result == -1) result = 2 * (p.second[i + 2] - p.second[i]);
                    else result = min(result, 2 * (p.second[i + 2] - p.second[i]));
                }
            }
        }
        return result;
    }
};