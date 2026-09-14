// Last updated: 14/09/2026, 09:31:57
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