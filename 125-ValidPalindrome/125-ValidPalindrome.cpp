// Last updated: 13/07/2026, 22:26:32
class Solution {
public:
    bool isPalindrome(string s) {
        string filter = "";
        for (char& ch : s){
            if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z')) filter += ch;
            if (ch >= 'A' && ch <= 'Z') filter += ch + 32;
        }
        int left = 0;
        int right = filter.length() - 1;
        while (left < right){
            if (filter[left] == filter[right]){
                left++;
                right--;
            }
            else break;
        }

        return left >= right;
    }
};