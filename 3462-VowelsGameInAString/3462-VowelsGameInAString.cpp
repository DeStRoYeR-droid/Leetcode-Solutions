// Last updated: 06/07/2026, 18:52:48
class Solution {
public:
    bool doesAliceWin(string s) {
        return any_of(s.begin(), s.end(), [](const char& c){return ((0x104111>>(c-'a')) & 1);});
    }
};