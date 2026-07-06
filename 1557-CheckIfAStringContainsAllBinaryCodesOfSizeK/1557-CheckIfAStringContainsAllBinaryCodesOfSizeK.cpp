// Last updated: 06/07/2026, 19:03:07
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        vector<bool> mp(1 << k, false);

        int num = 0;
        for (int i = 0; i < k && i < s.size(); ++i){
            num = num << 1 | (s[i] - '0');
        }
        mp[num] = true;
        for (int r = k; r < s.size(); ++r){
            num = num << 1;
            num %= 1 << k;
            num |= s[r] - '0';

            mp[num] = true;
        }

        for (const bool& val : mp){
            if (!val) return false;
        }
        return true;
    }
};