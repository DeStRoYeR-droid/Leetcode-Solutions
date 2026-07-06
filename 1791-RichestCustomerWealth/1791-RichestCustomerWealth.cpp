// Last updated: 06/07/2026, 19:01:37
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int result = 0;
        for (const auto& account : accounts)    
            result = max(result, accumulate(account.begin(), account.end(), 0));
        return result;
    }
};