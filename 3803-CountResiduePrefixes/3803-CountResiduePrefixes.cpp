// Last updated: 07/09/2026, 22:23:15
class Solution {
public:
    int residuePrefixes(string s) {
        int state = 0;
        int result = 0;
        for (int i = 0; i < s.size(); ++i){
            state =  state | (1 << (s[i] - 'a'));
            if (__builtin_popcount(state) == (i + 1) % 3) result += 1;
        }
        return result;
    }
};