// Last updated: 24/08/2026, 22:50:00
class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i){
            result += expand(s, i, i);
            result += expand(s, i, i + 1);
        }
        return result;
    }

    int expand(const string& s, int left, int right){
        int result = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]){
            ++result;
            --left;
            ++right;
        }
        return result;
    }
};