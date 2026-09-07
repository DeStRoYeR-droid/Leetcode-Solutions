// Last updated: 07/09/2026, 22:48:06
class Solution {
public:
    long long appealSum(string s) {
        long long result = 0;
        long long cur = 0;
        long long prev[26] = {};

        for (int i = 0; i < s.size(); ++i){
            cur += i + 1 - prev[s[i] - 'a'];
            prev[s[i] - 'a'] = i + 1;
            result += cur;
        }
        return result;
    }
};