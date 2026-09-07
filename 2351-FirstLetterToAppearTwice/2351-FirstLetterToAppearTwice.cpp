// Last updated: 07/09/2026, 22:46:40
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