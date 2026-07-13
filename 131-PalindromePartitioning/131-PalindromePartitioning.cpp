// Last updated: 13/07/2026, 22:26:19
class Solution {
    bool isPalindrome(string s){
        int l = 0, r = s.size() - 1;
        while (l < r){
            if (s[l] != s[r]) return false;
            ++l; --r;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> cur;
        const int n = s.size();
        helper(result, cur, s, 0, n);
        return result;
    }

    void helper(vector<vector<string>>& result, vector<string>& cur, string& s, int idx, const int& size){
        if (idx == size){
            result.push_back(cur);
            return;
        }

        for (int i = idx; i < size; ++i){
            if (isPalindrome(s.substr(idx, i - idx + 1))){
                cur.push_back(s.substr(idx, i - idx + 1));
                helper(result, cur, s, i + 1, size);
                cur.pop_back();
            }
        }
    }
};