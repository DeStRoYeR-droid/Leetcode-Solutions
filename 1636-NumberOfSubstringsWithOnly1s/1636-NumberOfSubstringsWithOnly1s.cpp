// Last updated: 06/07/2026, 19:02:29
const int MOD = 1e9 + 7;
class Solution {
public:
    int numSub(string s) {
        const int n = s.size();
        int result = 0, idx = 0;
        while (idx < n){
            if (s[idx] == '1'){
                int count = 0;
                while (idx < n && s[idx] == '1'){
                    ++idx;
                    ++count;
                }
                result += ((long long)count * (count + 1) / 2) % MOD;
            }
            else ++idx;
        }
        return result;
    }
};