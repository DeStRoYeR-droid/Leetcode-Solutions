// Last updated: 06/07/2026, 18:57:48
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