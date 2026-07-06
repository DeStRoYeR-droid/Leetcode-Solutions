// Last updated: 06/07/2026, 19:07:03
class Solution {
public:
    int minAddToMakeValid(string s) {
        int unmatchedOpen = 0, unmatchedClose = 0;
        for (char& ch : s){
            if (ch == '(') unmatchedOpen++;
            else if (unmatchedOpen) unmatchedOpen--;
            else unmatchedClose++;
        }
        return unmatchedOpen + unmatchedClose;
    }
};