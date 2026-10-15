// Last updated: 15/10/2026, 11:19:54
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int rmL = 0, rmR = 0;
        
        for (char c : s) {
            if (c == '(') {
                rmL++;
            } else if (c == ')') {
                if (rmL > 0) {
                    rmL--;
                } else {
                    rmR++; 
                }
            }
        }

        unordered_set<string> result;
        string cur = "";
        
        // Backtrack with pruning
        backtrack(s, 0, rmL, rmR, 0, cur, result);
        
        return vector<string>(result.begin(), result.end());
    }

private:
    void backtrack(const string& s, int i, int rmL, int rmR, int open, string& cur, unordered_set<string>& result) {
        // Base Case
        if (i == s.size()) {
            if (rmL == 0 && rmR == 0 && open == 0) {
                result.insert(cur);
            }
            return;
        }

        char c = s[i];

        // Branch 1: Try removing the current character
        if (c == '(' && rmL > 0) {
            backtrack(s, i + 1, rmL - 1, rmR, open, cur, result);
        } else if (c == ')' && rmR > 0) {
            backtrack(s, i + 1, rmL, rmR - 1, open, cur, result);
        }

        // Branch 2: Keep the current character
        cur.push_back(c);
        
        if (c == '(') {
            backtrack(s, i + 1, rmL, rmR, open + 1, cur, result);
        } else if (c == ')') {
            if (open > 0) {
                backtrack(s, i + 1, rmL, rmR, open - 1, cur, result);
            }
        } else {
            backtrack(s, i + 1, rmL, rmR, open, cur, result);
        }
        
        cur.pop_back();
    }
};