// Last updated: 14/09/2026, 09:18:43
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int result = 0;
        for (const auto& account : accounts)    
            result = max(result, accumulate(account.begin(), account.end(), 0));
        return result;
    }
};