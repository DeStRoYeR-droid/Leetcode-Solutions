// Last updated: 06/07/2026, 18:57:11
class Solution {
public:
    char repeatedCharacter(const string& s) {
        int state = 0;
        for (const char& ch : s){
            if ((1 << (ch - 'a')) & state) return ch;
            state = state | (1 << (ch - 'a'));
        }
        return ' ';
    }
};