// Last updated: 07/09/2026, 22:36:23
class Solution {
public:
    bool doesAliceWin(string s) {
        return any_of(s.begin(), s.end(), [](const char& c){return ((0x104111>>(c-'a')) & 1);});
    }
};