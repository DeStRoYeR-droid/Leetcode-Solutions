// Last updated: 06/07/2026, 19:07:06
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right){
            while (left < s.size() && !isalpha(s[left])) ++left;
            while (right >= 0 && !isalpha(s[right])) --right;
            if (left < right){
                swap(s[left], s[right]);
                ++left;
                --right;
            }
        }
        return s;
    }
};