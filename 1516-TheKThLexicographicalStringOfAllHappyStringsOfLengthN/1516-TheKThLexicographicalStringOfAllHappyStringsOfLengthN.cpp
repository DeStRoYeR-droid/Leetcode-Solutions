// Last updated: 06/07/2026, 19:03:25
class Solution {
public:
    void backtrack(int n, int k, vector<char>& chars, string& s, vector<string>& ans) {
        if (ans.size() >= k) return;

        if (s.size() == n) {
            ans.push_back(s);
            return;
        }

        for (char c : chars) {
            if (s.length() == 0) {
                s = s + c;
                backtrack(n, k, chars, s, ans);
                s.erase(s.begin() + s.size()-1);
            } else if (c != s.back()) {
                s = s + c;
                backtrack(n, k, chars, s, ans);
                s.erase(s.begin() + s.size()-1);
            }
        }
        
    }

    string getHappyString(int n, int k) {
        vector<string> ans;
        vector<char> chars = {'a', 'b', 'c'};
        string s = "";

        backtrack(n, k, chars, s, ans);

        if (ans.size() < k) {
            return "";
        } else {
            return ans.at(k-1);
        }
    }
};