// Last updated: 06/07/2026, 18:47:16
class Solution {
public:
    string trimTrailingVowels(string s) {
        static const int vowelState = 1065233;
        int i = s.size() - 1;
        while (i >= 0){
            if ((1 << (s[i] - 'a')) & vowelState) --i;
            else break;
        }

        if (i < 0) return "";
        return s.substr(0, i + 1);
    }
};