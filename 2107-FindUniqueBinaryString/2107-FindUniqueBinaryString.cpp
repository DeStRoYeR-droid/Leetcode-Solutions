// Last updated: 06/07/2026, 18:59:33
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        const int n = nums[0].size();
        string result = "";

        for (int i = 0; i < n; ++i){
            result += (nums[i][i] == '0') ? '1' : '0';
        }

        return result;
    }
};