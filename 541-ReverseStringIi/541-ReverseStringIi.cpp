// Last updated: 13/07/2026, 22:18:33
class Solution {
public:
    string reverseStr(string s, int k) {
        bool flip = true;
        for (int i = 0; i < s.size(); i += k){
            if (flip) reverse(s.begin() + i, min(s.end(), s.begin() + i + k));
            flip = !flip;
        }
        return s;
    }
};