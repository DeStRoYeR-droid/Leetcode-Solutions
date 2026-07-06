// Last updated: 06/07/2026, 19:08:31
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        backtrack(s, 0, result, "");
        return result;
    }

    void backtrack(string s, int i, vector<string>& result, string cur){
        if (i == s.size()){
            result.push_back(cur);
            return;
        }
        if (s[i] >= 'a' && s[i] <= 'z'){
            char upper = s[i] + 'A' - 'a';
            backtrack(s, i + 1, result, cur + upper);
        }
        if (s[i] >= 'A' && s[i] <= 'Z'){
            char lower = s[i] + 'a' - 'A';
            backtrack(s, i + 1, result, cur + lower);
        }
        backtrack(s, i + 1, result, cur + s[i]);
    }
};