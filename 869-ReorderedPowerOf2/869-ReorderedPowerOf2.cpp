// Last updated: 14/09/2026, 09:33:29
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string target = sortedDigits(n);
        for (int i = 0; i < 32; ++i){
            if (sortedDigits(1 << i) == target) return true;
        }
        return false;
    }

    string sortedDigits(int n){
        string s = to_string(n);
        sort(s.begin(), s.end());
        return s;
    }
};